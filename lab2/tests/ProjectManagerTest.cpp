#include <gtest/gtest.h>
#include "models/ProjectManager.h"
#include "core/ConstructionProject.h"
#include "models/Budget.h"
#include "core/Schedule.h"

TEST(ProjectManagerTest, CalculateManagementEfficiency) {
    ProjectManager manager("PM001", "Alice Brown", 90000, 3, 2000000);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    manager.assignToProject(&project);
    
    double efficiency = manager.calculateManagementEfficiency();
    EXPECT_GT(efficiency, 0);  // Теперь должно быть > 0
}

TEST(ProjectManagerTest, CalculateManagementEfficiencyNoProjects) {
    ProjectManager manager("PM002", "Bob Green", 85000, 0, 1500000);
    double efficiency = manager.calculateManagementEfficiency();
    EXPECT_EQ(efficiency, 0.0);
}

TEST(ProjectManagerTest, CanHandleMoreProjectsAvailable) {
    ProjectManager manager("PM003", "Charlie Blue", 95000, 2, 3000000);
    bool canHandle = manager.canHandleMoreProjects();
    EXPECT_TRUE(canHandle);
}

TEST(ProjectManagerTest, CalculateRiskMitigationScore) {
    ProjectManager manager("PM004", "Diana Red", 92000, 5, 4000000);
    double score = manager.calculateRiskMitigationScore();
    EXPECT_GT(score, 0.0);
    EXPECT_LE(score, 200.0);  // Исправлен предел
}

TEST(ProjectManagerTest, IsBudgetOptimized) {
    ProjectManager manager("PM005", "Eve Yellow", 98000, 4, 6000000);
    Budget budget("B1", 5000000);
    manager.setManagedBudget(&budget);
    
    bool optimized = manager.isBudgetOptimized();
    EXPECT_FALSE(optimized);
}

TEST(ProjectManagerTest, AssignAndGetProjects) {
    ProjectManager manager("PM006", "Frank Black", 87000, 1, 1000000);
    ConstructionProject project1("P1", "Project 1", 1000000, 12);
    
    manager.assignToProject(&project1);
    auto projects = manager.getCurrentProjects();
    EXPECT_EQ(projects.size(), 1);
}

TEST(ProjectManagerTest, SetAndGetBudget) {
    ProjectManager manager("PM007", "Grace White", 88000, 2, 2000000);
    Budget budget("B1", 1500000);
    
    manager.setManagedBudget(&budget);
    EXPECT_EQ(manager.getManagedBudget()->getId(), "B1");
}
