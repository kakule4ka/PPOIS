#include <gtest/gtest.h>
#include "Contract.h"

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

TEST(ContractTest, CalculatePenaltyLargeContract) {
    Contract contract("CT003", "CL003", 2000000, 36);
    double penalty = contract.calculatePenaltyForDelay(10);
    EXPECT_LT(penalty, 400000.0);
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

TEST(ContractTest, GetContractId) {
    Contract contract("CT006", "CL006", 750000, 18);
    EXPECT_EQ(contract.getId(), "CT006");
}
