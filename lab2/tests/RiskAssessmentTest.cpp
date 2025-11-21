#include <gtest/gtest.h>
#include "core/RiskAssessment.h"
#include "core/ConstructionProject.h"
#include "core/SafetyProtocol.h"

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

TEST(RiskAssessmentTest, CalculateRiskImpact) {
    RiskAssessment assessment("RISK004", "PROJ004", 0.5, "Quality");
    double impact = assessment.calculateRiskImpact();
    EXPECT_GT(impact, 0.0);
}


TEST(RiskAssessmentTest, SetAndGetProject) {
    RiskAssessment assessment("RISK006", "PROJ006", 0.4, "Schedule");
    ConstructionProject project("P1", "Test Project", 500000, 36);
    
    assessment.setProject(&project);
    EXPECT_EQ(assessment.getProject()->getId(), "P1");
}

TEST(RiskAssessmentTest, AddAndGetMitigationProtocols) {
    RiskAssessment assessment("RISK007", "PROJ007", 0.6, "Safety");
    SafetyProtocol protocol1("SP1", "Fall Protection", 40, true);
    SafetyProtocol protocol2("SP2", "Fire Safety", 20, true);
    
    assessment.addMitigationProtocol(&protocol1);
    assessment.addMitigationProtocol(&protocol2);
    
    auto protocols = assessment.getMitigationProtocols();
    EXPECT_EQ(protocols.size(), 2);
}
