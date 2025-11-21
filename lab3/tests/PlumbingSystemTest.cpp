#include <gtest/gtest.h>
#include "models/PlumbingSystem.h"
#include "models/Building.h"
#include "core/QualityStandard.h"

TEST(PlumbingSystemTest, CalculateWaterFlowCopper) {
    PlumbingSystem system("PLUM001", "Copper", 4.0, 12);
    double flow = system.calculateWaterFlow();
    EXPECT_GT(flow, 0);
}

TEST(PlumbingSystemTest, CalculateWaterFlowPVC) {
    PlumbingSystem system("PLUM002", "PVC", 3.5, 8);
    double flow = system.calculateWaterFlow();
    EXPECT_GT(flow, 0);
}

TEST(PlumbingSystemTest, ValidatePressureRequirementsNormal) {
    PlumbingSystem system("PLUM004", "Copper", 4.5, 15);
    bool valid = system.validatePressureRequirements();
    EXPECT_TRUE(valid);
}

TEST(PlumbingSystemTest, CalculateSystemReliability) {
    PlumbingSystem system("PLUM005", "PEX", 4.2, 10);
    double reliability = system.calculateSystemReliability();
    EXPECT_GT(reliability, 0.0);
}

TEST(PlumbingSystemTest, MeetsPlumbingCode) {
    PlumbingSystem system("PLUM006", "Copper", 4.0, 12);
    bool meetsCode = system.meetsPlumbingCode();
    EXPECT_FALSE(meetsCode);
}

TEST(PlumbingSystemTest, SetAndGetBuilding) {
    PlumbingSystem system("PLUM007", "PVC", 4.2, 18);
    Building building("B1", "Test Building", 5, 2000);
    
    system.setBuilding(&building);
    EXPECT_EQ(system.getBuilding()->getId(), "B1");
}

TEST(PlumbingSystemTest, AddAndGetComplianceStandards) {
    PlumbingSystem system("PLUM008", "Copper", 4.5, 15);
    QualityStandard standard1("QS1", "Water Pressure", "Plumbing", 4.0);
    QualityStandard standard2("QS2", "Flow Rate", "Plumbing", 10.0);
    
    system.addComplianceStandard(&standard1);
    system.addComplianceStandard(&standard2);
    
    auto standards = system.getComplianceStandards();
    EXPECT_EQ(standards.size(), 2);
}
