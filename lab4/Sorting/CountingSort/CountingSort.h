#pragma once
#include <algorithm>
#include <vector>
#include <array>
#include <iterator>
#include <type_traits>
#include "Product.h"

template<typename RandomAccessIterator>
void CountingSort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (end - begin < 2) return;
    
    using ValueType = typename std::iterator_traits<RandomAccessIterator>::value_type;
    
    // Используем if constexpr (C++17) для разделения логики
    // Это позволяет иметь одну функцию (требование убрать enable_if из заголовка)
    // и корректно обрабатывать Product
    if constexpr (std::is_same_v<ValueType, Product>) {
        auto [min_it, max_it] = std::minmax_element(begin, end);
        double min_val = min_it->getValue();
        double max_val = max_it->getValue();
        
        if (min_val == max_val) return;
        
        size_t range = static_cast<size_t>(max_val - min_val + 1);
        std::vector<size_t> count(range, 0);
        
        for (auto it = begin; it != end; ++it) {
            count[static_cast<size_t>(it->getValue() - min_val)]++;
        }
        
        for (size_t i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }
        
        std::vector<Product> temp(std::distance(begin, end));
        
        for (auto it = end - 1; it >= begin; --it) {
            size_t index = static_cast<size_t>(it->getValue() - min_val);
            temp[count[index] - 1] = *it;
            count[index]--;
        }
        std::copy(temp.begin(), temp.end(), begin);

    } else {
        // Логика для арифметических типов
        auto [min_it, max_it] = std::minmax_element(begin, end);
        ValueType min_val = *min_it;
        ValueType max_val = *max_it;
        
        if (min_val == max_val) return;
        
        size_t range = max_val - min_val + 1;
        std::vector<size_t> count(range, 0);
        
        for (auto it = begin; it != end; ++it) {
            count[*it - min_val]++;
        }
        
        for (size_t i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }
        
        std::vector<ValueType> temp(std::distance(begin, end));
        
        for (auto it = end - 1; it >= begin; --it) {
            size_t index = *it - min_val;
            temp[count[index] - 1] = *it;
            count[index]--;
        }
        std::copy(temp.begin(), temp.end(), begin);
    }
}

template<typename T>
void CountingSort(std::vector<T>& vec) {
    CountingSort(vec.begin(), vec.end());
}

template<typename T, size_t N>
void CountingSort(T (&arr)[N]) {
    CountingSort(arr, arr + N);
}

template<typename T, size_t N>
void CountingSort(std::array<T, N>& arr) {
    CountingSort(arr.begin(), arr.end());
}
