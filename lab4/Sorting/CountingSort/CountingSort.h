#pragma once
#include <algorithm>
#include <vector>
#include <array>
#include <iterator>
#include <type_traits>
#include "Product.h"

class CountingSorter {
public:
    template<typename RandomAccessIterator>
    static void Sort(RandomAccessIterator begin, RandomAccessIterator end) {
        if (end - begin < 2) return;

        using ValueType = typename std::iterator_traits<RandomAccessIterator>::value_type;
        if constexpr (std::is_same_v<ValueType, Product>) {
            auto extractor = [](const Product& p) { return p.getValue(); };
            SortInternal(begin, end, extractor);
        } else {
            auto extractor = [](const ValueType& v) { return v; };
            SortInternal(begin, end, extractor);
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

private:
    
    template<typename Iterator, typename ValueExtractor>
    static void SortInternal(Iterator begin, Iterator end, ValueExtractor extractor) {
        auto [min_val, max_val] = FindRange(begin, end, extractor);
        
        if (min_val == max_val) return;

        auto count = CountFrequencies(begin, end, min_val, max_val, extractor);

        CalculatePrefixSums(count);

        BuildOutput(begin, end, count, min_val, extractor);
    }

    template<typename Iterator, typename ValueExtractor>
    static std::pair<double, double> FindRange(Iterator begin, Iterator end, ValueExtractor extractor) {
        double min_val = extractor(*begin);
        double max_val = min_val;

        for (auto it = begin; it != end; ++it) {
            double val = extractor(*it);
            if (val < min_val) min_val = val;
            if (val > max_val) max_val = val;
        }
        return {min_val, max_val};
    }

    template<typename Iterator, typename ValueExtractor>
    static std::vector<size_t> CountFrequencies(Iterator begin, Iterator end, double min_val, double max_val, ValueExtractor extractor) {
        size_t range = static_cast<size_t>(max_val - min_val + 1);
        std::vector<size_t> count(range, 0);

        for (auto it = begin; it != end; ++it) {
            size_t idx = static_cast<size_t>(extractor(*it) - min_val);
            count[idx]++;
        }
        return count;
    }

    static void CalculatePrefixSums(std::vector<size_t>& count) {
        for (size_t i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }
    }

    template<typename Iterator, typename ValueExtractor>
    static void BuildOutput(Iterator begin, Iterator end, std::vector<size_t>& count, double min_val, ValueExtractor extractor) {
        using ValueType = typename std::iterator_traits<Iterator>::value_type;
        std::vector<ValueType> output(std::distance(begin, end));

        for (auto it = end - 1; it >= begin; --it) {
            size_t idx = static_cast<size_t>(extractor(*it) - min_val);
            output[count[idx] - 1] = *it;
            count[idx]--;
        }

        std::copy(output.begin(), output.end(), begin);
    }
};
