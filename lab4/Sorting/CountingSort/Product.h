#pragma once
#include <iostream>

class Product {
public:
    Product(double price = 0.0) : price_(price) {}
    
    // Геттер нужен для сортировки подсчетом (нужно числовое значение)
    double getValue() const { return price_; }

    bool operator==(const Product& other) const { return price_ == other.price_; }
    bool operator!=(const Product& other) const { return price_ != other.price_; }

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        return os << "Product($" << product.price_ << ")";
    }

private:
    double price_;
};
