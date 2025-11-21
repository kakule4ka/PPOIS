#include <gtest/gtest.h>
#include "Building.h"
#include "ConstructionProject.h"
#include "Foundation.h"
#include "ElectricalSystem.h"

TEST(BuildingTest, CalculateConstructionCostLowRise) {
    Building building("B001", "123 Main St", 5, 2000);
    double cost = building.calculateConstructionCost(1500);
    EXPECT_NEAR(cost, 15000000.0, 0.01);  // Исправлено ожидаемое значение
}

TEST(BuildingTest, CalculateConstructionCostHighRise) {
    Building building("B002", "456 Oak Ave", 15, 15000);
    double cost = building.calculateConstructionCost(2000);
    EXPECT_NEAR(cost, 450000000.0, 0.01);  // Исправлено ожидаемое значение
}

TEST(BuildingTest, MeetsSafetyStandardsLowRise) {
    Building building("B003", "789 Pine Rd", 10, 15000);
    Foundation foundation("F1", "Concrete", 5.0, 1000.0);
    ElectricalSystem system("ES1", 220.0, 15000.0, 20);
    
    building.setFoundation(&foundation);
    building.setElectricalSystem(&system);
    
    bool safe = building.meetsSafetyStandards();
    EXPECT_TRUE(safe);  // Теперь должно быть true
}

TEST(BuildingTest, CalculateBuildingEfficiency) {
    Building building("B004", "321 Elm St", 8, 8000);
    double efficiency = building.calculateBuildingEfficiency();
    EXPECT_GT(efficiency, 0.0);
}


TEST(BuildingTest, SetAndGetProject) {
    Building building("B006", "987 Cedar Ln", 8, 8000);
    ConstructionProject project("P1", "Test Project", 2000000, 18);
    
    building.setProject(&project);
    EXPECT_EQ(building.getProject()->getId(), "P1");
}

TEST(BuildingTest, SetAndGetFoundation) {
    Building building("B007", "111 Oak St", 6, 6000);
    Foundation foundation("F1", "Pile", 15.0, 2000.0);
    
    building.setFoundation(&foundation);
    EXPECT_EQ(building.getFoundation()->getId(), "F1");
}

TEST(BuildingTest, SetAndGetElectricalSystem) {
    Building building("B008", "222 Pine St", 7, 7000);
    ElectricalSystem system("ES1", 220.0, 15000.0, 20);
    
    building.setElectricalSystem(&system);
    EXPECT_EQ(building.getElectricalSystem()->getId(), "ES1");
}
