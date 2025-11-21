#include <gtest/gtest.h>
#include "models/Floor.h"
#include "models/Building.h"
#include "models/BuildingMaterial.h"

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

TEST(FloorTest, CalculateFloorStability) {
    Floor floor("FLR004", 3, "Concrete", 600.0);
    double stability = floor.calculateFloorStability();
    EXPECT_GT(stability, 0.0);
}

TEST(FloorTest, NeedsReinforcement) {
    Floor floor("FLR005", 8, "Wood", 1200.0);
    bool needsReinforcement = floor.needsReinforcement();
    EXPECT_TRUE(needsReinforcement);
}

TEST(FloorTest, SetAndGetBuilding) {
    Floor floor("FLR006", 5, "Concrete", 600.0);
    Building building("B1", "Test Building", 10, 5000);
    
    floor.setBuilding(&building);
    EXPECT_EQ(floor.getBuilding()->getId(), "B1");
}

TEST(FloorTest, AddAndGetFlooringMaterials) {
    Floor floor("FLR007", 2, "Concrete", 500.0);
    BuildingMaterial material1("MAT1", "Concrete", 50, 50);
    BuildingMaterial material2("MAT2", "Rebar", 20, 80);
    
    floor.addFlooringMaterial(&material1);
    floor.addFlooringMaterial(&material2);
    
    auto materials = floor.getFlooringMaterials();
    EXPECT_EQ(materials.size(), 2);
}
