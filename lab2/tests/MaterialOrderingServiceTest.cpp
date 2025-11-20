#include <gtest/gtest.h>
#include "MaterialOrderingService.h"

TEST(MaterialOrderingServiceTest, CalculateOrderEfficiencyHigh) {
    MaterialOrderingService service("ORDER001", 150, 0.94);
    double efficiency = service.calculateOrderEfficiency();
    EXPECT_EQ(efficiency, 94.0);
}

TEST(MaterialOrderingServiceTest, CalculateOrderEfficiencyLow) {
    MaterialOrderingService service("ORDER002", 80, 0.72);
    double efficiency = service.calculateOrderEfficiency();
    EXPECT_EQ(efficiency, 72.0);
}

TEST(MaterialOrderingServiceTest, CalculateOrderEfficiencyBulk) {
    MaterialOrderingService service("BULK001", 300, 0.87);
    double efficiency = service.calculateOrderEfficiency();
    EXPECT_EQ(efficiency, 87.0);
}

TEST(MaterialOrderingServiceTest, OptimizeOrderQuantityYes) {
    MaterialOrderingService service("INVENTORY001", 200, 0.91);
    bool optimized = service.optimizeOrderQuantity();
    EXPECT_TRUE(optimized);
}

TEST(MaterialOrderingServiceTest, OptimizeOrderQuantityNo) {
    MaterialOrderingService service("MANUAL001", 3, 0.83);
    bool optimized = service.optimizeOrderQuantity();
    EXPECT_FALSE(optimized);
}

TEST(MaterialOrderingServiceTest, GetServiceId) {
    MaterialOrderingService service("ORDER003", 100, 0.89);
    EXPECT_EQ(service.getId(), "ORDER003");
}
