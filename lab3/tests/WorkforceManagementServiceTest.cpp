#include <gtest/gtest.h>
#include "services/WorkforceManagementService.h"

TEST(WorkforceManagementServiceTest, CalculateLaborEfficiencyHigh) {
    WorkforceManagementService service("SKILLED001", 65, 0.88);
    double efficiency = service.calculateLaborEfficiency();
    EXPECT_GT(efficiency, 85.0);
}

TEST(WorkforceManagementServiceTest, CalculateLaborEfficiencyLow) {
    WorkforceManagementService service("GENERAL001", 120, 0.65);
    double efficiency = service.calculateLaborEfficiency();
    EXPECT_LT(efficiency, 70.0);
}

TEST(WorkforceManagementServiceTest, CalculateLaborEfficiencyLargeWorkforce) {
    WorkforceManagementService service("LARGE001", 200, 0.78);
    double efficiency = service.calculateLaborEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(WorkforceManagementServiceTest, OptimizeWorkforceAllocationYes) {
    WorkforceManagementService service("SCHEDULING001", 45, 0.85);
    bool optimized = service.optimizeWorkforceAllocation();
    EXPECT_TRUE(optimized);
}

TEST(WorkforceManagementServiceTest, OptimizeWorkforceAllocationNo) {
    WorkforceManagementService service("MANUAL001", 180, 0.72);
    bool optimized = service.optimizeWorkforceAllocation();
    EXPECT_FALSE(optimized);
}

TEST(WorkforceManagementServiceTest, GetServiceId) {
    WorkforceManagementService service("WORK001", 85, 0.82);
    EXPECT_EQ(service.getId(), "WORK001");
}
