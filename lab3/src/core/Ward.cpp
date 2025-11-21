#include "Ward.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalDepartment.h"
#include <algorithm>
#include <cmath>

Ward::Ward(const std::string& id, const std::string& name, const std::string& type, int capacity)
    : id(id), name(name), type(type), capacity(capacity), currentOccupancy(0), cleanlinessScore(90.0), department(nullptr) {}

double Ward::calculateOccupancyRate() const {
    if (capacity == 0) return 0.0;
    return (static_cast<double>(currentOccupancy) / capacity) * 100.0;
}

bool Ward::canAdmitPatient() const {
    double occupancyRate = calculateOccupancyRate();
    bool hasCapacity = currentOccupancy < capacity;
    bool hasNurseCoverage = !assignedNurses.empty();
    bool meetsCleanlinessStandards = cleanlinessScore >= 85.0;
    bool isAppropriateType = type != "Isolation" || cleanlinessScore >= 95.0;
    
    return hasCapacity && hasNurseCoverage && meetsCleanlinessStandards && isAppropriateType && occupancyRate < 95.0;
}

double Ward::calculateCareQualityScore() const {
    double baseScore = 70.0;
    
    double occupancyScore = (100.0 - calculateOccupancyRate()) * 0.3;
    double nursePatientRatio = assignedNurses.empty() ? 0.0 : (static_cast<double>(assignedNurses.size()) / currentOccupancy) * 20.0;
    double cleanlinessScore = this->cleanlinessScore * 0.4;
    
    double patientOutcomeBonus = 0.0;
    for (const auto& patient : patients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientOutcomeBonus += 2.0;
        }
    }
    
    double departmentBonus = department ? 5.0 : 0.0;
    double typeBonus = type == "ICU" ? 10.0 : (type == "Private" ? 5.0 : 0.0);
    
    double totalScore = baseScore + occupancyScore + nursePatientRatio + cleanlinessScore + patientOutcomeBonus + departmentBonus + typeBonus;
    return std::min(totalScore, 100.0);
}

void Ward::addPatient(Patient* patient) {
    if (patient && currentOccupancy < capacity) {
        patients.push_back(patient);
        currentOccupancy++;
    }
}

void Ward::removePatient(const std::string& patientId) {
    patients.erase(
        std::remove_if(patients.begin(), patients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        patients.end()
    );
    currentOccupancy = patients.size();
}

std::vector<Patient*> Ward::getPatients() const {
    return patients;
}

void Ward::addNurse(Nurse* nurse) {
    if (nurse) {
        assignedNurses.push_back(nurse);
    }
}

void Ward::removeNurse(const std::string& nurseId) {
    assignedNurses.erase(
        std::remove_if(assignedNurses.begin(), assignedNurses.end(),
            [&nurseId](Nurse* nurse) {
                return nurse->getId() == nurseId;
            }),
        assignedNurses.end()
    );
}

std::vector<Nurse*> Ward::getAssignedNurses() const {
    return assignedNurses;
}

void Ward::setDepartment(MedicalDepartment* department) {
    this->department = department;
}

MedicalDepartment* Ward::getDepartment() const {
    return department;
}
