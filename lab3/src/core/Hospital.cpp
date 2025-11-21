#include "Hospital.h"
#include "MedicalDepartment.h"
#include "Patient.h"
#include <algorithm>
#include <cmath>

Hospital::Hospital(const std::string& name, const std::string& address, int capacity, int year, double budget)
    : name(name), address(address), capacity(capacity), establishedYear(year), budget(budget) {}

double Hospital::calculateBedOccupancyRate() const {
    if (capacity == 0) return 0.0;
    
    int occupiedBeds = currentPatients.size();
    double occupancyRate = (static_cast<double>(occupiedBeds) / capacity) * 100.0;
    
    double seasonalFactor = 1.0;
    if (establishedYear < 2000) {
        seasonalFactor = 1.1;
    }
    
    return std::min(occupancyRate * seasonalFactor, 100.0);
}

bool Hospital::canHandleEmergency(int emergencySeverity) const {
    double availableCapacity = 1.0 - (calculateBedOccupancyRate() / 100.0);
    int specializedDepartments = 0;
    
    for (const auto& department : departments) {
        if (department->canHandleEmergency()) {
            specializedDepartments++;
        }
    }
    
    double resourceScore = availableCapacity * 0.6 + (specializedDepartments > 0 ? 0.4 : 0.0);
    double requiredScore = emergencySeverity * 0.2;
    
    return resourceScore >= requiredScore && availableCapacity >= 0.1;
}

double Hospital::calculateResourceUtilization() const {
    double bedUtilization = calculateBedOccupancyRate() * 0.4;
    
    double departmentUtilization = 0.0;
    if (!departments.empty()) {
        int activeDepartments = 0;
        for (const auto& department : departments) {
            if (department->isOperational()) {
                activeDepartments++;
            }
        }
        departmentUtilization = (static_cast<double>(activeDepartments) / departments.size()) * 100.0 * 0.6;
    }
    
    return bedUtilization + departmentUtilization;
}

bool Hospital::needsExpansion() const {
    double occupancyRate = calculateBedOccupancyRate();
    double resourceUtilization = calculateResourceUtilization();
    bool isOldFacility = establishedYear < 1990;
    bool hasBudgetForExpansion = budget > 5000000.0;
    
    return occupancyRate > 85.0 && resourceUtilization > 90.0 && hasBudgetForExpansion;
}

double Hospital::calculatePatientSatisfactionScore() const {
    double baseScore = 70.0;
    
    double capacityFactor = (100.0 - calculateBedOccupancyRate()) * 0.2;
    double departmentCoverage = departments.size() * 2.0;
    double experienceBonus = (2024 - establishedYear) * 0.1;
    
    double totalScore = baseScore + capacityFactor + departmentCoverage + experienceBonus;
    return std::min(totalScore, 100.0);
}

void Hospital::addDepartment(MedicalDepartment* department) {
    if (department) {
        departments.push_back(department);
    }
}

void Hospital::removeDepartment(const std::string& departmentId) {
    departments.erase(
        std::remove_if(departments.begin(), departments.end(),
            [&departmentId](MedicalDepartment* department) {
                return department->getId() == departmentId;
            }),
        departments.end()
    );
}

std::vector<MedicalDepartment*> Hospital::getDepartments() const {
    return departments;
}

void Hospital::admitPatient(Patient* patient) {
    if (patient && currentPatients.size() < capacity) {
        currentPatients.push_back(patient);
    }
}

void Hospital::dischargePatient(const std::string& patientId) {
    currentPatients.erase(
        std::remove_if(currentPatients.begin(), currentPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        currentPatients.end()
    );
}

std::vector<Patient*> Hospital::getCurrentPatients() const {
    return currentPatients;
}
