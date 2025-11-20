#ifndef CLIENTMANAGEMENTSERVICE_H
#define CLIENTMANAGEMENTSERVICE_H

#include <string>

class ClientManagementService {
private:
    std::string serviceId;
    int managedClients;
    double satisfactionRate;
    
public:
    ClientManagementService(const std::string& id, int clients, double satisfaction);
    
    double calculateClientRetention() const;
    bool identifyAtRiskClients() const;
    
    std::string getId() const { return serviceId; }
};

#endif
