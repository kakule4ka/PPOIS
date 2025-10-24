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
    // Конструкторы
    BigInt();
    BigInt(int32_t value);
    BigInt(const BigInt& other);
    BigInt(const std::string& str);

    //Унарные операторы
    BigInt operator+() const;
    BigInt operator-() const;

    // Оператор присваивания
    BigInt& operator=(const BigInt& other);

    // Операторы преобразования
    explicit operator long long() const;
    explicit operator int() const;

    // Арифметические операторы с BigInt
    BigInt operator+ (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);
    BigInt operator- (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);

    // Арифметические операторы с int
    BigInt operator+ (const int& value) const;
    BigInt& operator+= (const int& value);
    friend BigInt operator+ (int lhs, const BigInt& rhs);
    BigInt operator- (const int& value) const;
    BigInt& operator-= (const int& value);
    friend BigInt operator- (int lhs, const BigInt& rhs);

    // Инкремент и декремент
    BigInt& operator++();
    BigInt operator++(int);
    BigInt& operator--();
    BigInt operator--(int);

    // Операторы сравнения с BigInt
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    // Операторы сравнения с int
    friend bool operator>(int value, const BigInt& big);
    friend bool operator>=(int value, const BigInt& big);
    friend bool operator<(int value, const BigInt& big);
    friend bool operator<=(int value, const BigInt& big);
    friend bool operator==(int value, const BigInt& big);
    friend bool operator!=(int value, const BigInt& big);

    // Методы умножения
    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);
    friend BigInt operator*(const BigInt& a, int b);
    friend BigInt operator*(int a, const BigInt& b);
    BigInt& operator*=(int value);

    // Методы деления
    BigInt operator/(const BigInt& other) const;
    BigInt& operator/=(const BigInt& other);
    friend BigInt operator/(const BigInt& a, int b);
    friend BigInt operator/(int a, const BigInt& b);
    BigInt& operator/=(int value);

    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
    friend std::istream& operator>>(std::istream& is, BigInt& num);

private:
    std::vector<uint32_t> number;
    bool is_positive;
    static const uint32_t base;

    // Вспомогательные методы
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
