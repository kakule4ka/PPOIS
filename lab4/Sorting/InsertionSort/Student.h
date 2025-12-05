#pragma once
#include <iostream>

class Student {
public:
    Student(int grade = 0) : grade_(grade) {}
    
    // Операторы сравнения необходимы для сортировки
    bool operator<(const Student& other) const { return grade_ < other.grade_; }
    bool operator>(const Student& other) const { return grade_ > other.grade_; }
    bool operator<=(const Student& other) const { return grade_ <= other.grade_; }
    bool operator>=(const Student& other) const { return grade_ >= other.grade_; }
    bool operator==(const Student& other) const { return grade_ == other.grade_; }
    bool operator!=(const Student& other) const { return grade_ != other.grade_; }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        return os << "Student(" << student.grade_ << ")";
    }

private:
    int grade_;
};
