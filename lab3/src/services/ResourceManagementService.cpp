#include "ResourceManagementService.h"
#include "Hospital.h"
#include <algorithm>

ResourceManagementService::ResourceManagementService(const std::string& serviceId)
    : serviceId(serviceId) {}

double ResourceManagementService::calculateResourceUtilization() const {
    if (managedHospitals.empty()) return 0.0;
    
    double totalUtilization = 0.0;
    int efficientHospitals = 0;
    
    for (const auto& hospital : managedHospitals) {
        double utilization = hospital->calculateResourceUtilization();
        totalUtilization += utilization;
        
        if (utilization >= 70.0 && utilization <= 90.0) {
            efficientHospitals++;
        }
    }
    
    double avgUtilization = totalUtilization / managedHospitals.size();
    double efficiencyBonus = (static_cast<double>(efficientHospitals) / managedHospitals.size()) * 20.0;
    
    return std::min(avgUtilization + efficiencyBonus, 100.0);
}

bool ResourceManagementService::optimizeResourceAllocation() const {
    if (managedHospitals.empty()) return false;
    
    int needsExpansion = 0;
    for (const auto& hospital : managedHospitals) {
        if (hospital->needsExpansion()) {
            needsExpansion++;
        }
    }
    
    double expansionRate = static_cast<double>(needsExpansion) / managedHospitals.size();
    return expansionRate <= 0.3;
}

int ResourceManagementService::getManagedHospitalCount() const {
    return managedHospitals.size();
}

void ResourceManagementService::addManagedHospital(Hospital* hospital) {
    if (hospital) {
        managedHospitals.push_back(hospital);
    }
}

void ResourceManagementService::removeManagedHospital(const std::string& hospitalId) {
    managedHospitals.erase(
        std::remove_if(managedHospitals.begin(), managedHospitals.end(),
            [&hospitalId](Hospital* hospital) {
                return hospital->getName() == hospitalId;
            }),
        managedHospitals.end()
    );
}

std::vector<Hospital*> ResourceManagementService::getManagedHospitals() const {
    return managedHospitals;
}
