#include <gtest/gtest.h>
#include "Wall.h"

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

TEST(WallTest, CalculateMaterialQuantitySteel) {
    Wall wall("WALL003", "Steel", 4.0, 6.0);
    double quantity = wall.calculateMaterialQuantity();
    EXPECT_GT(quantity, 0);
}

TEST(WallTest, MeetsStructuralRequirementsNormal) {
    Wall wall("WALL004", "Concrete", 4.0, 12.0);
    bool meets = wall.meetsStructuralRequirements();
    EXPECT_TRUE(meets);
}

TEST(WallTest, MeetsStructuralRequirementsTall) {
    Wall wall("WALL005", "Steel", 12.0, 15.0);
    bool meets = wall.meetsStructuralRequirements();
    EXPECT_FALSE(meets);
}

TEST(WallTest, GetWallId) {
    Wall wall("WALL006", "Brick", 3.0, 6.0);
    EXPECT_EQ(wall.getId(), "WALL006");
}
