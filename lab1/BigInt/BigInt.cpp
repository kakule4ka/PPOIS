#include "BigInt.h"

const uint32_t BigInt::base = 1000000000u;

BigInt::BigInt(): is_positive(true), number{0} {}

BigInt::BigInt(int32_t value) {
    number.clear();
    if (value == 0) {
        is_positive = true;
        number.push_back(0);
        return;
    }
    if (value < 0) {
        is_positive = false;
        int64_t tmp = -(int64_t)value;
        number.push_back(static_cast<uint32_t>(tmp));
    } else {
        is_positive = true;
        number.push_back(static_cast<uint32_t>(value));
    }
}

BigInt::BigInt(const BigInt& other) : number(other.number), is_positive(other.is_positive) {}

BigInt::BigInt(const std::string& str) {
    if (str.empty()) throw std::invalid_argument("Empty string");
    if (!NumberValidationCheck(str)) {
        throw std::invalid_argument("Invalid number. Please enter only digits and a sign in the beginning: " + str);
    }

    size_t pos = 0;
    if (str[0] == '+' || str[0] == '-') {
        is_positive = (str[0] != '-');
        pos = 1;
    } else {
        is_positive = true;
    }

    while (pos + 1 < str.size() && str[pos] == '0') ++pos;

    number.clear();
    for (int i = static_cast<int>(str.size()); i > static_cast<int>(pos); i -= 9) {
        int left = std::max(static_cast<int>(pos), i - 9);
        int len = i - left;
        uint32_t chunk = static_cast<uint32_t>(std::stoul(str.substr(left, len)));
        number.push_back(chunk);
    }

    removeLeadingZeros();
}

BigInt::operator long long() const {
    long long result = 0;
    long long multiplier = 1;

    for (size_t i = 0; i < number.size(); ++i) {
        if (multiplier == 0 || multiplier > LLONG_MAX / static_cast<long long>(base)) {
            break;
        }

        long long term = static_cast<long long>(number[i]) * multiplier;

        if (term > 0 && result > LLONG_MAX - term) {
            break;
        }

        result += term;
        multiplier *= static_cast<long long>(base);
    }

    return is_positive ? result : -result;
}

BigInt::operator int() const {
    return static_cast<int>(static_cast<long long>(*this));
}

