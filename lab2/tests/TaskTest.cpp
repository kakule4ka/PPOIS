#include <gtest/gtest.h>
#include "Task.h"
#include "Employee.h"
#include "BuildingMaterial.h"
#include "Equipment.h"

TEST(TaskTest, CalculateResourceCost) {
    Task task("TASK004", "Construction work", 80);
    BuildingMaterial material("MAT1", "Concrete", 100, 50);
    Equipment equipment("EQ1", "Crane", 5000);
    
    task.addRequiredMaterial(&material);
    task.addRequiredEquipment(&equipment);
    task.setActualHours(40);
    
    double cost = task.calculateResourceCost();
    EXPECT_GT(cost, 0.0);
}

TEST(TaskTest, IsResourceSufficient) {
    Task task("TASK005", "Building work", 40);
    BuildingMaterial material("MAT1", "Concrete", 50, 50);
    Equipment equipment("EQ1", "Crane", 5000);
    Employee employee("E1", "John", "Worker", 50000);
    
    task.addRequiredMaterial(&material);
    task.addRequiredEquipment(&equipment);
    task.assignEmployee(&employee);
    
    bool sufficient = task.isResourceSufficient();
    EXPECT_TRUE(sufficient);
}

TEST(TaskTest, AssignAndGetEmployee) {
    Task task("TASK006", "Test task", 20);
    Employee employee("E1", "John", "Worker", 50000);
    
    task.assignEmployee(&employee);
    EXPECT_EQ(task.getAssignedEmployee()->getId(), "E1");
}

TEST(TaskTest, AddAndGetMaterials) {
    Task task("TASK007", "Material task", 30);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Steel", 50, 80);
    
    task.addRequiredMaterial(&material1);
    task.addRequiredMaterial(&material2);
    
    auto materials = task.getRequiredMaterials();
    EXPECT_EQ(materials.size(), 2);
}

TEST(TaskTest, AddAndGetEquipment) {
    Task task("TASK008", "Equipment task", 25);
    Equipment equipment1("EQ1", "Crane", 5000);
    Equipment equipment2("EQ2", "Excavator", 8000);
    
    task.addRequiredEquipment(&equipment1);
    task.addRequiredEquipment(&equipment2);
    
    auto equipment = task.getRequiredEquipment();
    EXPECT_EQ(equipment.size(), 2);
}
