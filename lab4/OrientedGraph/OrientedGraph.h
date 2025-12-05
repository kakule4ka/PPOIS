#pragma once

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <utility>

#include "iterators/VertexIterator.h"
#include "iterators/EdgeIterator.h"
#include "iterators/AdjacentIterator.h"
#include "iterators/IncidentIterator.h"

template <typename T>
struct GraphTraits {
    using KeyType = T;
    using Compare = std::less<T>;
};

template <typename T, typename Traits = GraphTraits<T>>
class OrientedGraph {
public:
    using ValueType = T;
    using Reference = T&;
    using ConstReference = const T&;
    using SizeType = size_t;
    using EdgeType = std::pair<T, T>;

    using NeighborSet = std::set<T, typename Traits::Compare>;
    using AdjacencyMap = std::map<T, NeighborSet, typename Traits::Compare>;

private:
    AdjacencyMap AdjList;

public:
    using VertexIterator = GraphImpl::VertexIterator<OrientedGraph<T, Traits>>;
    using ConstVertexIterator = VertexIterator;
    using ReverseVertexIterator = std::reverse_iterator<VertexIterator>;
    
    using EdgeIterator = GraphImpl::EdgeIterator<OrientedGraph<T, Traits>>;
    
    using AdjacentIterator = GraphImpl::AdjacentIterator<OrientedGraph<T, Traits>>;
    using ConstAdjacentIterator = AdjacentIterator;
    using ReverseAdjacentIterator = std::reverse_iterator<AdjacentIterator>;

    using IncidentIterator = GraphImpl::IncidentIterator<OrientedGraph<T, Traits>>;
    using ReverseIncidentIterator = std::reverse_iterator<IncidentIterator>;

    OrientedGraph() = default;
    OrientedGraph(const OrientedGraph& Other) : AdjList(Other.AdjList) {}
    ~OrientedGraph() { Clear(); }
    
    OrientedGraph& operator=(const OrientedGraph& Other) {
        if (this != &Other) AdjList = Other.AdjList;
        return *this;
    }

    bool IsEmpty() const { return AdjList.empty(); }
    void Clear() { AdjList.clear(); }

    bool operator==(const OrientedGraph& Other) const { return AdjList == Other.AdjList; }
    bool operator!=(const OrientedGraph& Other) const { return !(*this == Other); }
    bool operator<(const OrientedGraph& Other) const { return AdjList < Other.AdjList; }
    bool operator>(const OrientedGraph& Other) const { return AdjList > Other.AdjList; }
    bool operator<=(const OrientedGraph& Other) const { return AdjList <= Other.AdjList; }
    bool operator>=(const OrientedGraph& Other) const { return AdjList >= Other.AdjList; }

    bool ContainsVertex(const T& Vertex) const {
        return AdjList.find(Vertex) != AdjList.end();
    }

    bool ContainsEdge(const T& From, const T& To) const {
        auto It = AdjList.find(From);
        if (It == AdjList.end()) return false;
        return It->second.find(To) != It->second.end();
    }

    SizeType GetVertexCount() const { return AdjList.size(); }

    SizeType GetEdgeCount() const {
        SizeType Count = 0;
        for (const auto& Node : AdjList) Count += Node.second.size();
        return Count;
    }

    SizeType GetVertexDegree(const T& Vertex) const {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        SizeType Degree = AdjList.at(Vertex).size();
        for (const auto& Node : AdjList) {
            if (Node.second.count(Vertex)) Degree++;
        }
        return Degree;
    }

    SizeType GetEdgeDegree(const T& From, const T& To) const {
        if (!ContainsEdge(From, To)) throw std::invalid_argument("Edge not found");
        return GetVertexDegree(From) + GetVertexDegree(To);
    }

    void AddVertex(const T& Vertex) {
        if (!ContainsVertex(Vertex)) AdjList[Vertex];
    }

    void AddEdge(const T& From, const T& To) {
        AddVertex(From);
        AddVertex(To);
        AdjList[From].insert(To);
    }

    void RemoveVertex(const T& Vertex) {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        for (auto& Node : AdjList) {
            Node.second.erase(Vertex);
        }
        AdjList.erase(Vertex);
    }

    void RemoveEdge(const T& From, const T& To) {
        if (!ContainsVertex(From)) throw std::invalid_argument("Source vertex not found");
        auto& Neighbors = AdjList[From];
        if (Neighbors.find(To) == Neighbors.end()) throw std::invalid_argument("Edge not found");
        Neighbors.erase(To);
    }

    VertexIterator BeginVertex() const { return VertexIterator(AdjList.begin()); }
    VertexIterator EndVertex() const { return VertexIterator(AdjList.end()); }
    ReverseVertexIterator RBeginVertex() const { return ReverseVertexIterator(EndVertex()); }
    ReverseVertexIterator REndVertex() const { return ReverseVertexIterator(BeginVertex()); }

    EdgeIterator BeginEdge() const { return EdgeIterator(AdjList.begin(), AdjList.end()); }
    EdgeIterator EndEdge() const { return EdgeIterator(AdjList.end(), AdjList.end()); }

    AdjacentIterator BeginAdjacent(const T& Vertex) const {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        return AdjacentIterator(AdjList.at(Vertex).begin());
    }
    AdjacentIterator EndAdjacent(const T& Vertex) const {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        return AdjacentIterator(AdjList.at(Vertex).end());
    }
    
    IncidentIterator BeginIncident(const T& Vertex) const {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        return IncidentIterator(Vertex, AdjList.at(Vertex).begin());
    }
    IncidentIterator EndIncident(const T& Vertex) const {
        if (!ContainsVertex(Vertex)) throw std::invalid_argument("Vertex not found");
        return IncidentIterator(Vertex, AdjList.at(Vertex).end());
    }

    void RemoveVertex(VertexIterator It) {
        if (It != EndVertex()) RemoveVertex(*It);
    }
    
    void RemoveEdge(EdgeIterator It) {
        if (It != EndEdge()) {
            EdgeType E = *It;
            RemoveEdge(E.first, E.second);
        }
    }

    friend std::ostream& operator<<(std::ostream& Os, const OrientedGraph& G) {
        std::for_each(G.BeginVertex(), G.EndVertex(), [&](const T& V) {
            Os << V << ":";
            std::for_each(G.BeginAdjacent(V), G.EndAdjacent(V), [&](const T& Neighbor) {
                Os << " " << Neighbor;
            });
            Os << "\n";
        });
        return Os;
    }
};
