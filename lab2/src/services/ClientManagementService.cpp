#include "ClientManagementService.h"
#include "Client.h"
#include "Contract.h"
#include <algorithm>

ClientManagementService::ClientManagementService(const std::string& id, int clients, double satisfaction)
    : serviceId(id), managedClients(clients), satisfactionRate(satisfaction) {}

double ClientManagementService::calculateClientRetention() const {
    double baseRetention = satisfactionRate * 100.0;
    
    double clientLoadFactor = 1.0;
    if (managedClients > 50) {
        clientLoadFactor = 0.9;
    } else if (managedClients > 25) {
        clientLoadFactor = 0.95;
    } else if (managedClients < 10) {
        clientLoadFactor = 1.05;
    }
    
    double serviceLevelFactor = 1.0;
    if (serviceId.find("PREMIUM") != std::string::npos) {
        serviceLevelFactor = 1.1;
    } else if (serviceId.find("STANDARD") != std::string::npos) {
        serviceLevelFactor = 1.0;
    } else if (serviceId.find("BASIC") != std::string::npos) {
        serviceLevelFactor = 0.95;
    }
    
    double communicationFactor = 1.05;
    double supportFactor = 1.03;
    
    double totalRetention = baseRetention * clientLoadFactor * serviceLevelFactor * communicationFactor * supportFactor;
    
    return totalRetention > 100.0 ? 100.0 : totalRetention;
}

bool ClientManagementService::identifyAtRiskClients() const {
    return satisfactionRate < 0.7 || managedClients > 40;
}

double ClientManagementService::calculateServiceEffectiveness() const {
    double baseEffectiveness = 70.0;
    
    double clientEffectiveness = managedClients * 0.5;
    double satisfactionEffectiveness = satisfactionRate * 25.0;
    double contractEffectiveness = clientContracts.size() * 1.0;
    double clientManagementEffectiveness = clients.size() * 0.8;
    
    double totalEffectiveness = baseEffectiveness + clientEffectiveness + 
                              satisfactionEffectiveness + contractEffectiveness + 
                              clientManagementEffectiveness;
    
    return totalEffectiveness > 100.0 ? 100.0 : totalEffectiveness;
}

bool ClientManagementService::needsClientOutreach() const {
    double effectiveness = calculateServiceEffectiveness();
    bool hasLowEffectiveness = effectiveness < 75.0;
    bool hasAtRiskClients = identifyAtRiskClients();
    bool hasFewClients = clients.size() < 5;
    bool hasLimitedContracts = clientContracts.size() < 3;
    bool hasLowSatisfaction = satisfactionRate < 0.75;
    
    return hasLowEffectiveness || hasAtRiskClients || hasFewClients || 
           hasLimitedContracts || hasLowSatisfaction;
}

void ClientManagementService::addClient(Client* client) {
    if (client) {
        clients.push_back(client);
    }
}

void ClientManagementService::removeClient(const std::string& clientId) {
    clients.erase(
        std::remove_if(clients.begin(), clients.end(),
            [&clientId](Client* client) {
                return client->getId() == clientId;
            }),
        clients.end()
    );
}

std::vector<Client*> ClientManagementService::getClients() const {
    return clients;
}

void ClientManagementService::addClientContract(Contract* contract) {
    if (contract) {
        clientContracts.push_back(contract);
    }
}

void ClientManagementService::removeClientContract(const std::string& contractId) {
    clientContracts.erase(
        std::remove_if(clientContracts.begin(), clientContracts.end(),
            [&contractId](Contract* contract) {
                return contract->getId() == contractId;
            }),
        clientContracts.end()
    );
}

std::vector<Contract*> ClientManagementService::getClientContracts() const {
    return clientContracts;
}
