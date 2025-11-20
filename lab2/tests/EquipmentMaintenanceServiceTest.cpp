#include <gtest/gtest.h>
#include "EquipmentMaintenanceService.h"

TEST(EquipmentMaintenanceServiceTest, CalculateMaintenanceCostLow) {
    EquipmentMaintenanceService service("MAINT001", 25, 0.96);
    double cost = service.calculateMaintenanceCost();
    EXPECT_LT(cost, 30000.0);
}

TEST(EquipmentMaintenanceServiceTest, CalculateMaintenanceCostHigh) {
    EquipmentMaintenanceService service("HEAVY001", 80, 0.82);
    double cost = service.calculateMaintenanceCost();
    EXPECT_GT(cost, 80000.0);
}

TEST(EquipmentMaintenanceServiceTest, CalculateMaintenanceCostManyEquipment) {
    EquipmentMaintenanceService service("LARGE001", 120, 0.85);
    double cost = service.calculateMaintenanceCost();
    EXPECT_GT(cost, 0);
}

TEST(EquipmentMaintenanceServiceTest, PredictEquipmentFailureYes) {
    EquipmentMaintenanceService service("PREDICTIVE001", 45, 0.85);
    bool failure = service.predictEquipmentFailure();
    EXPECT_TRUE(failure);
}

TEST(EquipmentMaintenanceServiceTest, PredictEquipmentFailureNo) {
    EquipmentMaintenanceService service("BASIC001", 15, 0.95);
    bool failure = service.predictEquipmentFailure();
    EXPECT_FALSE(failure);
}

TEST(EquipmentMaintenanceServiceTest, GetServiceId) {
    EquipmentMaintenanceService service("MAINT002", 35, 0.91);
    EXPECT_EQ(service.getId(), "MAINT002");
}
