#include <gtest/gtest.h>
#include "InventoryService.h"

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

TEST(InventoryServiceTest, CalculateStockOutRiskAutomated) {
    InventoryService service("AUTOMATED001", 450, 7.2);
    double risk = service.calculateStockOutRisk();
    EXPECT_GE(risk, 0);
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

TEST(InventoryServiceTest, GetServiceId) {
    InventoryService service("INV003", 300, 4.5);
    EXPECT_EQ(service.getId(), "INV003");
}
