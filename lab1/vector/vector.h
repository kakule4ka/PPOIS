#pragma once
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <initializer_list>

class vector {
private:
    double x_, y_, z_;

public:
    vector();
    vector(double x_beg, double y_beg, double z_beg, double x_end, double y_end, double z_end);
    vector(double x, double y, double z);
    vector(const vector& other) = default;
    vector(std::initializer_list<double> list);
    
    void swap(vector& other) noexcept;
    double size() const;
    
    vector& operator=(const vector& other) = default;
    vector& operator=(std::initializer_list<double> list);
    
    // Арифметические операторы
    vector operator+(const vector& vec) const;
    vector operator-(const vector& vec) const;
    vector& operator+=(const vector& vec);
    vector& operator-=(const vector& vec);
    
    // Умножение и деление на скаляр
    vector operator*(double value) const;
    vector& operator*=(double value);
    vector operator/(double value) const;
    vector& operator/=(double value);
    
    // Скалярное и векторное произведения
    double operator*(const vector& vec) const;
    vector operator%(const vector& vec) const;
    vector& operator%=(const vector& vec);
    
    // Поэлементное деление
    vector operator/(const vector& vec) const;
    vector& operator/=(const vector& vec);
    
    // Косинус угла между векторами
    double operator^(const vector& vec) const;
    
    // Операторы сравнения
    bool operator==(const vector& vec) const;
    bool operator!=(const vector& vec) const;
    bool operator>(const vector& vec) const;
    bool operator>=(const vector& vec) const;
    bool operator<(const vector& vec) const;
    bool operator<=(const vector& vec) const;

    // Операторы ввода-вывода
    friend std::ostream& operator<<(std::ostream& os, const vector& vec);
    friend std::istream& operator>>(std::istream& is, vector& vec);
};