BigInt BigInt::operator+ (const BigInt& other) const {
    BigInt result;
    if (is_positive && other.is_positive) {
        result = PositiveSum(*this, other);
        result.is_positive = true;
    } else if (is_positive && !other.is_positive) {
        result = Subtract(*this, other);
    } else if (!is_positive && other.is_positive) {
        result = Subtract(other, *this);
    } else {
        result = PositiveSum(*this, other);
        result.is_positive = false;
    }
    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator+= (const BigInt& other) {
    *this = *this + other;
    return *this;
}

BigInt BigInt::operator- (const BigInt& other) const {
    BigInt result;
    if (is_positive && other.is_positive) result = Subtract(*this, other);
    else if (is_positive && !other.is_positive) {
        result = PositiveSum(*this, other);
        result.is_positive = true;
    } else if (!is_positive && other.is_positive) {
        result = PositiveSum(*this, other);
        result.is_positive = false;
    } else result = Subtract(other, *this);
    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator-= (const BigInt& other) {
    *this = *this - other;
    return *this;
}

BigInt BigInt::operator+ (const int& value) const {
    BigInt result(*this);
    if (result.number.empty()) result.number.push_back(0);
    if (value >= 0) {
        uint32_t add = static_cast<uint32_t>(value);
        size_t i = 0;
        uint64_t carry = add;
        while (carry) {
            if (i >= result.number.size()) result.number.push_back(0);
            uint64_t sum = uint64_t(result.number[i]) + carry;
            result.number[i] = static_cast<uint32_t>(sum % base);
            carry = sum / base;
            ++i;
        }
    } else {
        int32_t v = -value;
        return *this - v;
    }
    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator+= (const int& value) {
    *this = *this + value;
    return *this;
}

BigInt operator+ (int lhs, const BigInt& rhs) {
    return rhs + lhs;
}

BigInt BigInt::operator- (const int& value) const {
    BigInt result(*this);
    if (result.number.empty()) result.number.push_back(0);

    if (value >= 0) {
        int64_t cur = static_cast<int64_t>(result.number[0]) - static_cast<int64_t>(value);
        bool borrow = false;
        if (cur < 0) {
            cur += base;
            borrow = true;
        }
        result.number[0] = static_cast<uint32_t>(cur);
        size_t i = 1;
        while (borrow && i < result.number.size()) {
            if (result.number[i] == 0) {
                result.number[i] = base - 1;
                ++i;
            } else {
                result.number[i]--;
                borrow = false;
            }
        }
        if (borrow) {
            BigInt tmp;
            tmp.number.clear();
            tmp.number.push_back(static_cast<uint32_t>(value));
            tmp.is_positive = true;
            result = Subtract(tmp, *this);
        }
    } else {
        return *this + (-value);
    }

    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator-= (const int& value) {
    *this = *this - value;
    return *this;
}

BigInt operator- (int lhs, const BigInt& rhs) {
    BigInt tmp(lhs);
    return tmp - rhs;
}

int& BigInt::operator+=(int& a, const BigInt& b) {
    a = static_cast<int>(BigInt(a) + b);
    return a;
}

int& BigInt::operator-=(int& a, const BigInt& b) {
    a = static_cast<int>(BigInt(a) - b);
    return a;
}

BigInt& BigInt::operator++() {
    *this += 1;
    return *this;
}

BigInt& BigInt::operator--() {
    *this -= 1;
    return *this;
}

bool BigInt::operator==(const BigInt& other) const {
    return is_positive == other.is_positive && number == other.number;
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const {
    if (is_positive != other.is_positive) return !is_positive;
    if (number.size() != other.number.size()) {
        bool res = number.size() < other.number.size();
        return is_positive ? res : !res;
    }
    for (int i = static_cast<int>(number.size()) - 1; i >= 0; --i) {
        if (number[i] != other.number[i]) {
            bool res = number[i] < other.number[i];
            return is_positive ? res : !res;
        }
    }
    return false;
}

bool BigInt::operator>(const BigInt& other) const {
    return other < *this;
}

bool BigInt::operator<=(const BigInt& other) const {
    return !(*this > other);
}

bool BigInt::operator>=(const BigInt& other) const {
    return !(*this < other);
}

bool operator>(int value, const BigInt& big) {
    return BigInt(value) > big;
}

bool operator>=(int value, const BigInt& big) {
    return BigInt(value) >= big;
}

bool operator<(int value, const BigInt& big) {
    return BigInt(value) < big;
}

bool operator<=(int value, const BigInt& big) {
    return BigInt(value) <= big;
}

bool operator==(int value, const BigInt& big) {
    return BigInt(value) == big;
}

bool operator!=(int value, const BigInt& big) {
    return BigInt(value) != big;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt zero(0);
    if (*this == zero || other == zero) {
        return BigInt(0);
    }

    BigInt result;
    result.is_positive = (is_positive == other.is_positive);
    result.number.assign(number.size() + other.number.size(), 0u);

    for (size_t i = 0; i < number.size(); ++i) {
        uint64_t carry = 0;
        for (size_t j = 0; j < other.number.size() || carry; ++j) {
            uint64_t cur = result.number[i + j] + carry;
            if (j < other.number.size()) cur += uint64_t(number[i]) * other.number[j];
            result.number[i + j] = static_cast<uint32_t>(cur % base);
            carry = cur / base;
        }
    }

    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator*=(const BigInt& other) {
    *this = *this * other;
    return *this;
}

BigInt operator*(const BigInt& a, int b) {
    BigInt result;
    result.is_positive = (a.is_positive == (b >= 0));
    uint32_t abs_b = static_cast<uint32_t>(b >= 0 ? b : -static_cast<int64_t>(b));

    uint64_t carry = 0;
    result.number.assign(a.number.size() + 1, 0u);
    for (size_t i = 0; i < a.number.size() || carry; ++i) {
        if (i == result.number.size()) result.number.push_back(0);
        uint64_t cur = carry;
        if (i < a.number.size()) cur += uint64_t(a.number[i]) * abs_b;
        result.number[i] = static_cast<uint32_t>(cur % BigInt::base);
        carry = cur / BigInt::base;
    }

    result.removeLeadingZeros();
    return result;
}

BigInt operator*(int a, const BigInt& b) {
    return b * a;
}

int& BigInt::operator*=(int& a, const BigInt& b) {
    a = static_cast<int>(BigInt(a) * b);
    return a;
}

BigInt& BigInt::operator*=(int value) {
    *this = *this * BigInt(value);
    return *this;
}

BigInt BigInt::operator/(const BigInt& other) const {
    if (other == BigInt(0)) {
        throw std::invalid_argument("Division by zero");
    }

    BigInt a = this->abs();
    BigInt b = other.abs();
    BigInt result;
    BigInt current;
    result.is_positive = (is_positive == other.is_positive);

    result.number.assign(number.size(), 0u);

    for (int i = static_cast<int>(number.size()) - 1; i >= 0; --i) {
        current.number.insert(current.number.begin(), 0u);
        current.number[0] = number[i];
        current.removeLeadingZeros();

        uint32_t left = 0, right = BigInt::base - 1, quotient = 0;
        while (left <= right) {
            uint32_t mid = left + (right - left) / 2u;
            BigInt prod = b * static_cast<int>(mid);
            if (prod <= current) {
                quotient = mid;
                left = mid + 1;
            } else {
                if (mid == 0) break;
                right = mid - 1;
            }
        }

        result.number[i] = quotient;
        if (quotient != 0) {
            current = current - b * static_cast<int>(quotient);
        }
    }

    result.removeLeadingZeros();
    return result;
}

BigInt& BigInt::operator/=(const BigInt& other) {
    *this = *this / other;
    return *this;
}

BigInt operator/(const BigInt& a, int b) {
    return a / BigInt(b);
}

BigInt operator/(int a, const BigInt& b) {
    return BigInt(a) / b;
}

int& BigInt::operator/=(int& a, const BigInt& b) {
    a = static_cast<int>(BigInt(a) / b);
    return a;
}

BigInt& BigInt::operator/=(int value) {
    *this = *this / BigInt(value);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    if (num.number.empty() || (num.number.size() == 1 && num.number[0] == 0)) {
        os << "0";
        return os;
    }

    if (!num.is_positive) os << "-";

    os << num.number.back();
    for (int i = static_cast<int>(num.number.size()) - 2; i >= 0; --i) {
        os << std::setw(9) << std::setfill('0') << num.number[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, BigInt& num) {
    std::string str;
    is >> str;
    if (!is) return is;
    try {
        num = BigInt(str);
    } catch (const std::exception&) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

bool BigInt::IsDigit(const char& ch) {
    return (ch >= '0' && ch <= '9');
}

bool BigInt::NumberValidationCheck(const std::string& str) {
    if (str.empty()) return false;
    size_t pos = 0;
    if (str[0] == '+' || str[0] == '-') pos = 1;
    if (pos >= str.size()) return false;
    for (size_t i = pos; i < str.size(); ++i) {
        if (!IsDigit(str[i])) return false;
    }
    return true;
}

const std::vector<uint32_t>& BigInt::GetLargerVector(const BigInt& a, const BigInt& b) {
    return (a.number.size() >= b.number.size()) ? a.number : b.number;
}

const std::vector<uint32_t>& BigInt::GetSmallerVector(const BigInt& a, const BigInt& b) {
    return (a.number.size() < b.number.size()) ? a.number : b.number;
}

void BigInt::removeLeadingZeros() {
    while (!number.empty() && number.size() > 1 && number.back() == 0) number.pop_back();
    if (number.empty()) {
        number.push_back(0);
        is_positive = true;
    }
    if (number.size() == 1 && number[0] == 0) is_positive = true;
}

BigInt BigInt::abs() const {
    BigInt r = *this;
    r.is_positive = true;
    return r;
}

BigInt BigInt::PositiveSum(const BigInt& vec1, const BigInt& vec2) {
    size_t n1 = vec1.number.size();
    size_t n2 = vec2.number.size();
    size_t n = std::max(n1, n2);
    BigInt result;
    result.number.assign(n, 0u);

    uint64_t carry = 0;
    for (size_t i = 0; i < n; ++i) {
        uint64_t a = (i < n1) ? vec1.number[i] : 0;
        uint64_t b = (i < n2) ? vec2.number[i] : 0;
        uint64_t sum = a + b + carry;
        result.number[i] = static_cast<uint32_t>(sum % base);
        carry = sum / base;
    }
    if (carry) result.number.push_back(static_cast<uint32_t>(carry));
    result.removeLeadingZeros();
    return result;
}

bool BigInt::AbsLess(const BigInt& x, const BigInt& y) {
    if (x.number.size() != y.number.size()) return x.number.size() < y.number.size();
    for (int i = static_cast<int>(x.number.size()) - 1; i >= 0; --i)
        if (x.number[i] != y.number[i]) return x.number[i] < y.number[i];
    return false;
}

BigInt BigInt::PositiveDiffStrict(const BigInt& larger, const BigInt& smaller) {
    BigInt result;
    size_t largeSize = larger.number.size();
    size_t smallSize = smaller.number.size();
    result.number.assign(largeSize, 0u);

    bool borrow = false;
    for (size_t i = 0; i < largeSize; ++i) {
        int64_t cur = static_cast<int64_t>(larger.number[i]) - (borrow ? 1 : 0);
        if (i < smallSize) cur -= static_cast<int64_t>(smaller.number[i]);
        if (cur < 0) {
            cur += static_cast<int64_t>(base);
            borrow = true;
        } else borrow = false;
        result.number[i] = static_cast<uint32_t>(cur);
    }

    result.removeLeadingZeros();
    return result;
}

BigInt BigInt::Subtract(const BigInt& a, const BigInt& b) {
    if (AbsLess(a, b)) {
        BigInt r = PositiveDiffStrict(b, a);
        r.is_positive = r.number.size() == 1 && r.number[0] == 0 ? true : false;
        if (!(r.number.size() == 1 && r.number[0] == 0)) r.is_positive = false;
        return r;
    } else {
        BigInt r = PositiveDiffStrict(a, b);
        r.is_positive = true;
        if (r.number.size() == 1 && r.number[0] == 0) r.is_positive = true;
        return r;
    }
}
