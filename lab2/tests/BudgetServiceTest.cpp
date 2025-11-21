#include <gtest/gtest.h>
#include "services/BudgetService.h"
#include "core/ConstructionProject.h"
#include "models/Budget.h"

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

TEST(BudgetServiceTest, CalculateBudgetEfficiency) {
    BudgetService service("BUDGET004", 900000, 35);
    double efficiency = service.calculateBudgetEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(BudgetServiceTest, RequiresBudgetReview) {
    BudgetService service("HIGH_RISK001", 2000000, 10);
    bool needsReview = service.requiresBudgetReview();
    EXPECT_TRUE(needsReview);
}

TEST(BudgetServiceTest, AddAndGetManagedProjects) {
    BudgetService service("BUDGET005", 800000, 30);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addManagedProject(&project1);
    service.addManagedProject(&project2);
    
    auto projects = service.getManagedProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(BudgetServiceTest, AddAndGetProjectBudgets) {
    BudgetService service("BUDGET006", 1000000, 25);
    Budget budget1("B1", 500000);
    Budget budget2("B2", 300000);
    
    service.addProjectBudget(&budget1);
    service.addProjectBudget(&budget2);
    
    auto budgets = service.getProjectBudgets();
    EXPECT_EQ(budgets.size(), 2);
}
