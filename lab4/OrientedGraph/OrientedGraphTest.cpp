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

TEST_F(OrientedGraphTest, BasicOperations) {
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
    
    Graph.Clear();
    EXPECT_EQ(Graph.GetVertexCount(), 0);
}

TEST_F(OrientedGraphTest, DegreesCalculation) {
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

    Graph.RemoveEdge(1, 2);
    EXPECT_FALSE(Graph.ContainsEdge(1, 2));
    EXPECT_EQ(Graph.GetEdgeCount(), 1);

    Graph.RemoveVertex(2);
    EXPECT_FALSE(Graph.ContainsVertex(2));
    EXPECT_EQ(Graph.GetEdgeCount(), 0);
}

TEST_F(OrientedGraphTest, IteratorsFullCheck) {
    Graph.AddEdge(10, 20); 
    Graph.AddEdge(10, 30); 
    Graph.AddVertex(40);

    // 1. Vertex Iterator
    std::vector<int> Vertices;
    for (auto It = Graph.BeginVertex(); It != Graph.EndVertex(); ++It) {
        Vertices.push_back(*It);
    }
    std::vector<int> ExpectedV = {10, 20, 30, 40};
    EXPECT_EQ(Vertices, ExpectedV);

    // 2. Edge Iterator (Bidirectional)
    auto EIt = Graph.BeginEdge();
    EXPECT_EQ((*EIt).second, 20);
    ++EIt;
    EXPECT_EQ((*EIt).second, 30);
    ++EIt; 
    EXPECT_EQ(EIt, Graph.EndEdge());
    
    // Reverse (Check operator--)
    --EIt;
    EXPECT_EQ((*EIt).second, 30);

    // 3. Removal by Iterator
    auto VIt = Graph.BeginVertex();
    Graph.RemoveVertex(VIt);
    EXPECT_FALSE(Graph.ContainsVertex(10));
    
    Graph.AddEdge(50, 60);
    auto EdgeToRemove = Graph.BeginEdge();
    Graph.RemoveEdge(EdgeToRemove);
    EXPECT_FALSE(Graph.ContainsEdge(50, 60));

    // 4. Other Iterators (Smoke test)
    auto AdjIt = Graph.BeginAdjacent(40);
    auto IncIt = Graph.BeginIncident(40);
}

TEST_F(OrientedGraphTest, ComparisonOperators) {
    OrientedGraph<int> G1, G2;
    G1.AddVertex(1);
    G2.AddVertex(1);
    
    EXPECT_TRUE(G1 == G2);
    EXPECT_FALSE(G1 != G2);
    
    G2.AddVertex(2);
    EXPECT_TRUE(G1 < G2);
    EXPECT_TRUE(G1 <= G2);
    EXPECT_TRUE(G2 > G1);
    EXPECT_TRUE(G2 >= G1);
}

TEST_F(OrientedGraphTest, Exceptions) {
    EXPECT_THROW(Graph.GetVertexDegree(99), std::invalid_argument);
    EXPECT_THROW(Graph.RemoveVertex(99), std::invalid_argument);
    Graph.AddVertex(1);
    EXPECT_THROW(Graph.RemoveEdge(1, 99), std::invalid_argument);
}

TEST_F(OrientedGraphTest, StreamOutput) {
    Graph.AddEdge(1, 2);
    std::stringstream SS;
    SS << Graph;
    EXPECT_FALSE(SS.str().empty());
    EXPECT_NE(SS.str().find("1: 2"), std::string::npos);
}
