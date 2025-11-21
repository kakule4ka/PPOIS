#include <gtest/gtest.h>
#include "CostEstimate.h"
#include "ConstructionProject.h"
#include "BuildingMaterial.h"
#include "Equipment.h"

TEST(CostEstimateTest, CalculateTotalCost) {
    CostEstimate estimate("EST001", "PROJ001", 50000, 30000);
    double total = estimate.calculateTotalCost();
    EXPECT_EQ(total, 80000);
}

TEST(CostEstimateTest, CalculateVariancePositive) {
    CostEstimate estimate("EST002", "PROJ002", 40000, 25000);
    double variance = estimate.calculateVariance(70000);
    EXPECT_EQ(variance, 5000);
}

TEST(CostEstimateTest, CalculateAccuracy) {
    CostEstimate estimate("EST003", "PROJ003", 60000, 40000);
    double accuracy = estimate.calculateAccuracy();
    EXPECT_GT(accuracy, 0.0);
}

TEST(CostEstimateTest, IsEstimateRealistic) {
    CostEstimate estimate("EST004", "PROJ004", 30000, 20000);
    ConstructionProject project("P1", "Test Project", 50000, 10);
    BuildingMaterial material("MAT1", "Concrete", 100, 300);
    
    estimate.setProject(&project);
    estimate.addMaterial(&material);
    
    bool realistic = estimate.isEstimateRealistic();
    EXPECT_TRUE(realistic);
}

TEST(CostEstimateTest, SetAndGetProject) {
    CostEstimate estimate("EST005", "PROJ005", 70000, 50000);
    ConstructionProject project("P1", "Test Project", 120000, 15);
    
    estimate.setProject(&project);
    EXPECT_EQ(estimate.getProject()->getId(), "P1");
}

TEST(CostEstimateTest, AddAndGetMaterials) {
    CostEstimate estimate("EST006", "PROJ006", 40000, 30000);
    BuildingMaterial material1("MAT1", "Concrete", 100, 200);
    BuildingMaterial material2("MAT2", "Steel", 50, 400);
    
    estimate.addMaterial(&material1);
    estimate.addMaterial(&material2);
    
    auto materials = estimate.getMaterials();
    EXPECT_EQ(materials.size(), 2);
}

TEST(CostEstimateTest, AddAndGetEquipment) {
    CostEstimate estimate("EST007", "PROJ007", 50000, 35000);
    Equipment equipment1("EQ1", "Crane", 5000);
    Equipment equipment2("EQ2", "Excavator", 8000);
    
    estimate.addEquipment(&equipment1);
    estimate.addEquipment(&equipment2);
    
    auto equipment = estimate.getEquipment();
    EXPECT_EQ(equipment.size(), 2);
}
