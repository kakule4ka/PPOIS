#include "Nurse.h"
#include "Patient.h"
#include "MedicalDepartment.h"
#include <algorithm>
#include <cmath>

Nurse::Nurse(const std::string& id, const std::string& name, const std::string& qualification, int experience)
    : id(id), name(name), qualification(qualification), experienceYears(experience), shiftHours(8), maxPatients(6), department(nullptr) {}

double Nurse::calculateWorkload() const {
    if (maxPatients == 0) return 0.0;
    
    double patientLoad = static_cast<double>(assignedPatients.size()) / maxPatients;
    
    double complexityLoad = 0.0;
    for (const auto& patient : assignedPatients) {
        complexityLoad += patient->calculateHealthRiskScore() * 0.01;
    }
    
    double shiftLoad = shiftHours / 12.0;
    double experienceFactor = 1.0 - (experienceYears * 0.02);
    
    double totalWorkload = (patientLoad * 0.5 + complexityLoad * 0.3 + shiftLoad * 0.2) * 100.0 * experienceFactor;
    return std::min(totalWorkload, 100.0);
}

bool Nurse::canTakeMorePatients() const {
    double workload = calculateWorkload();
    bool hasCapacity = assignedPatients.size() < maxPatients;
    bool isNotOverworked = workload < 80.0;
    bool hasReasonableShift = shiftHours <= 10;
    bool isQualifiedForComplexCases = qualification == "RN" || experienceYears >= 3;
    
    return hasCapacity && isNotOverworked && hasReasonableShift && isQualifiedForComplexCases;
}

double Nurse::calculatePatientCareScore() const {
    double baseScore = 70.0;
    
    double experienceBonus = experienceYears * 2.0;
    double qualificationBonus = 0.0;
    
    if (qualification == "RN") qualificationBonus = 15.0;
    else if (qualification == "LPN") qualificationBonus = 10.0;
    else if (qualification == "CNA") qualificationBonus = 5.0;
    
    double patientOutcomeBonus = 0.0;
    for (const auto& patient : assignedPatients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientOutcomeBonus += 3.0;
        }
    }
    
    double departmentBonus = department ? 5.0 : 0.0;
    double workloadPenalty = calculateWorkload() > 70.0 ? 10.0 : 0.0;
    
    double totalScore = baseScore + experienceBonus + qualificationBonus + patientOutcomeBonus + departmentBonus - workloadPenalty;
    return std::max(0.0, std::min(totalScore, 100.0));
}

void Nurse::addPatient(Patient* patient) {
    if (patient && assignedPatients.size() < maxPatients) {
        assignedPatients.push_back(patient);
    }
}

void Nurse::removePatient(const std::string& patientId) {
    assignedPatients.erase(
        std::remove_if(assignedPatients.begin(), assignedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        assignedPatients.end()
    );
}

std::vector<Patient*> Nurse::getAssignedPatients() const {
    return assignedPatients;
}

void Nurse::setDepartment(MedicalDepartment* department) {
    this->department = department;
}

MedicalDepartment* Nurse::getDepartment() const {
    return department;
}
