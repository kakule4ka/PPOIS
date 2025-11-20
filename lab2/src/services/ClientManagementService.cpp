#include "ClientManagementService.h"

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
