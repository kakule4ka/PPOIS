#include <gtest/gtest.h>
#include "services/EquipmentMaintenanceService.h"
#include "models/Equipment.h"
#include "core/ConstructionProject.h"

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

TEST(EquipmentMaintenanceServiceTest, PredictEquipmentFailureYes) {
    EquipmentMaintenanceService service("PREDICTIVE001", 45, 0.85);
    bool failure = service.predictEquipmentFailure();
    EXPECT_TRUE(failure);
}

TEST(EquipmentMaintenanceServiceTest, CalculateServiceReliability) {
    EquipmentMaintenanceService service("MAINT002", 35, 0.91);
    double reliability = service.calculateServiceReliability();
    EXPECT_GT(reliability, 0.0);
}


TEST(EquipmentMaintenanceServiceTest, AddAndGetEquipmentList) {
    EquipmentMaintenanceService service("MAINT003", 20, 0.92);
    Equipment equipment1("EQ1", "Crane", 5000);
    Equipment equipment2("EQ2", "Excavator", 8000);
    
    service.addEquipment(&equipment1);
    service.addEquipment(&equipment2);
    
    auto equipment = service.getEquipmentList();
    EXPECT_EQ(equipment.size(), 2);
}

TEST(EquipmentMaintenanceServiceTest, AddAndGetSupportedProjects) {
    EquipmentMaintenanceService service("MAINT004", 30, 0.89);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addSupportedProject(&project1);
    service.addSupportedProject(&project2);
    
    auto projects = service.getSupportedProjects();
    EXPECT_EQ(projects.size(), 2);
}
