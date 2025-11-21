#include <gtest/gtest.h>
#include "Budget.h"
#include "ConstructionProject.h"
#include "CostEstimate.h"

TEST(BudgetTest, CalculateRemainingBudget) {
    Budget budget("BGT001", 1000000);
    double remaining = budget.calculateRemaining();
    EXPECT_EQ(remaining, 1000000);
}

TEST(BudgetTest, CanAllocateSmallAmount) {
    Budget budget("BGT003", 100000);
    bool canAllocate = budget.canAllocate(5000);
    EXPECT_TRUE(canAllocate);
}

TEST(BudgetTest, CannotAllocateLargeAmount) {
    Budget budget("BGT004", 50000);
    bool canAllocate = budget.canAllocate(40000);
    EXPECT_FALSE(canAllocate);
}

TEST(BudgetTest, CalculateCostVariance) {
    Budget budget("BGT005", 1000000);
    CostEstimate estimate1("EST1", "P1", 200000, 100000);
    CostEstimate estimate2("EST2", "P1", 150000, 50000);
    
    budget.addCostEstimate(&estimate1);
    budget.addCostEstimate(&estimate2);
    
    double variance = budget.calculateCostVariance();
    EXPECT_NE(variance, 0.0);
}

TEST(BudgetTest, IsOverBudget) {
    Budget budget("BGT006", 500000);
    bool overBudget = budget.isOverBudget();
    EXPECT_FALSE(overBudget);
}

TEST(BudgetTest, SetAndGetAssociatedProject) {
    Budget budget("BGT007", 1000000);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    budget.setAssociatedProject(&project);
    EXPECT_EQ(budget.getAssociatedProject()->getId(), "P1");
}

TEST(BudgetTest, AddAndGetCostEstimates) {
    Budget budget("BGT008", 1500000);
    CostEstimate estimate1("EST1", "P1", 200000, 100000);
    CostEstimate estimate2("EST2", "P1", 150000, 50000);
    
    budget.addCostEstimate(&estimate1);
    budget.addCostEstimate(&estimate2);
    
    auto estimates = budget.getCostEstimates();
    EXPECT_EQ(estimates.size(), 2);
}
