#ifndef CLIENTMANAGEMENTSERVICE_H
#define CLIENTMANAGEMENTSERVICE_H

#include <string>
#include <vector>

class Client;
class Contract;

class ClientManagementService {
private:
    std::string serviceId;
    int managedClients;
    double satisfactionRate;
    std::vector<Client*> clients;
    std::vector<Contract*> clientContracts;
    
public:
    ClientManagementService(const std::string& id, int clients, double satisfaction);
    
    double calculateClientRetention() const;
    bool identifyAtRiskClients() const;
    double calculateServiceEffectiveness() const;
    bool needsClientOutreach() const;
    
    void addClient(Client* client);
    void removeClient(const std::string& clientId);
    std::vector<Client*> getClients() const;
    
    void addClientContract(Contract* contract);
    void removeClientContract(const std::string& contractId);
    std::vector<Contract*> getClientContracts() const;
    
    std::string getId() const { return serviceId; }
};

#endif
