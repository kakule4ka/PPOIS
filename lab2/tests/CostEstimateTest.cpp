#include <gtest/gtest.h>
#include "CostEstimate.h"

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

TEST(CostEstimateTest, CalculateVarianceNegative) {
    CostEstimate estimate("EST003", "PROJ003", 60000, 40000);
    double variance = estimate.calculateVariance(95000);
    EXPECT_EQ(variance, -5000);
}

TEST(CostEstimateTest, CalculateVarianceZero) {
    CostEstimate estimate("EST004", "PROJ004", 30000, 20000);
    double variance = estimate.calculateVariance(50000);
    EXPECT_EQ(variance, 0);
}

TEST(CostEstimateTest, GetEstimateId) {
    CostEstimate estimate("EST005", "PROJ005", 70000, 50000);
    EXPECT_EQ(estimate.getId(), "EST005");
}
