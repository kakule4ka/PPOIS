#include <gtest/gtest.h>
#include "services/MaterialOrderingService.h"
#include "models/Supplier.h"

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


TEST(MaterialOrderingServiceTest, OptimizeOrderQuantityNo) {
    MaterialOrderingService service("MANUAL001", 3, 0.83);
    bool optimized = service.optimizeOrderQuantity();
    EXPECT_FALSE(optimized);
}

TEST(MaterialOrderingServiceTest, AddAndGetApprovedSuppliers) {
    MaterialOrderingService service("ORDER003", 100, 0.89);
    Supplier supplier1("SUP1", "Concrete Co", "Concrete", 0.85);
    Supplier supplier2("SUP2", "Steel Corp", "Steel", 0.92);
    
    service.addSupplier(&supplier1);
    service.addSupplier(&supplier2);
    
    auto suppliers = service.getApprovedSuppliers();
    EXPECT_EQ(suppliers.size(), 2);
}

TEST(MaterialOrderingServiceTest, GetServiceId) {
    MaterialOrderingService service("ORDER004", 100, 0.89);
    EXPECT_EQ(service.getId(), "ORDER004");
}
