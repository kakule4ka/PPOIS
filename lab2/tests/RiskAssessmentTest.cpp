#include <gtest/gtest.h>
#include "RiskAssessment.h"

TEST(RiskAssessmentTest, CalculateMitigationCostLowRisk) {
    RiskAssessment assessment("RISK001", "PROJ001", 0.3, "Financial");
    double cost = assessment.calculateMitigationCost();
    EXPECT_EQ(cost, 1500.0);
}

TEST(RiskAssessmentTest, CalculateMitigationCostHighRisk) {
    RiskAssessment assessment("RISK002", "PROJ002", 0.9, "Safety");
    double cost = assessment.calculateMitigationCost();
    EXPECT_EQ(cost, 4500.0);
}

TEST(RiskAssessmentTest, RequiresImmediateActionHigh) {
    RiskAssessment assessment("RISK003", "PROJ003", 0.7, "Schedule");
    bool immediate = assessment.requiresImmediateAction();
    EXPECT_TRUE(immediate);
}

TEST(RiskAssessmentTest, RequiresImmediateActionLow) {
    RiskAssessment assessment("RISK004", "PROJ004", 0.4, "Quality");
    bool immediate = assessment.requiresImmediateAction();
    EXPECT_FALSE(immediate);
}

TEST(RiskAssessmentTest, GetAssessmentId) {
    RiskAssessment assessment("RISK005", "PROJ005", 0.5, "Environmental");
    EXPECT_EQ(assessment.getId(), "RISK005");
}
