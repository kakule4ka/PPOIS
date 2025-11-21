#ifndef PHARMACYSERVICE_H
#define PHARMACYSERVICE_H

#include <string>
#include <vector>

class Pharmacy;

class PharmacyService {
private:
    std::string serviceId;
    std::vector<Pharmacy*> managedPharmacies;

public:
    PharmacyService(const std::string& serviceId);
    
    double calculateServiceEfficiency() const;
    bool validateInventoryManagement() const;
    int getTotalPharmacyCount() const;
    
    void addManagedPharmacy(Pharmacy* pharmacy);
    void removeManagedPharmacy(const std::string& pharmacyId);
    std::vector<Pharmacy*> getManagedPharmacies() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
