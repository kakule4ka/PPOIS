#pragma once
#include <algorithm>
#include <vector>
#include <array>

class InsertionSorter {
public:
    template<typename RandomAccessIterator>
    static void Sort(RandomAccessIterator begin, RandomAccessIterator end) {
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
    static void Sort(std::vector<T>& vec) {
        Sort(vec.begin(), vec.end());
    }

    template<typename T, size_t N>
    static void Sort(T (&arr)[N]) {
        Sort(arr, arr + N);
    }

    template<typename T, size_t N>
    static void Sort(std::array<T, N>& arr) {
        Sort(arr.begin(), arr.end());
    }
};
