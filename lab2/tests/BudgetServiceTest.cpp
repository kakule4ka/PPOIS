#include <gtest/gtest.h>
#include "BudgetService.h"

TEST(BudgetServiceTest, CalculateBudgetVarianceNormal) {
    BudgetService service("BUDGET001", 750000, 40);
    double variance = service.calculateBudgetVariance();
    EXPECT_EQ(variance, 37500.0);
}

TEST(BudgetServiceTest, CalculateBudgetVarianceLargeBudget) {
    BudgetService service("BUDGET002", 2000000, 10);
    double variance = service.calculateBudgetVariance();
    EXPECT_EQ(variance, 100000.0);
}

TEST(BudgetServiceTest, DetectOverspendingNormal) {
    BudgetService service("BUDGET003", 750000, 40);
    bool overspending = service.detectOverspending();
    EXPECT_FALSE(overspending);
}

TEST(BudgetServiceTest, DetectOverspendingHighSpending) {
    BudgetService service("HIGH_RISK001", 2000000, 10);
    bool overspending = service.detectOverspending();
    EXPECT_TRUE(overspending);
}

TEST(BudgetServiceTest, GetServiceId) {
    BudgetService service("BUDGET004", 900000, 35);
    EXPECT_EQ(service.getId(), "BUDGET004");
}
