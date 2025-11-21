#include <gtest/gtest.h>
#include "ClientManagementService.h"
#include "Client.h"
#include "Contract.h"

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

TEST(ClientManagementServiceTest, IdentifyAtRiskClientsYes) {
    ClientManagementService service("ANALYTICS001", 45, 0.65);
    bool atRisk = service.identifyAtRiskClients();
    EXPECT_TRUE(atRisk);
}

TEST(ClientManagementServiceTest, CalculateServiceEffectiveness) {
    ClientManagementService service("SERVICE001", 35, 0.88);
    double effectiveness = service.calculateServiceEffectiveness();
    EXPECT_GT(effectiveness, 0.0);
}

TEST(ClientManagementServiceTest, NeedsClientOutreach) {
    ClientManagementService service("STANDARD001", 50, 0.70);
    bool needsOutreach = service.needsClientOutreach();
    EXPECT_TRUE(needsOutreach);
}

TEST(ClientManagementServiceTest, AddAndGetClients) {
    ClientManagementService service("CLIENT001", 30, 0.85);
    Client client1("C1", "Client 1", 500000);
    Client client2("C2", "Client 2", 300000);
    
    service.addClient(&client1);
    service.addClient(&client2);
    
    auto clients = service.getClients();
    EXPECT_EQ(clients.size(), 2);
}

TEST(ClientManagementServiceTest, AddAndGetClientContracts) {
    ClientManagementService service("CONTRACT001", 25, 0.82);
    Contract contract1("CT1", "C1", 200000, 12);
    Contract contract2("CT2", "C2", 150000, 8);
    
    service.addClientContract(&contract1);
    service.addClientContract(&contract2);
    
    auto contracts = service.getClientContracts();
    EXPECT_EQ(contracts.size(), 2);
}
