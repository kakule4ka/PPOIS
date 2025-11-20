#include <gtest/gtest.h>
#include "Foundation.h"

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

TEST(FoundationTest, CalculateConstructionTimeStrip) {
    Foundation foundation("FND003", "Strip", 2.0, 500.0);
    double time = foundation.calculateConstructionTime();
    EXPECT_GT(time, 5.0);
}

TEST(FoundationTest, ValidateSoilCompatibilityClay) {
    Foundation foundation("FND004", "Pile", 12.0, 1800.0);
    bool compatible = foundation.validateSoilCompatibility("Clay");
    EXPECT_TRUE(compatible);
}

TEST(FoundationTest, ValidateSoilCompatibilitySand) {
    Foundation foundation("FND005", "Strip", 2.0, 250.0);
    bool compatible = foundation.validateSoilCompatibility("Sand");
    EXPECT_TRUE(compatible);
}

TEST(FoundationTest, GetFoundationId) {
    Foundation foundation("FND006", "Raft", 4.0, 3000.0);
    EXPECT_EQ(foundation.getId(), "FND006");
}
