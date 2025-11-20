#include <gtest/gtest.h>
#include "PlumbingSystem.h"

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

TEST(PlumbingSystemTest, CalculateWaterFlowPEX) {
    PlumbingSystem system("PLUM003", "PEX", 4.5, 15);
    double flow = system.calculateWaterFlow();
    EXPECT_GT(flow, 0);
}

TEST(PlumbingSystemTest, ValidatePressureRequirementsNormal) {
    PlumbingSystem system("PLUM004", "Copper", 4.5, 15);
    bool valid = system.validatePressureRequirements();
    EXPECT_TRUE(valid);
}

TEST(PlumbingSystemTest, ValidatePressureRequirementsLow) {
    PlumbingSystem system("PLUM005", "Galvanized", 1.5, 10);
    bool valid = system.validatePressureRequirements();
    EXPECT_FALSE(valid);
}

TEST(PlumbingSystemTest, GetSystemId) {
    PlumbingSystem system("PLUM006", "PVC", 4.2, 18);
    EXPECT_EQ(system.getId(), "PLUM006");
}
