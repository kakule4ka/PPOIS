#pragma once
#include <iterator>
#include <utility>

namespace GraphImpl {

    template <typename GraphType>
    class IncidentIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<typename GraphType::ValueType, typename GraphType::ValueType>;
        using difference_type = std::ptrdiff_t;
        
        using SetIterType = typename GraphType::NeighborSet::const_iterator;
        using VertexType = typename GraphType::ValueType;

    private:
        VertexType Source;
        SetIterType Current;

    public:
        IncidentIterator(VertexType Src, SetIterType Start) : Source(Src), Current(Start) {}

        value_type operator*() const {
            return {Source, *Current};
        }

        IncidentIterator& operator++() { ++Current; return *this; }
        IncidentIterator& operator--() { --Current; return *this; }

        bool operator==(const IncidentIterator& Other) const { return Current == Other.Current; }
        bool operator!=(const IncidentIterator& Other) const { return Current != Other.Current; }
    };

}
