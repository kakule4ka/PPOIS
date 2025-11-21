#include <gtest/gtest.h>
#include "models/Supplier.h"
#include "models/BuildingMaterial.h"
#include "core/ConstructionProject.h"

TEST(SupplierTest, CalculateDeliveryRiskLow) {
    Supplier supplier("SUP001", "Material Corp", "Concrete", 0.85);
    double risk = supplier.calculateDeliveryRisk();
    EXPECT_NEAR(risk, 15.0, 0.01);
}

TEST(SupplierTest, CalculateDeliveryRiskHigh) {
    Supplier supplier("SUP002", "Unreliable Supplies", "Steel", 0.65);
    double risk = supplier.calculateDeliveryRisk();
    EXPECT_NEAR(risk, 35.0, 0.01);
}

TEST(SupplierTest, CanHandleUrgentOrderReliable) {
    Supplier supplier("SUP003", "Fast Supplies", "Steel", 0.90);
    bool canHandle = supplier.canHandleUrgentOrder();
    EXPECT_TRUE(canHandle);
}

TEST(SupplierTest, CalculateSupplierRating) {
    Supplier supplier("SUP004", "Quality Supplier", "Wood", 0.88);
    double rating = supplier.calculateSupplierRating();
    EXPECT_GT(rating, 0.0);
}

TEST(SupplierTest, IsPreferredSupplier) {
    Supplier supplier("SUP005", "Premium Supplier", "Steel", 0.92);
    bool preferred = supplier.isPreferredSupplier();
    EXPECT_FALSE(preferred);
}

TEST(SupplierTest, AddAndGetSuppliedMaterials) {
    Supplier supplier("SUP006", "Material Supplier", "Concrete", 0.85);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Cement", 50, 30);
    
    supplier.addSuppliedMaterial(&material1);
    supplier.addSuppliedMaterial(&material2);
    
    auto materials = supplier.getSuppliedMaterials();
    EXPECT_EQ(materials.size(), 2);
}

TEST(SupplierTest, AddAndGetServedProjects) {
    Supplier supplier("SUP007", "Project Supplier", "Steel", 0.88);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    supplier.addServedProject(&project1);
    supplier.addServedProject(&project2);
    
    auto projects = supplier.getServedProjects();
    EXPECT_EQ(projects.size(), 2);
}
