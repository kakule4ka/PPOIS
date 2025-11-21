#include <gtest/gtest.h>
#include "Equipment.h"
#include "ConstructionProject.h"
#include "Employee.h"

TEST(EquipmentTest, CalculateDepreciation) {
    Equipment equipment("EQ001", "Excavator", 5000);
    double depreciation = equipment.calculateDepreciation();
    EXPECT_EQ(depreciation, 500);
}

TEST(EquipmentTest, NeedsMaintenanceHighUsage) {
    Equipment equipment("EQ003", "Bulldozer", 8000);
    equipment.setHoursUsed(1500);
    bool needsMaintenance = equipment.needsMaintenance();
    EXPECT_TRUE(needsMaintenance);
}

TEST(EquipmentTest, CalculateUtilizationRate) {
    Equipment equipment("EQ004", "Crane", 10000);
    equipment.setHoursUsed(800);
    double utilization = equipment.calculateUtilizationRate();
    EXPECT_GT(utilization, 0.0);
}

TEST(EquipmentTest, IsAvailableForProject) {
    Equipment equipment("EQ005", "Generator", 500);
    equipment.setHoursUsed(500);
    bool available = equipment.isAvailableForProject();
    EXPECT_TRUE(available);
}

TEST(EquipmentTest, SetAndGetCurrentProject) {
    Equipment equipment("EQ006", "Compactor", 3500);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    equipment.setCurrentProject(&project);
    EXPECT_EQ(equipment.getCurrentProject()->getId(), "P1");
}

TEST(EquipmentTest, AssignAndGetOperator) {
    Equipment equipment("EQ007", "Excavator", 6000);
    Employee emp("E1", "John", "Operator", 55000);  // Переименовано с operator на emp
    
    equipment.assignOperator(&emp);
    EXPECT_EQ(equipment.getAssignedOperator()->getId(), "E1");
}
