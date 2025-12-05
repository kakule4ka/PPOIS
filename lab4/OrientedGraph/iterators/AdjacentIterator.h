#pragma once
#include <iterator>

namespace GraphImpl {

    template <typename GraphType>
    class AdjacentIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = typename GraphType::ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = const value_type*;
        using reference = const value_type&;
        using SetIterType = typename GraphType::NeighborSet::const_iterator;

    private:
        SetIterType Current;

    public:
        AdjacentIterator(SetIterType Start) : Current(Start) {}

        reference operator*() const { return *Current; }
        pointer operator->() const { return &(*Current); }

        AdjacentIterator& operator++() { ++Current; return *this; }
        AdjacentIterator operator++(int) { auto Tmp = *this; ++Current; return Tmp; }
        AdjacentIterator& operator--() { --Current; return *this; }
        AdjacentIterator operator--(int) { auto Tmp = *this; --Current; return Tmp; }

        bool operator==(const AdjacentIterator& Other) const { return Current == Other.Current; }
        bool operator!=(const AdjacentIterator& Other) const { return Current != Other.Current; }
    };

}
