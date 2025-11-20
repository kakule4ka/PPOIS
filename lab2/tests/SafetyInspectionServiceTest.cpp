#include <gtest/gtest.h>
#include "SafetyInspectionService.h"

TEST(SafetyInspectionServiceTest, CalculateRiskScoreLow) {
    SafetyInspectionService service("SAFE001", 35, 0.92);
    double risk = service.calculateRiskScore();
    EXPECT_LT(risk, 20.0);
}

TEST(SafetyInspectionServiceTest, CalculateRiskScoreHigh) {
    SafetyInspectionService service("HIGH_RISK001", 20, 0.65);
    double risk = service.calculateRiskScore();
    EXPECT_GT(risk, 30.0);
}

TEST(SafetyInspectionServiceTest, CalculateRiskScoreManyAudits) {
    SafetyInspectionService service("SAFE002", 80, 0.85);
    double risk = service.calculateRiskScore();
    EXPECT_GE(risk, 0);
}

TEST(SafetyInspectionServiceTest, IdentifySafetyHazardsGood) {
    SafetyInspectionService service("DIGITAL001", 50, 0.88);
    bool hazards = service.identifySafetyHazards();
    EXPECT_TRUE(hazards);
}

TEST(SafetyInspectionServiceTest, IdentifySafetyHazardsPoor) {
    SafetyInspectionService service("BASIC001", 8, 0.72);
    bool hazards = service.identifySafetyHazards();
    EXPECT_FALSE(hazards);
}

TEST(SafetyInspectionServiceTest, GetServiceId) {
    SafetyInspectionService service("SAFE003", 45, 0.90);
    EXPECT_EQ(service.getId(), "SAFE003");
}
