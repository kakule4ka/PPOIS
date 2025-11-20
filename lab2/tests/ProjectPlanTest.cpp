#include <gtest/gtest.h>
#include "ProjectPlan.h"

TEST(ProjectPlanTest, CalculateCompletionProbabilityLowRisk) {
    ProjectPlan plan("PLAN001", "PROJ001", 4, 0.2);
    double probability = plan.calculateCompletionProbability();
    EXPECT_GT(probability, 0.5);
}

TEST(ProjectPlanTest, CalculateCompletionProbabilityHighRisk) {
    ProjectPlan plan("PLAN002", "PROJ002", 8, 0.8);
    double probability = plan.calculateCompletionProbability();
    EXPECT_LT(probability, 0.5);
}

TEST(ProjectPlanTest, ValidateResourceAllocationOptimal) {
    ProjectPlan plan("PLAN003", "PROJ003", 4, 0.3);
    bool valid = plan.validateResourceAllocation();
    EXPECT_TRUE(valid);
}

TEST(ProjectPlanTest, ValidateResourceAllocationTooManyPhases) {
    ProjectPlan plan("PLAN004", "PROJ004", 10, 0.4);
    bool valid = plan.validateResourceAllocation();
    EXPECT_FALSE(valid);
}

TEST(ProjectPlanTest, ValidateResourceAllocationHighRisk) {
    ProjectPlan plan("PLAN005", "PROJ005", 5, 0.9);
    bool valid = plan.validateResourceAllocation();
    EXPECT_FALSE(valid);
}

TEST(ProjectPlanTest, GetPlanId) {
    ProjectPlan plan("PLAN006", "PROJ006", 3, 0.2);
    EXPECT_EQ(plan.getId(), "PLAN006");
}
