#include <gtest/gtest.h>
#include "core/ProjectPlan.h"
#include "core/ConstructionProject.h"
#include "core/RiskAssessment.h"
#include "core/Schedule.h"

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

TEST(ProjectPlanTest, CalculatePlanEfficiency) {
    ProjectPlan plan("PLAN004", "PROJ004", 5, 0.4);
    double efficiency = plan.calculatePlanEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ProjectPlanTest, NeedsRevision) {
    ProjectPlan plan("PLAN005", "PROJ005", 10, 0.9);
    bool needsRev = plan.needsRevision();
    EXPECT_TRUE(needsRev);
}

TEST(ProjectPlanTest, SetAndGetProject) {
    ProjectPlan plan("PLAN006", "PROJ006", 3, 0.2);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    plan.setProject(&project);
    EXPECT_EQ(plan.getProject()->getId(), "P1");
}

TEST(ProjectPlanTest, AddAndGetRiskAssessments) {
    ProjectPlan plan("PLAN007", "PROJ007", 4, 0.3);
    RiskAssessment assessment1("RA1", "P1", 0.5, "Financial");
    RiskAssessment assessment2("RA2", "P1", 0.3, "Schedule");
    
    plan.addRiskAssessment(&assessment1);
    plan.addRiskAssessment(&assessment2);
    
    auto assessments = plan.getRiskAssessments();
    EXPECT_EQ(assessments.size(), 2);
}

TEST(ProjectPlanTest, SetAndGetProjectSchedule) {
    ProjectPlan plan("PLAN008", "PROJ008", 4, 0.4);
    Schedule schedule("SCH1", "P1", 180);
    
    plan.setProjectSchedule(&schedule);
    EXPECT_EQ(plan.getProjectSchedule()->getId(), "SCH1");
}
