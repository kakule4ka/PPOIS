#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <algorithm>
#include "CountingSort.h"
#include "Product.h"

TEST(CountingSortTest, IntegersVector) {
    std::vector<int> vec = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::vector<int> expected = vec;
    std::sort(expected.begin(), expected.end());
    
    CountingSorter::Sort(vec); // Вызов через статический метод класса
    
    EXPECT_EQ(vec, expected);
}

TEST(CountingSortTest, NegativeIntegers) {
    std::vector<int> vec = {-3, -1, -2, -5, -4, 0, 2, -1};
    std::vector<int> expected = vec;
    std::sort(expected.begin(), expected.end());
    
    CountingSorter::Sort(vec);
    
    EXPECT_EQ(vec, expected);
}

TEST(CountingSortTest, CArray) {
    int arr[] = {5, 2, 8, 1};
    int expected[] = {1, 2, 5, 8};
    
    CountingSorter::Sort(arr);
    
    for(size_t i=0; i<4; ++i) EXPECT_EQ(arr[i], expected[i]);
}

TEST(CountingSortTest, StdArray) {
    std::array<int, 4> arr = {5, 2, 8, 1};
    std::array<int, 4> expected = {1, 2, 5, 8};
    
    CountingSorter::Sort(arr);
    
    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTest, EmptyVector) {
    std::vector<int> vec;
    CountingSorter::Sort(vec);
    EXPECT_TRUE(vec.empty());
}

TEST(CountingSortTest, CustomClassProduct) {
    std::vector<Product> products = {
        Product(100), Product(50), Product(150), Product(10)
    };
    
    CountingSorter::Sort(products);
    
    EXPECT_EQ(products[0].getValue(), 10);
    EXPECT_EQ(products[1].getValue(), 50);
    EXPECT_EQ(products[2].getValue(), 100);
    EXPECT_EQ(products[3].getValue(), 150);
}

TEST(CountingSortTest, IteratorRange) {
    std::vector<int> vec = {10, 5, 2, 8, 10};
    // Сортируем только середину {5, 2, 8} -> {2, 5, 8}
    CountingSorter::Sort(vec.begin() + 1, vec.end() - 1);
    
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 5);
    EXPECT_EQ(vec[3], 8);
    EXPECT_EQ(vec[4], 10);
}
