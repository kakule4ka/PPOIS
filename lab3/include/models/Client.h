#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

class ConstructionProject;
class Contract;

class Client {
private:
    std::string id;
    std::string name;
    double budget;
    std::vector<ConstructionProject*> projects;
    std::vector<Contract*> contracts;
    
public:
    Client(const std::string& id, const std::string& name, double budget);
    
    bool validateProjectBudget(double cost) const;
    double calculatePaymentPlan(int months) const;
    double calculateTotalInvestment() const;
    bool isReliableClient() const;
    
    void addProject(ConstructionProject* project);
    void removeProject(const std::string& projectId);
    std::vector<ConstructionProject*> getProjects() const;
    
    void addContract(Contract* contract);
    void removeContract(const std::string& contractId);
    std::vector<Contract*> getContracts() const;
    
    std::string getId() const { return id; }
};

#endif
