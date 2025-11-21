#include <gtest/gtest.h>
#include "InventoryService.h"
#include "BuildingMaterial.h"

TEST(InventoryServiceTest, CalculateStockOutRiskLow) {
    InventoryService service("INV001", 200, 6.5);
    double risk = service.calculateStockOutRisk();
    EXPECT_GE(risk, 0);
}

TEST(InventoryServiceTest, CalculateStockOutRiskHigh) {
    InventoryService service("INV002", 800, 2.0);
    double risk = service.calculateStockOutRisk();
    EXPECT_GT(risk, 10.0);
}

TEST(InventoryServiceTest, OptimizeInventoryLevelsGood) {
    InventoryService service("DIGITAL001", 350, 5.8);
    bool optimized = service.optimizeInventoryLevels();
    EXPECT_TRUE(optimized);
}

TEST(InventoryServiceTest, OptimizeInventoryLevelsPoor) {
    InventoryService service("MANUAL001", 600, 1.2);
    bool optimized = service.optimizeInventoryLevels();
    EXPECT_FALSE(optimized);
}

TEST(InventoryServiceTest, AddAndGetManagedMaterials) {
    InventoryService service("INV003", 300, 4.5);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Steel", 50, 80);
    
    service.addMaterial(&material1);
    service.addMaterial(&material2);
    
    auto materials = service.getManagedMaterials();
    EXPECT_EQ(materials.size(), 2);
}

TEST(InventoryServiceTest, GetServiceId) {
    InventoryService service("INV004", 300, 4.5);
    EXPECT_EQ(service.getId(), "INV004");
}
