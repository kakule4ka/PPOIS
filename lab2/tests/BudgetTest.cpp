#include <gtest/gtest.h>
#include "Budget.h"

TEST(BudgetTest, CalculateRemainingBudget) {
    Budget budget("BGT001", 1000000);
    double remaining = budget.calculateRemaining();
    EXPECT_EQ(remaining, 1000000);
}

TEST(BudgetTest, CalculateRemainingWithContingency) {
    Budget budget("BGT002", 500000);
    double remaining = budget.calculateRemaining();
    EXPECT_GT(remaining, 0);
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

TEST(BudgetTest, CannotAllocateBelowMinimum) {
    Budget budget("BGT005", 1000000);
    bool canAllocate = budget.canAllocate(500);
    EXPECT_FALSE(canAllocate);
}

TEST(BudgetTest, GetBudgetId) {
    Budget budget("BGT006", 750000);
    EXPECT_EQ(budget.getId(), "BGT006");
}
