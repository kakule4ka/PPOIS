#pragma once
#include <iterator>
#include <map>

namespace GraphImpl {

    template <typename GraphType>
    class VertexIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = typename GraphType::ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = const value_type*;
        using reference = const value_type&;
        using MapIterType = typename GraphType::AdjacencyMap::const_iterator;

    private:
        MapIterType Current;

    public:
        VertexIterator() = default;
        explicit VertexIterator(MapIterType Start) : Current(Start) {}

        reference operator*() const { return Current->first; }
        pointer operator->() const { return &Current->first; }

        VertexIterator& operator++() { ++Current; return *this; }
        VertexIterator operator++(int) { auto Tmp = *this; ++Current; return Tmp; }
        VertexIterator& operator--() { --Current; return *this; }
        VertexIterator operator--(int) { auto Tmp = *this; --Current; return Tmp; }

        bool operator==(const VertexIterator& Other) const { return Current == Other.Current; }
        bool operator!=(const VertexIterator& Other) const { return Current != Other.Current; }
    };

}
