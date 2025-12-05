#pragma once
#include <algorithm>
#include <vector>
#include <array>

template<typename RandomAccessIterator>
void InsertionSort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (end - begin < 2) return;
    for (auto it = begin + 1; it != end; ++it) {
        auto key = *it; 
        auto j = it - 1;   
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template<typename T>
void InsertionSort(std::vector<T>& vec) {
    InsertionSort(vec.begin(), vec.end());
}

template<typename T, size_t N>
void InsertionSort(T (&arr)[N]) {
    InsertionSort(arr, arr + N);
}

template<typename T, size_t N>
void InsertionSort(std::array<T, N>& arr) {
    InsertionSort(arr.begin(), arr.end());
}
