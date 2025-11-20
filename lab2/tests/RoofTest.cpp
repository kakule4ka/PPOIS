#include <gtest/gtest.h>
#include "Roof.h"

TEST(RoofTest, CalculateWaterDrainageFlat) {
    Roof roof("ROOF001", "Flat", 100.0, 2.0);
    double drainage = roof.calculateWaterDrainage();
    EXPECT_EQ(drainage, 500.0);
}

TEST(RoofTest, CalculateWaterDrainageGable) {
    Roof roof("ROOF002", "Gable", 150.0, 25.0);
    double drainage = roof.calculateWaterDrainage();
    EXPECT_EQ(drainage, 2250.0);
}

TEST(RoofTest, CalculateWaterDrainageHip) {
    Roof roof("ROOF003", "Hip", 120.0, 20.0);
    double drainage = roof.calculateWaterDrainage();
    EXPECT_EQ(drainage, 1440.0);
}

TEST(RoofTest, ValidateWindResistanceNormal) {
    Roof roof("ROOF004", "Hip", 120.0, 20.0);
    bool resistant = roof.validateWindResistance(100.0);
    EXPECT_TRUE(resistant);
}

TEST(RoofTest, ValidateWindResistanceHighWind) {
    Roof roof("ROOF005", "Flat", 80.0, 5.0);
    bool resistant = roof.validateWindResistance(150.0);
    EXPECT_FALSE(resistant);
}

TEST(RoofTest, GetRoofId) {
    Roof roof("ROOF006", "Hip", 90.0, 15.0);
    EXPECT_EQ(roof.getId(), "ROOF006");
}
