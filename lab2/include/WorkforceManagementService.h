#ifndef WORKFORCEMANAGEMENTSERVICE_H
#define WORKFORCEMANAGEMENTSERVICE_H

#include <string>

class WorkforceManagementService {
private:
    std::string serviceId;
    int managedWorkers;
    double productivityRate;
    
public:
    WorkforceManagementService(const std::string& id, int workers, double productivity);
    
    double calculateLaborEfficiency() const;
    bool optimizeWorkforceAllocation() const;
    
    std::string getId() const { return serviceId; }
};

#endif
