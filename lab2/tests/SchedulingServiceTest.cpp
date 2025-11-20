#include <gtest/gtest.h>
#include "SchedulingService.h"

TEST(SchedulingServiceTest, CalculateScheduleEfficiencySimple) {
    SchedulingService service("SIMPLE001", 15, 0.92);
    double efficiency = service.calculateScheduleEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(SchedulingServiceTest, CalculateScheduleEfficiencyComplex) {
    SchedulingService service("COMPLEX001", 45, 0.78);
    double efficiency = service.calculateScheduleEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(SchedulingServiceTest, CalculateScheduleEfficiencyHighVolume) {
    SchedulingService service("VOLUME001", 150, 0.72);
    double efficiency = service.calculateScheduleEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(SchedulingServiceTest, OptimizeResourceAllocationGood) {
    SchedulingService service("AUTOMATED001", 60, 0.85);
    bool optimized = service.optimizeResourceAllocation();
    EXPECT_TRUE(optimized);
}

TEST(SchedulingServiceTest, OptimizeResourceAllocationPoor) {
    SchedulingService service("MANUAL001", 120, 0.65);
    bool optimized = service.optimizeResourceAllocation();
    EXPECT_FALSE(optimized);
}

TEST(SchedulingServiceTest, GetServiceId) {
    SchedulingService service("SCHED001", 30, 0.88);
    EXPECT_EQ(service.getId(), "SCHED001");
}
