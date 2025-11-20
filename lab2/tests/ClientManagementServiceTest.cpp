#include <gtest/gtest.h>
#include "ClientManagementService.h"

TEST(ClientManagementServiceTest, CalculateClientRetentionHigh) {
    ClientManagementService service("PREMIUM001", 25, 0.94);
    double retention = service.calculateClientRetention();
    EXPECT_GT(retention, 90.0);
}

TEST(ClientManagementServiceTest, CalculateClientRetentionLow) {
    ClientManagementService service("BASIC001", 60, 0.68);
    double retention = service.calculateClientRetention();
    EXPECT_LT(retention, 75.0);
}

TEST(ClientManagementServiceTest, CalculateClientRetentionManyClients) {
    ClientManagementService service("SERVICE001", 80, 0.79);
    double retention = service.calculateClientRetention();
    EXPECT_GT(retention, 0);
}

TEST(ClientManagementServiceTest, IdentifyAtRiskClientsYes) {
    ClientManagementService service("ANALYTICS001", 45, 0.65);
    bool atRisk = service.identifyAtRiskClients();
    EXPECT_TRUE(atRisk);
}

TEST(ClientManagementServiceTest, IdentifyAtRiskClientsNo) {
    ClientManagementService service("STANDARD001", 30, 0.85);
    bool atRisk = service.identifyAtRiskClients();
    EXPECT_FALSE(atRisk);
}

TEST(ClientManagementServiceTest, GetServiceId) {
    ClientManagementService service("CLIENT001", 35, 0.88);
    EXPECT_EQ(service.getId(), "CLIENT001");
}
