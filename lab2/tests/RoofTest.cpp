#include <gtest/gtest.h>
#include "Roof.h"
#include "Building.h"
#include "BuildingMaterial.h"

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

TEST(RoofTest, ValidateWindResistanceNormal) {
    Roof roof("ROOF004", "Hip", 120.0, 20.0);
    bool resistant = roof.validateWindResistance(100.0);
    EXPECT_TRUE(resistant);
}

TEST(RoofTest, CalculateRoofDurability) {
    Roof roof("ROOF005", "Gable", 120.0, 15.0);
    double durability = roof.calculateRoofDurability();
    EXPECT_GT(durability, 0.0);
}

TEST(RoofTest, RequiresMaintenance) {
    Roof roof("ROOF006", "Flat", 80.0, 5.0);
    bool needsMaintenance = roof.requiresMaintenance();
    EXPECT_TRUE(needsMaintenance);
}

TEST(RoofTest, SetAndGetBuilding) {
    Roof roof("ROOF007", "Hip", 90.0, 15.0);
    Building building("B1", "Test Building", 5, 2000);
    
    roof.setBuilding(&building);
    EXPECT_EQ(roof.getBuilding()->getId(), "B1");
}

TEST(RoofTest, AddAndGetRoofingMaterials) {
    Roof roof("ROOF008", "Gable", 110.0, 20.0);
    BuildingMaterial material1("MAT1", "Shingles", 50, 30);
    BuildingMaterial material2("MAT2", "Underlayment", 30, 20);
    
    roof.addRoofingMaterial(&material1);
    roof.addRoofingMaterial(&material2);
    
    auto materials = roof.getRoofingMaterials();
    EXPECT_EQ(materials.size(), 2);
}
