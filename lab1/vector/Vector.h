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

    vector operator+(const vector& vec) const;
    vector operator-(const vector& vec) const;
    vector& operator+=(const vector& vec);
    vector& operator-=(const vector& vec);

    vector operator*(double value) const;
    friend vector operator*(double value, const vector& vec);
    vector& operator*=(double value);

    vector operator/(double value) const;
    vector& operator/=(double value);

    double operator*(const vector& vec) const;
    vector operator%(const vector& vec) const;
    vector& operator%=(const vector& vec);

    vector operator/(const vector& vec) const;
    vector& operator/=(const vector& vec);

    double operator^(const vector& vec) const;

    bool operator==(const vector& vec) const;
    bool operator!=(const vector& vec) const;
    bool operator>(const vector& vec) const;
    bool operator>=(const vector& vec) const;
    bool operator<(const vector& vec) const;
    bool operator<=(const vector& vec) const;

    friend std::ostream& operator<<(std::ostream& os, const vector& vec);
    friend std::istream& operator>>(std::istream& is, vector& vec);
};
