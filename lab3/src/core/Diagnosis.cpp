#include "Diagnosis.h"
#include "MedicalRecord.h"
#include "TreatmentPlan.h"
#include <algorithm>
#include <cmath>

Diagnosis::Diagnosis(const std::string& id, const std::string& name, const std::string& category)
    : id(id), name(name), category(category), severity(1), isChronic(false), icdCode("") {}

double Diagnosis::calculateTreatmentComplexity() const {
    double baseComplexity = severity * 15.0;
    
    double categoryComplexity = 0.0;
    if (category == "Cardiovascular") categoryComplexity = 25.0;
    else if (category == "Neurological") categoryComplexity = 30.0;
    else if (category == "Oncological") categoryComplexity = 35.0;
    else if (category == "Respiratory") categoryComplexity = 15.0;
    
    double chronicFactor = isChronic ? 20.0 : 5.0;
    double recordFactor = medicalRecords.size() * 2.0;
    double planFactor = recommendedPlans.size() * 3.0;
    
    double totalComplexity = baseComplexity + categoryComplexity + chronicFactor + recordFactor + planFactor;
    return std::min(totalComplexity, 100.0);
}

bool Diagnosis::requiresSpecialist() const {
    bool highSeverity = severity >= 4;
    bool complexCategory = category == "Cardiovascular" || category == "Neurological" || 
                          category == "Oncological" || category == "Psychiatric";
    bool chronicAndSevere = isChronic && severity >= 3;
    bool multipleRecords = medicalRecords.size() >= 3;
    bool hasComplexPlans = false;
    
    for (const auto& plan : recommendedPlans) {
        if (plan->determineComplexityLevel() == "HIGH") {
            hasComplexPlans = true;
            break;
        }
    }
    
    return highSeverity || complexCategory || chronicAndSevere || multipleRecords || hasComplexPlans;
}

double Diagnosis::calculateRecoveryTime() const {
    double baseTime = 14.0; // days
    
    double severityMultiplier = severity * 7.0;
    double categoryMultiplier = 0.0;
    
    if (category == "Cardiovascular") categoryMultiplier = 30.0;
    else if (category == "Neurological") categoryMultiplier = 45.0;
    else if (category == "Oncological") categoryMultiplier = 90.0;
    else if (category == "Respiratory") categoryMultiplier = 21.0;
    
    double chronicMultiplier = isChronic ? 60.0 : 0.0;
    double recordMultiplier = medicalRecords.size() * 2.0;
    
    double totalTime = baseTime + severityMultiplier + categoryMultiplier + chronicMultiplier + recordMultiplier;
    return totalTime;
}

void Diagnosis::addMedicalRecord(MedicalRecord* record) {
    if (record) {
        medicalRecords.push_back(record);
    }
}

void Diagnosis::removeMedicalRecord(const std::string& recordId) {
    medicalRecords.erase(
        std::remove_if(medicalRecords.begin(), medicalRecords.end(),
            [&recordId](MedicalRecord* record) {
                return record->getId() == recordId;
            }),
        medicalRecords.end()
    );
}

std::vector<MedicalRecord*> Diagnosis::getMedicalRecords() const {
    return medicalRecords;
}

void Diagnosis::addRecommendedPlan(TreatmentPlan* plan) {
    if (plan) {
        recommendedPlans.push_back(plan);
    }
}

void Diagnosis::removeRecommendedPlan(const std::string& planId) {
    recommendedPlans.erase(
        std::remove_if(recommendedPlans.begin(), recommendedPlans.end(),
            [&planId](TreatmentPlan* plan) {
                return plan->getId() == planId;
            }),
        recommendedPlans.end()
    );
}

std::vector<TreatmentPlan*> Diagnosis::getRecommendedPlans() const {
    return recommendedPlans;
}
