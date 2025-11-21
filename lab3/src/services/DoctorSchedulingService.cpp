#include "DoctorSchedulingService.h"
#include "Doctor.h"
#include <algorithm>

DoctorSchedulingService::DoctorSchedulingService(const std::string& serviceId)
    : serviceId(serviceId) {}

double DoctorSchedulingService::calculateScheduleEfficiency() const {
    if (managedDoctors.empty()) return 0.0;
    
    double totalEfficiency = 0.0;
    int availableForEmergency = 0;
    
    for (const auto& doctor : managedDoctors) {
        totalEfficiency += doctor->calculateWorkloadEfficiency();
        if (doctor->isAvailableForEmergency()) {
            availableForEmergency++;
        }
    }
    
    double avgEfficiency = totalEfficiency / managedDoctors.size();
    double emergencyCoverage = (static_cast<double>(availableForEmergency) / managedDoctors.size()) * 30.0;
    
    return std::min(avgEfficiency + emergencyCoverage, 100.0);
}

bool DoctorSchedulingService::assignEmergencyCoverage() const {
    if (managedDoctors.empty()) return false;
    
    int emergencyDoctors = 0;
    for (const auto& doctor : managedDoctors) {
        if (doctor->isAvailableForEmergency()) {
            emergencyDoctors++;
        }
    }
    
    return emergencyDoctors >= 2;
}

bool DoctorSchedulingService::validateWorkloadDistribution() const {
    if (managedDoctors.empty()) return false;
    
    int overloadedDoctors = 0;
    for (const auto& doctor : managedDoctors) {
        if (doctor->calculateWorkloadEfficiency() < 50.0) {
            overloadedDoctors++;
        }
    }
    
    double overloadRate = static_cast<double>(overloadedDoctors) / managedDoctors.size();
    return overloadRate < 0.3;
}

void DoctorSchedulingService::addManagedDoctor(Doctor* doctor) {
    if (doctor) {
        managedDoctors.push_back(doctor);
    }
}

void DoctorSchedulingService::removeManagedDoctor(const std::string& doctorId) {
    managedDoctors.erase(
        std::remove_if(managedDoctors.begin(), managedDoctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        managedDoctors.end()
    );
}

std::vector<Doctor*> DoctorSchedulingService::getManagedDoctors() const {
    return managedDoctors;
}
