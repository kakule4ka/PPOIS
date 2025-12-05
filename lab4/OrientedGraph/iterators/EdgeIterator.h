#pragma once
#include <iterator>
#include <utility>

namespace GraphImpl {
    template <typename GraphType>
    class EdgeIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<typename GraphType::ValueType, typename GraphType::ValueType>;
        using difference_type = std::ptrdiff_t;
        using pointer = const value_type*;
        using reference = const value_type&;
        
        using MapIterType = typename GraphType::AdjacencyMap::const_iterator;
        using SetIterType = typename GraphType::NeighborSet::const_iterator;

    private:
        MapIterType MapIter;
        MapIterType MapBegin;
        MapIterType MapEnd;
        SetIterType SetIter;

        void AdvanceToValid() {
            while (MapIter != MapEnd && SetIter == MapIter->second.end()) {
                ++MapIter;
                if (MapIter != MapEnd) SetIter = MapIter->second.begin();
            }
        }

        void RetreatToValid() {
            while (MapIter == MapEnd || SetIter == MapIter->second.begin()) {
                if (MapIter == MapBegin) return; 
                --MapIter;
                SetIter = MapIter->second.end();
            }
            --SetIter;
        }

    public:
        EdgeIterator(MapIterType Start, MapIterType End, MapIterType RealBegin) 
            : MapIter(Start), MapBegin(RealBegin), MapEnd(End) {
            if (MapIter != MapEnd) {
                SetIter = MapIter->second.begin();
                AdvanceToValid();
            }
        }

        value_type operator*() const {
            return {MapIter->first, *SetIter};
        }

        EdgeIterator& operator++() {
            ++SetIter;
            AdvanceToValid();
            return *this;
        }
        
        EdgeIterator operator++(int) {
            auto Tmp = *this;
            ++(*this);
            return Tmp;
        }

        EdgeIterator& operator--() {
            RetreatToValid();
            return *this;
        }
        
        EdgeIterator operator--(int) {
            auto Tmp = *this;
            --(*this);
            return Tmp;
        }

        bool operator==(const EdgeIterator& Other) const {
            if (MapIter == MapEnd && Other.MapIter == Other.MapEnd) return true;
            return MapIter == Other.MapIter && SetIter == Other.SetIter;
        }
        bool operator!=(const EdgeIterator& Other) const { return !(*this == Other); }
    };
}
