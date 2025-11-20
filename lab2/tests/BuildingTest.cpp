#include <gtest/gtest.h>
#include "Building.h"

TEST(BuildingTest, CalculateConstructionCostLowRise) {
    Building building("B001", "123 Main St", 5, 2000);
    double cost = building.calculateConstructionCost(1500);
    EXPECT_NEAR(cost, 3000000.0, 0.01);
}

TEST(BuildingTest, CalculateConstructionCostHighRise) {
    Building building("B002", "456 Oak Ave", 15, 15000);
    double cost = building.calculateConstructionCost(2000);
    EXPECT_NEAR(cost, 36000000.0, 0.01);
}

TEST(BuildingTest, MeetsSafetyStandardsLowRise) {
    Building building("B003", "789 Pine Rd", 10, 15000);
    bool safe = building.meetsSafetyStandards();
    EXPECT_TRUE(safe);
}

TEST(BuildingTest, MeetsSafetyStandardsHighRise) {
    Building building("B004", "321 Elm St", 25, 25000);
    bool safe = building.meetsSafetyStandards();
    EXPECT_FALSE(safe);
}

TEST(BuildingTest, MeetsSafetyStandardsAreaLimit) {
    Building building("B005", "654 Maple Dr", 5, 10000);
    bool safe = building.meetsSafetyStandards();
    EXPECT_TRUE(safe);
}

TEST(BuildingTest, GetBuildingId) {
    Building building("B006", "987 Cedar Ln", 8, 8000);
    EXPECT_EQ(building.getId(), "B006");
}
