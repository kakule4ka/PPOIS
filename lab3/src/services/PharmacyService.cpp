#include "PharmacyService.h"
#include "Pharmacy.h"
#include <algorithm>

PharmacyService::PharmacyService(const std::string& serviceId)
    : serviceId(serviceId) {}

double PharmacyService::calculateServiceEfficiency() const {
    if (managedPharmacies.empty()) return 0.0;
    
    double totalEfficiency = 0.0;
    int specializedPharmacies = 0;
    
    for (const auto& pharmacy : managedPharmacies) {
        double efficiency = pharmacy->calculateServiceEfficiency();
        totalEfficiency += efficiency;
        
        if (pharmacy->canDispenseSpecializedMeds()) {
            specializedPharmacies++;
        }
    }
    
    double avgEfficiency = totalEfficiency / managedPharmacies.size();
    double specializedBonus = (static_cast<double>(specializedPharmacies) / managedPharmacies.size()) * 25.0;
    
    return std::min(avgEfficiency + specializedBonus, 100.0);
}

bool PharmacyService::validateInventoryManagement() const {
    if (managedPharmacies.empty()) return false;
    
    int wellManaged = 0;
    for (const auto& pharmacy : managedPharmacies) {
        if (pharmacy->calculateInventoryTurnover() >= 60.0) {
            wellManaged++;
        }
    }
    
    double managementRate = static_cast<double>(wellManaged) / managedPharmacies.size();
    return managementRate >= 0.8;
}

int PharmacyService::getTotalPharmacyCount() const {
    return managedPharmacies.size();
}

void PharmacyService::addManagedPharmacy(Pharmacy* pharmacy) {
    if (pharmacy) {
        managedPharmacies.push_back(pharmacy);
    }
}

void PharmacyService::removeManagedPharmacy(const std::string& pharmacyId) {
    managedPharmacies.erase(
        std::remove_if(managedPharmacies.begin(), managedPharmacies.end(),
            [&pharmacyId](Pharmacy* pharmacy) {
                return pharmacy->getId() == pharmacyId;
            }),
        managedPharmacies.end()
    );
}

std::vector<Pharmacy*> PharmacyService::getManagedPharmacies() const {
    return managedPharmacies;
}
