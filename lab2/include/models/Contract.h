#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <vector>

class Client;
class ConstructionCompany;
class ConstructionProject;

class Contract {
private:
    std::string contractId;
    std::string clientId;
    double contractValue;
    int duration;
    Client* client;
    ConstructionCompany* company;
    ConstructionProject* project;
    
public:
    Contract(const std::string& id, const std::string& clientId, double value, int duration);
    
    double calculatePenaltyForDelay(int delayDays) const;
    bool isRenewable() const;
    double calculateProfitMargin() const;
    bool hasBreachOfContract() const;
    
    void setClient(Client* client);
    Client* getClient() const;
    
    void setCompany(ConstructionCompany* company);
    ConstructionCompany* getCompany() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    std::string getId() const { return contractId; }
    double getContractValue() const { return contractValue; }
};

#endif
