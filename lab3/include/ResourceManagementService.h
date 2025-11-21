#ifndef RESOURCEMANAGEMENTSERVICE_H
#define RESOURCEMANAGEMENTSERVICE_H

#include <string>
#include <vector>

class Hospital;

class ResourceManagementService {
private:
    std::string serviceId;
    std::vector<Hospital*> managedHospitals;

public:
    ResourceManagementService(const std::string& serviceId);
    
    double calculateResourceUtilization() const;
    bool optimizeResourceAllocation() const;
    int getManagedHospitalCount() const;
    
    void addManagedHospital(Hospital* hospital);
    void removeManagedHospital(const std::string& hospitalId);
    std::vector<Hospital*> getManagedHospitals() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
