#include <gtest/gtest.h>
#include "ResourceAllocation.h"

TEST(ResourceAllocationTest, CalculateUtilizationRateLabor) {
    ResourceAllocation allocation("ALLOC001", "LABOR001", "PROJ001", 50000);
    double utilization = allocation.calculateUtilizationRate();
    EXPECT_EQ(utilization, 50000);
}

TEST(ResourceAllocationTest, CalculateUtilizationRateEquipment) {
    ResourceAllocation allocation("ALLOC002", "EQUIP001", "PROJ002", 75000);
    double utilization = allocation.calculateUtilizationRate();
    EXPECT_EQ(utilization, 75000);
}

TEST(ResourceAllocationTest, IsOverAllocatedNormal) {
    ResourceAllocation allocation("ALLOC003", "MATERIAL001", "PROJ003", 30000);
    bool overAllocated = allocation.isOverAllocated();
    EXPECT_FALSE(overAllocated);
}

TEST(ResourceAllocationTest, IsOverAllocatedHighUtilization) {
    ResourceAllocation allocation("ALLOC004", "CRITICAL001", "PROJ004", 150000);
    bool overAllocated = allocation.isOverAllocated();
    EXPECT_TRUE(overAllocated);
}

TEST(ResourceAllocationTest, IsOverAllocatedBorderline) {
    ResourceAllocation allocation("ALLOC005", "RES001", "PROJ005", 100000);
    bool overAllocated = allocation.isOverAllocated();
    EXPECT_FALSE(overAllocated);
}

TEST(ResourceAllocationTest, GetAllocationId) {
    ResourceAllocation allocation("ALLOC006", "RES002", "PROJ006", 25000);
    EXPECT_EQ(allocation.getId(), "ALLOC006");
}
