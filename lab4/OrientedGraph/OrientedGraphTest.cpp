#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "OrientedGraph.h"

class OrientedGraphTest : public ::testing::Test {
protected:
    OrientedGraph<int> Graph;

    void SetUp() override {
        Graph.Clear();
    }
};

TEST_F(OrientedGraphTest, BasicOperationsAndCoverage) {
    EXPECT_TRUE(Graph.IsEmpty());
    Graph.AddVertex(1);
    EXPECT_FALSE(Graph.IsEmpty());
    Graph.AddVertex(1); 
    EXPECT_EQ(Graph.GetVertexCount(), 1);

    Graph.AddEdge(1, 2);
    EXPECT_EQ(Graph.GetVertexCount(), 2);
    EXPECT_TRUE(Graph.ContainsEdge(1, 2));
    EXPECT_FALSE(Graph.ContainsEdge(2, 1));
    
    OrientedGraph<int> GraphCopy(Graph);
    EXPECT_EQ(GraphCopy.GetVertexCount(), 2);
    
    OrientedGraph<int> GraphAssign;
    GraphAssign = Graph;
    EXPECT_EQ(GraphAssign.GetVertexCount(), 2);
    GraphAssign = GraphAssign; 

    Graph.Clear();
    EXPECT_EQ(Graph.GetVertexCount(), 0);
}

TEST_F(OrientedGraphTest, LogicAndDegrees) {
    Graph.AddEdge(1, 2); 
    Graph.AddEdge(2, 3);
    Graph.AddEdge(1, 3);

    EXPECT_EQ(Graph.GetVertexDegree(1), 2); 
    EXPECT_EQ(Graph.GetVertexDegree(2), 2); 
    EXPECT_EQ(Graph.GetVertexDegree(3), 2); 

    EXPECT_EQ(Graph.GetEdgeDegree(1, 2), 4);
}

TEST_F(OrientedGraphTest, RemovalLogic) {
    Graph.AddEdge(1, 2);
    Graph.AddEdge(2, 3);
    Graph.AddEdge(3, 1);

    Graph.RemoveEdge(1, 2);
    EXPECT_FALSE(Graph.ContainsEdge(1, 2));
    EXPECT_EQ(Graph.GetEdgeCount(), 2);

    Graph.RemoveVertex(2);
    EXPECT_FALSE(Graph.ContainsVertex(2));
    EXPECT_FALSE(Graph.ContainsEdge(2, 3));
    EXPECT_TRUE(Graph.ContainsVertex(3));
}

TEST_F(OrientedGraphTest, IteratorsFullCoverage) {
    Graph.AddEdge(10, 20);
    Graph.AddVertex(30);

    // Vertex Iterator
    int Sum = 0;
    for (auto It = Graph.BeginVertex(); It != Graph.EndVertex(); ++It) Sum += *It;
    EXPECT_EQ(Sum, 60);

    auto RIt = Graph.RBeginVertex();
    EXPECT_EQ(*RIt, 30);
    RIt++; 
    EXPECT_EQ(*RIt, 20);

    // Edge Iterator
    int EdgeCount = 0;
    for (auto It = Graph.BeginEdge(); It != Graph.EndEdge(); ++It) EdgeCount++;
    EXPECT_EQ(EdgeCount, 1);

    // Adjacent Iterator
    auto AdjIt = Graph.BeginAdjacent(10);
    EXPECT_EQ(*AdjIt, 20);
    AdjIt++;
    EXPECT_EQ(AdjIt, Graph.EndAdjacent(10));
    
    // Incident Iterator
    auto IncIt = Graph.BeginIncident(10);
    EXPECT_EQ((*IncIt).second, 20);
    
    // Iterator Removal
    Graph.RemoveVertex(Graph.BeginVertex());
    EXPECT_EQ(Graph.GetVertexCount(), 2);

    Graph.AddEdge(30, 20);
    Graph.RemoveEdge(Graph.BeginEdge());
    EXPECT_EQ(Graph.GetEdgeCount(), 0);
}

TEST_F(OrientedGraphTest, ExceptionsAndConst) {
    const OrientedGraph<int> ConstG = Graph;
    EXPECT_THROW(Graph.GetVertexDegree(99), std::invalid_argument);
    EXPECT_THROW(Graph.GetEdgeDegree(1, 99), std::invalid_argument); 
    EXPECT_THROW(Graph.RemoveVertex(99), std::invalid_argument);
    
    Graph.AddVertex(1);
    EXPECT_THROW(Graph.RemoveEdge(1, 99), std::invalid_argument);
    EXPECT_THROW(Graph.RemoveEdge(99, 1), std::invalid_argument);

    EXPECT_THROW(Graph.BeginAdjacent(99), std::invalid_argument);
    EXPECT_THROW(Graph.EndAdjacent(99), std::invalid_argument);
    EXPECT_THROW(Graph.BeginIncident(99), std::invalid_argument);
    EXPECT_THROW(Graph.EndIncident(99), std::invalid_argument);
}

TEST_F(OrientedGraphTest, ComparisonsAndStream) {
    OrientedGraph<int> G1, G2;
    G1.AddVertex(1);
    G2.AddVertex(1);
    EXPECT_TRUE(G1 == G2);
    G2.AddVertex(2);
    EXPECT_TRUE(G1 != G2);
    EXPECT_TRUE(G1 < G2);
    EXPECT_TRUE(G2 > G1);
    EXPECT_TRUE(G1 <= G2);
    EXPECT_TRUE(G2 >= G1);

    std::stringstream SS;
    SS << G2;
    EXPECT_FALSE(SS.str().empty());
}

struct DescTraits {
    using KeyType = int;
    struct Compare { bool operator()(int a, int b) const { return a > b; } };
};

TEST(TraitsTest, CustomOrder) {
    OrientedGraph<int, DescTraits> G;
    G.AddVertex(10);
    G.AddVertex(20);
    EXPECT_EQ(*G.BeginVertex(), 20);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
