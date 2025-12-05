#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <algorithm>
#include "InsertionSort.h"
#include "Student.h"

TEST(InsertionSortTest, IntegersVector) {
    std::vector<int> vec = {9, 1, 5, 3};
    InsertionSort(vec);
    std::vector<int> expected = {1, 3, 5, 9};
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, DoublesVector) {
    std::vector<double> vec = {2.5, 1.1, 3.8};
    InsertionSort(vec);
    EXPECT_DOUBLE_EQ(vec[0], 1.1);
    EXPECT_DOUBLE_EQ(vec[1], 2.5);
    EXPECT_DOUBLE_EQ(vec[2], 3.8);
}

TEST(InsertionSortTest, CArray) {
    int arr[] = {3, 1, 2};
    InsertionSort(arr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(InsertionSortTest, StdArray) {
    std::array<int, 3> arr = {3, 1, 2};
    std::array<int, 3> expected = {1, 2, 3};
    InsertionSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTest, CustomClassStudent) {
    // Проверка сортировки пользовательского класса
    std::vector<Student> students = {
        Student(85), Student(40), Student(95), Student(60)
    };
    
    InsertionSort(students);
    
    // Проверяем упорядоченность через оператор сравнения
    EXPECT_TRUE(students[0] <= students[1]);
    EXPECT_TRUE(students[1] <= students[2]);
    EXPECT_TRUE(students[2] <= students[3]);
}

TEST(InsertionSortTest, IteratorRange) {
    // Сортировка поддиапазона
    std::vector<int> vec = {5, 4, 3, 2, 1};
    // Сортируем элементы с индексами 1 по 3 (значения 4, 3, 2 -> 2, 3, 4)
    // begin() + 1 указывает на 4
    // end() - 1 указывает на 1 (последний элемент, не включается в диапазон сортировки)
    // Диапазон: [4, 3, 2]
    InsertionSort(vec.begin() + 1, vec.end() - 1);
    
    EXPECT_EQ(vec[0], 5); // 5 не тронуто
    EXPECT_EQ(vec[1], 2); // 2 встало на место
    EXPECT_EQ(vec[2], 3); // 3
    EXPECT_EQ(vec[3], 4); // 4
    EXPECT_EQ(vec[4], 1); // 1 не тронуто
}
