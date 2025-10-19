#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <climits>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

class BigInt {
public:
    BigInt();
    BigInt(int32_t value);
    BigInt(const BigInt& other);
    BigInt(const std::string& str);

    explicit operator long long() const;
    explicit operator int() const;

    BigInt operator+ (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);

    BigInt operator- (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);

    BigInt operator+ (const int& value) const;
    BigInt& operator+= (const int& value);
    friend BigInt operator+ (int lhs, const BigInt& rhs);

    BigInt operator- (const int& value) const;
    BigInt& operator-= (const int& value);
    friend BigInt operator- (int lhs, const BigInt& rhs);

    int& operator+=(int& a, const BigInt& b);
    int& operator-=(int& a, const BigInt& b);

    BigInt& operator++();
    BigInt& operator--();

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    friend bool operator>(int value, const BigInt& big);
    friend bool operator>=(int value, const BigInt& big);
    friend bool operator<(int value, const BigInt& big);
    friend bool operator<=(int value, const BigInt& big);
    friend bool operator==(int value, const BigInt& big);
    friend bool operator!=(int value, const BigInt& big);

    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);

    friend BigInt operator*(const BigInt& a, int b);
    friend BigInt operator*(int a, const BigInt& b);
    int& operator*=(int& a, const BigInt& b);
    BigInt& operator*=(int value);

    BigInt operator/(const BigInt& other) const;
    BigInt& operator/=(const BigInt& other);

    friend BigInt operator/(const BigInt& a, int b);
    friend BigInt operator/(int a, const BigInt& b);
    int& operator/=(int& a, const BigInt& b);
    BigInt& operator/=(int value);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
    friend std::istream& operator>>(std::istream& is, BigInt& num);

private:
    std::vector<uint32_t> number;
    bool is_positive;
    static const uint32_t base;

    static bool IsDigit(const char& ch);
    static bool NumberValidationCheck(const std::string& str);

    static const std::vector<uint32_t>& GetLargerVector(const BigInt& a, const BigInt& b);
    static const std::vector<uint32_t>& GetSmallerVector(const BigInt& a, const BigInt& b);

    void removeLeadingZeros();
    BigInt abs() const;

    static BigInt PositiveSum(const BigInt& vec1, const BigInt& vec2);
    static bool AbsLess(const BigInt& x, const BigInt& y);
    static BigInt PositiveDiffStrict(const BigInt& larger, const BigInt& smaller);
    static BigInt Subtract(const BigInt& a, const BigInt& b);
};
ЫЫ
