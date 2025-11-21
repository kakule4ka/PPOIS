#include <gtest/gtest.h>
#include "ResourceAllocation.h"
#include "ConstructionProject.h"
#include "Employee.h"
#include "Equipment.h"

TEST(ResourceAllocationTest, CalculateUtilizationRateLabor) {
    ResourceAllocation allocation("ALLOC001", "LABOR001", "PROJ001", 50000);
    double utilization = allocation.calculateUtilizationRate();
    EXPECT_EQ(utilization, 50000);
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

TEST(ResourceAllocationTest, CalculateAllocationEfficiency) {
    ResourceAllocation allocation("ALLOC005", "RES001", "PROJ005", 25000);
    double efficiency = allocation.calculateAllocationEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ResourceAllocationTest, NeedsAdjustment) {
    ResourceAllocation allocation("ALLOC006", "RES002", "PROJ006", 200000);
    bool needsAdjust = allocation.needsAdjustment();
    EXPECT_TRUE(needsAdjust);
}

TEST(ResourceAllocationTest, SetAndGetProject) {
    ResourceAllocation allocation("ALLOC007", "RES003", "PROJ007", 35000);
    ConstructionProject project("P1", "Test Project", 500000, 12);
    
    allocation.setProject(&project);
    EXPECT_EQ(allocation.getProject()->getId(), "P1");
}

TEST(ResourceAllocationTest, SetAndGetAssignedEmployee) {
    ResourceAllocation allocation("ALLOC008", "RES004", "PROJ008", 40000);
    Employee employee("E1", "John", "Worker", 50000);
    
    allocation.setAssignedEmployee(&employee);
    EXPECT_EQ(allocation.getAssignedEmployee()->getId(), "E1");
}

TEST(ResourceAllocationTest, SetAndGetAssignedEquipment) {
    ResourceAllocation allocation("ALLOC009", "RES005", "PROJ009", 45000);
    Equipment equipment("EQ1", "Crane", 5000);
    
    allocation.setAssignedEquipment(&equipment);
    EXPECT_EQ(allocation.getAssignedEquipment()->getId(), "EQ1");
}
