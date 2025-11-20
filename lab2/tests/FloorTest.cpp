#include <gtest/gtest.h>
#include "Floor.h"

TEST(FloorTest, CalculateLoadCapacity) {
    Floor floor("FLR001", 0, "Concrete", 500.0);
    double capacity = floor.calculateLoadCapacity();
    EXPECT_EQ(capacity, 50000.0);
}

TEST(FloorTest, CalculateLoadCapacityLargeArea) {
    Floor floor("FLR002", 1, "Composite", 800.0);
    double capacity = floor.calculateLoadCapacity();
    EXPECT_EQ(capacity, 80000.0);
}

TEST(FloorTest, ValidateFloorPlanComplianceValid) {
    Floor floor("FLR003", 2, "Steel", 400.0);
    bool compliant = floor.validateFloorPlanCompliance();
    EXPECT_TRUE(compliant);
}

TEST(FloorTest, ValidateFloorPlanComplianceInvalidArea) {
    Floor floor("FLR004", 3, "Concrete", 0.0);
    bool compliant = floor.validateFloorPlanCompliance();
    EXPECT_FALSE(compliant);
}

TEST(FloorTest, ValidateFloorPlanComplianceNegativeLevel) {
    Floor floor("FLR005", -1, "Wood", 300.0);
    bool compliant = floor.validateFloorPlanCompliance();
    EXPECT_FALSE(compliant);
}

TEST(FloorTest, GetFloorId) {
    Floor floor("FLR006", 5, "Concrete", 600.0);
    EXPECT_EQ(floor.getId(), "FLR006");
}
