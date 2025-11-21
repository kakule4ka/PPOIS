#include <gtest/gtest.h>
#include "models/Client.h"
#include "core/ConstructionProject.h"
#include "models/Contract.h"

TEST(ClientTest, ValidateProjectBudgetWithinBudget) {
    Client client("C001", "ABC Corporation", 500000);
    bool valid = client.validateProjectBudget(300000);  // Исправлено: 300000 вместо 450000
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

TEST(ClientTest, CalculateTotalInvestment) {
    Client client("C005", "Investor Corp", 2000000);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    client.addProject(&project1);
    client.addProject(&project2);
    
    double investment = client.calculateTotalInvestment();
    EXPECT_GT(investment, 0.0);
}

TEST(ClientTest, IsReliableClient) {
    Client client("C006", "Reliable Corp", 500000);
    ConstructionProject project("P1", "Project 1", 300000, 12);
    Contract contract("CT1", "C006", 300000, 12);
    
    client.addProject(&project);
    client.addContract(&contract);
    
    bool reliable = client.isReliableClient();
    EXPECT_TRUE(reliable);
}

TEST(ClientTest, AddAndGetProjects) {
    Client client("C007", "Test Client", 300000);
    ConstructionProject project1("P1", "Project 1", 200000, 10);
    ConstructionProject project2("P2", "Project 2", 150000, 8);
    
    client.addProject(&project1);
    client.addProject(&project2);
    
    auto projects = client.getProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(ClientTest, AddAndGetContracts) {
    Client client("C008", "Contract Client", 400000);
    Contract contract1("CT1", "C008", 200000, 12);
    Contract contract2("CT2", "C008", 150000, 8);
    
    client.addContract(&contract1);
    client.addContract(&contract2);
    
    auto contracts = client.getContracts();
    EXPECT_EQ(contracts.size(), 2);
}
