#include <gtest/gtest.h>
#include "Client.h"

TEST(ClientTest, ValidateProjectBudgetWithinBudget) {
    Client client("C001", "ABC Corporation", 500000);
    bool valid = client.validateProjectBudget(450000);
    EXPECT_TRUE(valid);
}

TEST(ClientTest, ValidateProjectBudgetWithBuffer) {
    Client client("C002", "XYZ Ltd", 300000);
    bool valid = client.validateProjectBudget(330000);
    EXPECT_TRUE(valid);
}

TEST(ClientTest, ExceedProjectBudget) {
    Client client("C003", "Small Business", 100000);
    bool valid = client.validateProjectBudget(120000);
    EXPECT_FALSE(valid);
}

TEST(ClientTest, CalculatePaymentPlanMonthly) {
    Client client("C004", "Global Enterprises", 1000000);
    double monthly = client.calculatePaymentPlan(12);
    EXPECT_NEAR(monthly, 83333.33, 0.01);
}

TEST(ClientTest, CalculatePaymentPlanQuarterly) {
    Client client("C005", "Regional Corp", 600000);
    double quarterly = client.calculatePaymentPlan(4);
    EXPECT_NEAR(quarterly, 150000.0, 0.01);
}

TEST(ClientTest, GetClientId) {
    Client client("C006", "Local Business", 250000);
    EXPECT_EQ(client.getId(), "C006");
}
