#include <gtest/gtest.h>
#include "models/BuildingMaterial.h"
#include "core/ConstructionProject.h"
#include "models/Supplier.h"

TEST(BuildingMaterialTest, CalculateTotalCostSmallQuantity) {
    BuildingMaterial material("MAT001", "Concrete", 100, 50);
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

TEST(BuildingMaterialTest, CalculateWasteEstimate) {
    BuildingMaterial material("MAT005", "Concrete", 1000, 50);
    double waste = material.calculateWasteEstimate();
    EXPECT_GT(waste, 0.0);
}

TEST(BuildingMaterialTest, NeedsReorderingLowStock) {
    BuildingMaterial material("MAT006", "Concrete", 50, 50);
    bool needsReorder = material.needsReordering();
    EXPECT_TRUE(needsReorder);
}

TEST(BuildingMaterialTest, SetAndGetUsedInProject) {
    BuildingMaterial material("MAT007", "Steel", 200, 80);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    material.setUsedInProject(&project);
    EXPECT_EQ(material.getUsedInProject()->getId(), "P1");
}

TEST(BuildingMaterialTest, SetAndGetSupplier) {
    BuildingMaterial material("MAT008", "Wood", 300, 30);
    Supplier supplier("S1", "Timber Co", "Wood", 0.85);
    
    material.setSupplier(&supplier);
    EXPECT_EQ(material.getSupplier()->getId(), "S1");
}
