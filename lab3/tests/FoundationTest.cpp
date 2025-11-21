#include <gtest/gtest.h>
#include "models/Foundation.h"
#include "models/Building.h"
#include "core/QualityStandard.h"

TEST(FoundationTest, CalculateConstructionTimePile) {
    Foundation foundation("FND001", "Pile", 15.0, 2000.0);
    double time = foundation.calculateConstructionTime();
    EXPECT_GT(time, 50.0);
}

TEST(FoundationTest, CalculateConstructionTimeRaft) {
    Foundation foundation("FND002", "Raft", 3.0, 1500.0);
    double time = foundation.calculateConstructionTime();
    EXPECT_GT(time, 10.0);
}

TEST(FoundationTest, ValidateSoilCompatibilityClay) {
    Foundation foundation("FND004", "Pile", 12.0, 1800.0);
    bool compatible = foundation.validateSoilCompatibility("Clay");
    EXPECT_TRUE(compatible);
}

TEST(FoundationTest, CalculateStabilityFactor) {
    Foundation foundation("FND005", "Strip", 2.0, 500.0);
    double stability = foundation.calculateStabilityFactor();
    EXPECT_GT(stability, 0.0);
}

TEST(FoundationTest, MeetsStructuralRequirements) {
    Foundation foundation("FND006", "Raft", 4.0, 3000.0);
    bool meetsRequirements = foundation.meetsStructuralRequirements();
    EXPECT_FALSE(meetsRequirements);
}

TEST(FoundationTest, SetAndGetBuilding) {
    Foundation foundation("FND007", "Pile", 10.0, 1500.0);
    Building building("B1", "Test Building", 5, 2000);
    
    foundation.setBuilding(&building);
    EXPECT_EQ(foundation.getBuilding()->getId(), "B1");
}

TEST(FoundationTest, AddAndGetComplianceStandards) {
    Foundation foundation("FND008", "Strip", 2.5, 600.0);
    QualityStandard standard1("QS1", "Concrete Strength", "Structural", 30.0);
    QualityStandard standard2("QS2", "Load Capacity", "Structural", 25.0);
    
    foundation.addComplianceStandard(&standard1);
    foundation.addComplianceStandard(&standard2);
    
    auto standards = foundation.getComplianceStandards();
    EXPECT_EQ(standards.size(), 2);
}
