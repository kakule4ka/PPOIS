#include "Patient.h"
#include "MedicalRecord.h"
#include "TreatmentPlan.h"
#include <algorithm>
#include <cmath>

Patient::Patient(const std::string& id, const std::string& name, int age, const std::string& bloodType)
    : id(id), name(name), age(age), bloodType(bloodType), isAdmitted(false), weight(0.0), height(0.0), currentTreatmentPlan(nullptr) {}

double Patient::calculateBMI() const {
    if (height <= 0.0 || weight <= 0.0) return 0.0;
    
    double heightInMeters = height / 100.0;
    return weight / (heightInMeters * heightInMeters);
}

bool Patient::isEligibleForSurgery() const {
    double bmi = calculateBMI();
    bool hasNormalBMI = bmi >= 18.5 && bmi <= 24.9;
    bool isStableAge = age >= 18 && age <= 70;
    
    bool hasNoCriticalRecords = true;
    for (const auto& record : medicalHistory) {
        if (record->indicatesCriticalCondition()) {
            hasNoCriticalRecords = false;
            break;
        }
    }
    
    bool bloodTypeCompatible = bloodType != "O-"; // Simplified compatibility check
    
    return hasNormalBMI && isStableAge && hasNoCriticalRecords && bloodTypeCompatible;
}

double Patient::calculateHealthRiskScore() const {
    double baseRisk = 20.0;
    
    double ageRisk = age * 0.5;
    double bmiRisk = 0.0;
    double bmi = calculateBMI();
    if (bmi < 18.5) bmiRisk = 15.0;
    else if (bmi > 30.0) bmiRisk = 25.0;
    else if (bmi > 25.0) bmiRisk = 10.0;
    
    double bloodTypeRisk = 0.0;
    if (bloodType == "AB+") bloodTypeRisk = 5.0;
    else if (bloodType == "O-") bloodTypeRisk = -5.0;
    
    double historyRisk = medicalHistory.size() * 2.0;
    
    double totalRisk = baseRisk + ageRisk + bmiRisk + bloodTypeRisk + historyRisk;
    return std::min(totalRisk, 100.0);
}

bool Patient::needsRegularCheckup() const {
    double riskScore = calculateHealthRiskScore();
    bool isSenior = age >= 60;
    bool hasChronicCondition = false;
    
    for (const auto& record : medicalHistory) {
        if (record->isChronicCondition()) {
            hasChronicCondition = true;
            break;
        }
    }
    
    bool hasActiveTreatment = currentTreatmentPlan != nullptr;
    
    return riskScore > 40.0 || isSenior || hasChronicCondition || hasActiveTreatment;
}

std::string Patient::determinePriorityLevel() const {
    double riskScore = calculateHealthRiskScore();
    
    if (riskScore > 70.0 || age >= 75) return "HIGH";
    else if (riskScore > 40.0 || age >= 60) return "MEDIUM";
    else if (riskScore > 20.0) return "LOW";
    else return "ROUTINE";
}

void Patient::addMedicalRecord(MedicalRecord* record) {
    if (record) {
        medicalHistory.push_back(record);
    }
}

void Patient::removeMedicalRecord(const std::string& recordId) {
    medicalHistory.erase(
        std::remove_if(medicalHistory.begin(), medicalHistory.end(),
            [&recordId](MedicalRecord* record) {
                return record->getId() == recordId;
            }),
        medicalHistory.end()
    );
}

std::vector<MedicalRecord*> Patient::getMedicalHistory() const {
    return medicalHistory;
}

void Patient::setTreatmentPlan(TreatmentPlan* plan) {
    this->currentTreatmentPlan = plan;
}

TreatmentPlan* Patient::getTreatmentPlan() const {
    return currentTreatmentPlan;
}
