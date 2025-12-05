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
    CountingSort(vec);
    EXPECT_EQ(vec, expected);
}

TEST(CountingSortTest, NegativeIntegers) {
    std::vector<int> vec = {-3, -1, -2, -5, -4, 0, 2, -1};
    std::vector<int> expected = vec;
    std::sort(expected.begin(), expected.end());
    CountingSort(vec);
    EXPECT_EQ(vec, expected);
}

TEST(CountingSortTest, CArray) {
    int arr[] = {5, 2, 8, 1};
    int expected[] = {1, 2, 5, 8};
    CountingSort(arr);
    for(size_t i=0; i<4; ++i) EXPECT_EQ(arr[i], expected[i]);
}

TEST(CountingSortTest, StdArray) {
    std::array<int, 4> arr = {5, 2, 8, 1};
    std::array<int, 4> expected = {1, 2, 5, 8};
    CountingSort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(CountingSortTest, EmptyVector) {
    std::vector<int> vec;
    CountingSort(vec);
    EXPECT_TRUE(vec.empty());
}

TEST(CountingSortTest, CustomClassProduct) {
    std::vector<Product> products = {
        Product(100), Product(50), Product(150), Product(10)
    };
    
    CountingSort(products);
    
    EXPECT_EQ(products[0].getValue(), 10);
    EXPECT_EQ(products[1].getValue(), 50);
    EXPECT_EQ(products[2].getValue(), 100);
    EXPECT_EQ(products[3].getValue(), 150);
}

TEST(CountingSortTest, ProductDuplicates) {
    std::vector<Product> products = {
        Product(10), Product(20), Product(10)
    };
    CountingSort(products);
    EXPECT_EQ(products[0].getValue(), 10);
    EXPECT_EQ(products[1].getValue(), 10);
    EXPECT_EQ(products[2].getValue(), 20);
}
