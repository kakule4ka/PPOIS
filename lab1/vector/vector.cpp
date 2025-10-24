#include "vector.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>

vector::vector() : x_(0), y_(0), z_(0) {}

vector::vector(double x_beg, double y_beg, double z_beg, double x_end, double y_end, double z_end)
    : x_(x_end - x_beg), y_(y_end - y_beg), z_(z_end - z_beg) {}

vector::vector(double x, double y, double z) : x_(x), y_(y), z_(z) {}

vector::vector(std::initializer_list<double> list) {
    if (list.size() != 3) {
        throw std::invalid_argument("Initializer list must have exactly 3 elements");
    }
    auto it = list.begin();
    x_ = *it++;
    y_ = *it++;
    z_ = *it;
}

vector& vector::operator=(std::initializer_list<double> list) {
    if (list.size() != 3) {
        throw std::invalid_argument("Initializer list must have exactly 3 elements");
    }
    auto it = list.begin();
    x_ = *it++;
    y_ = *it++;
    z_ = *it;
    return *this;
}

void vector::swap(vector& other) noexcept {
    std::swap(x_, other.x_);
    std::swap(y_, other.y_);
    std::swap(z_, other.z_);
}

double vector::size() const {
    return std::sqrt(x_*x_ + y_*y_ + z_*z_);
}

vector vector::operator+(const vector& vec) const {
    return vector{x_ + vec.x_, y_ + vec.y_, z_ + vec.z_};
}

vector vector::operator-(const vector& vec) const {
    return vector{x_ - vec.x_, y_ - vec.y_, z_ - vec.z_};
}

vector& vector::operator+=(const vector& vec) {
    x_ += vec.x_;
    y_ += vec.y_;
    z_ += vec.z_;
    return *this;
}

vector& vector::operator-=(const vector& vec) {
    x_ -= vec.x_;
    y_ -= vec.y_;
    z_ -= vec.z_;
    return *this;
}

vector vector::operator*(double value) const {
    return vector{x_ * value, y_ * value, z_ * value};
}

vector operator*(double value, const vector& vec) {
    return vec * value;
}

vector& vector::operator*=(double value) {
    x_ *= value;
    y_ *= value;
    z_ *= value;
    return *this;
}

double vector::operator*(const vector& vec) const {
    return x_*vec.x_ + y_*vec.y_ + z_*vec.z_;
}

vector vector::operator%(const vector& vec) const {
    return vector{y_*vec.z_ - z_*vec.y_, z_*vec.x_ - x_*vec.z_, x_*vec.y_ - y_*vec.x_};
}

vector& vector::operator%=(const vector& vec) {
    *this = *this % vec;
    return *this;
}

vector vector::operator/(double value) const {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return vector{x_ / value, y_ / value, z_ / value};
}

vector& vector::operator/=(double value) {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    x_ /= value;
    y_ /= value;
    z_ /= value;
    return *this;
}

vector vector::operator/(const vector& vec) const {
    if (vec.x_ == 0 || vec.y_ == 0 || vec.z_ == 0) {
        throw std::invalid_argument("Division by zero vector component");
    }
    return vector{x_/vec.x_, y_/vec.y_, z_/vec.z_};
}

vector& vector::operator/=(const vector& vec) {
    if (vec.x_ == 0 || vec.y_ == 0 || vec.z_ == 0) {
        throw std::invalid_argument("Division by zero vector component");
    }
    x_ /= vec.x_;
    y_ /= vec.y_;
    z_ /= vec.z_;
    return *this;
}

double vector::operator^(const vector& vec) const {
    double s1 = size();
    double s2 = vec.size();
    if (s1 == 0 || s2 == 0) {
        throw std::invalid_argument("Zero vector has no direction");
    }
    return (*this * vec) / (s1 * s2);
}

bool vector::operator==(const vector& vec) const {
    const double epsilon = 1e-10;
    return std::abs(x_ - vec.x_) < epsilon &&
           std::abs(y_ - vec.y_) < epsilon &&
           std::abs(z_ - vec.z_) < epsilon;
}

bool vector::operator!=(const vector& vec) const {
    return !(*this == vec);
}

bool vector::operator>(const vector& vec) const {
    return size() > vec.size();
}

bool vector::operator>=(const vector& vec) const {
    return size() >= vec.size();
}

bool vector::operator<(const vector& vec) const {
    return size() < vec.size();
}

bool vector::operator<=(const vector& vec) const {
    return size() <= vec.size();
}

std::ostream& operator<<(std::ostream& os, const vector& vec) {
    os << "{" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << "}";
    return os;
}

std::istream& operator>>(std::istream& is, vector& vec) {
    char ch;
    if (!(is >> ch) || ch != '{') {
        is.setstate(std::ios::failbit);
        return is;
    }

    double x, y, z;
    char comma1, comma2;

    if (!(is >> x >> comma1 >> y >> comma2 >> z) || 
        comma1 != ',' || comma2 != ',') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> ch) || ch != '}') {
        is.setstate(std::ios::failbit);
        return is;
    }

    vec.x_ = x;
    vec.y_ = y;
    vec.z_ = z;
    return is;
}
