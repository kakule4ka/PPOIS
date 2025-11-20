#include <gtest/gtest.h>
#include "ProjectManager.h"

TEST(ProjectManagerTest, CalculateManagementEfficiency) {
    ProjectManager manager("PM001", "Alice Brown", 90000, 3, 2000000);
    double efficiency = manager.calculateManagementEfficiency();
    EXPECT_GT(efficiency, 0);
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

TEST(ProjectManagerTest, CannotHandleMoreProjectsMaxProjects) {
    ProjectManager manager("PM004", "Diana Red", 92000, 5, 4000000);
    bool canHandle = manager.canHandleMoreProjects();
    EXPECT_FALSE(canHandle);
}

TEST(ProjectManagerTest, CannotHandleMoreProjectsHighBudget) {
    ProjectManager manager("PM005", "Eve Yellow", 98000, 4, 6000000);
    bool canHandle = manager.canHandleMoreProjects();
    EXPECT_FALSE(canHandle);
}

TEST(ProjectManagerTest, GetManagerId) {
    ProjectManager manager("PM006", "Frank Black", 87000, 1, 1000000);
    EXPECT_EQ(manager.getId(), "PM006");
}
