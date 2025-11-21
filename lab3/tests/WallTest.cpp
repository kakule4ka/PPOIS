#include <gtest/gtest.h>
#include "models/Wall.h"
#include "models/Building.h"
#include "models/BuildingMaterial.h"

TEST(WallTest, CalculateMaterialQuantityConcrete) {
    Wall wall("WALL001", "Concrete", 3.0, 10.0);
    double quantity = wall.calculateMaterialQuantity();
    EXPECT_GT(quantity, 0);
}

TEST(WallTest, CalculateMaterialQuantityBrick) {
    Wall wall("WALL002", "Brick", 2.5, 8.0);
    double quantity = wall.calculateMaterialQuantity();
    EXPECT_GT(quantity, 0);
}

TEST(WallTest, MeetsStructuralRequirementsNormal) {
    Wall wall("WALL004", "Concrete", 4.0, 12.0);
    bool meets = wall.meetsStructuralRequirements();
    EXPECT_TRUE(meets);
}

TEST(WallTest, CalculateWallStrength) {
    Wall wall("WALL005", "Steel", 4.0, 6.0);
    double strength = wall.calculateWallStrength();
    EXPECT_GT(strength, 0.0);
}

TEST(WallTest, IsLoadBearing) {
    Wall wall("WALL006", "Concrete", 3.0, 8.0);
    bool loadBearing = wall.isLoadBearing();
    EXPECT_FALSE(loadBearing);
}

TEST(WallTest, SetAndGetBuilding) {
    Wall wall("WALL007", "Brick", 3.0, 6.0);
    Building building("B1", "Test Building", 5, 2000);
    
    wall.setBuilding(&building);
    EXPECT_EQ(wall.getBuilding()->getId(), "B1");
}

TEST(WallTest, AddAndGetConstructionMaterials) {
    Wall wall("WALL008", "Concrete", 3.5, 10.0);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Rebar", 50, 80);
    
    wall.addConstructionMaterial(&material1);
    wall.addConstructionMaterial(&material2);
    
    auto materials = wall.getConstructionMaterials();
    EXPECT_EQ(materials.size(), 2);
}
