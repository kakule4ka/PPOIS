#include <gtest/gtest.h>
#include "BuildingMaterial.h"

TEST(BuildingMaterialTest, CalculateTotalCostSmallQuantity) {
    BuildingMaterial material("MAT001", "Concrete", 100, 50);
    double cost = material.calculateTotalCost();
    EXPECT_GT(cost, 0);
}

TEST(BuildingMaterialTest, CalculateTotalCostBulkQuantity) {
    BuildingMaterial material("MAT002", "Steel", 1500, 80);
    double cost = material.calculateTotalCost();
    EXPECT_GT(cost, 0);
}

TEST(BuildingMaterialTest, IsQuantitySufficient) {
    BuildingMaterial material("MAT003", "Bricks", 500, 2);
    bool sufficient = material.isQuantitySufficient(400);
    EXPECT_TRUE(sufficient);
}

TEST(BuildingMaterialTest, IsQuantityInsufficient) {
    BuildingMaterial material("MAT004", "Cement", 50, 15);
    bool sufficient = material.isQuantitySufficient(60);
    EXPECT_FALSE(sufficient);
}

TEST(BuildingMaterialTest, IsQuantitySufficientWithSafetyMargin) {
    BuildingMaterial material("MAT005", "Rebar", 200, 25);
    bool sufficient = material.isQuantitySufficient(150);
    EXPECT_TRUE(sufficient);
}

TEST(BuildingMaterialTest, GetMaterialId) {
    BuildingMaterial material("MAT006", "Wood", 300, 30);
    EXPECT_EQ(material.getId(), "MAT006");
}
