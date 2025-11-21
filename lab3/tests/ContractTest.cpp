#include <gtest/gtest.h>
#include "models/Contract.h"
#include "models/Client.h"
#include "core/ConstructionCompany.h"
#include "core/ConstructionProject.h"

TEST(ContractTest, CalculatePenaltyForShortDelay) {
    Contract contract("CT001", "CL001", 500000, 12);
    double penalty = contract.calculatePenaltyForDelay(5);
    EXPECT_NEAR(penalty, 50000.0, 0.01);
}

TEST(ContractTest, CalculatePenaltyForLongDelay) {
    Contract contract("CT002", "CL002", 1000000, 24);
    double penalty = contract.calculatePenaltyForDelay(40);
    EXPECT_GT(penalty, 800000.0);
}

TEST(ContractTest, IsRenewableLongTerm) {
    Contract contract("CT004", "CL004", 1000000, 30);
    bool renewable = contract.isRenewable();
    EXPECT_TRUE(renewable);
}

TEST(ContractTest, IsNotRenewableShortTerm) {
    Contract contract("CT005", "CL005", 40000, 12);
    bool renewable = contract.isRenewable();
    EXPECT_FALSE(renewable);
}

TEST(ContractTest, CalculateProfitMargin) {
    Contract contract("CT006", "CL006", 750000, 18);
    double margin = contract.calculateProfitMargin();
    EXPECT_GT(margin, 0.0);
}

TEST(ContractTest, HasBreachOfContract) {
    Contract contract("CT007", "CL007", 500000, 12);
    ConstructionProject project("P1", "Test Project", 500000, 18);
    
    contract.setProject(&project);
    bool breach = contract.hasBreachOfContract();
    EXPECT_TRUE(breach);
}

TEST(ContractTest, SetAndGetClient) {
    Contract contract("CT008", "CL008", 600000, 15);
    Client client("CL1", "Test Client", 600000);
    
    contract.setClient(&client);
    EXPECT_EQ(contract.getClient()->getId(), "CL1");
}

TEST(ContractTest, SetAndGetCompany) {
    Contract contract("CT009", "CL009", 800000, 20);
    ConstructionCompany company("Test Corp", "CONST123", 2020);
    
    contract.setCompany(&company);
    EXPECT_EQ(contract.getCompany()->getName(), "Test Corp");
}

TEST(ContractTest, SetAndGetProject) {
    Contract contract("CT010", "CL010", 900000, 24);
    ConstructionProject project("P1", "Test Project", 900000, 24);
    
    contract.setProject(&project);
    EXPECT_EQ(contract.getProject()->getId(), "P1");
}
