#include <gtest/gtest.h>
#include "Supplier.h"

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

TEST(SupplierTest, CannotHandleUrgentOrderConcrete) {
    Supplier supplier("SUP004", "Concrete Experts", "Concrete", 0.95);
    bool canHandle = supplier.canHandleUrgentOrder();
    EXPECT_FALSE(canHandle);
}

TEST(SupplierTest, CannotHandleUrgentOrderUnreliable) {
    Supplier supplier("SUP005", "Slow Materials", "Wood", 0.75);
    bool canHandle = supplier.canHandleUrgentOrder();
    EXPECT_FALSE(canHandle);
}

TEST(SupplierTest, GetSupplierId) {
    Supplier supplier("SUP006", "Quality Materials", "Bricks", 0.88);
    EXPECT_EQ(supplier.getId(), "SUP006");
}
