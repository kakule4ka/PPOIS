#pragma once
#include <iostream>

class Product {
public:
    Product(double price = 0.0) : price_(price) {}
    
    // Операторы сравнения
    bool operator<(const Product& other) const { return price_ < other.price_; }
    bool operator>(const Product& other) const { return price_ > other.price_; }
    bool operator<=(const Product& other) const { return price_ <= other.price_; }
    bool operator>=(const Product& other) const { return price_ >= other.price_; }
    bool operator==(const Product& other) const { return price_ == other.price_; }
    bool operator!=(const Product& other) const { return price_ != other.price_; }

    double getValue() const { return price_; }

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        return os << "Product($" << product.price_ << ")";
    }

private:
    double price_;
};
