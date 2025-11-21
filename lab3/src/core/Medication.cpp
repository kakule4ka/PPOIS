#include "Medication.h"
#include "TreatmentPlan.h"
#include "Patient.h"
#include <algorithm>
#include <cmath>

Medication::Medication(const std::string& id, const std::string& name, const std::string& type, double dosage)
    : id(id), name(name), type(type), dosageMg(dosage), frequencyPerDay(1), costPerUnit(0.0), brandStatus(false) {}

double Medication::calculateDailyCost() const {
    double baseCost = costPerUnit * frequencyPerDay;
    
    double brandMultiplier = brandStatus ? 2.5 : 1.0;
    double dosageMultiplier = dosageMg / 100.0;
    double typeMultiplier = 1.0;
    
    if (type == "Antibiotic") typeMultiplier = 1.2;
    else if (type == "Pain Relief") typeMultiplier = 0.8;
    else if (type == "Chronic") typeMultiplier = 1.5;
    
    double treatmentPlanFactor = 1.0 + (treatmentPlans.size() * 0.05);
    
    return baseCost * brandMultiplier * dosageMultiplier * typeMultiplier * treatmentPlanFactor;
}

bool Medication::hasSideEffects() const {
    bool highDosage = dosageMg > 500.0;
    bool frequentAdministration = frequencyPerDay >= 4;
    bool isStrongType = type == "Antibiotic" || type == "Chemotherapy" || type == "Psychiatric";
    bool hasAllergicPatients = !allergicPatients.empty();
    bool isExpensive = costPerUnit > 50.0;
    
    return highDosage || frequentAdministration || isStrongType || hasAllergicPatients || isExpensive;
}

double Medication::calculateEffectivenessScore() const {
    double baseScore = 70.0;
    
    double dosageScore = std::min(dosageMg / 10.0, 20.0);
    double frequencyScore = frequencyPerDay <= 3 ? 10.0 : 5.0;
    double typeScore = 0.0;
    
    if (type == "Antibiotic") typeScore = 15.0;
    else if (type == "Pain Relief") typeScore = 12.0;
    else if (type == "Chronic") typeScore = 8.0;
    else typeScore = 5.0;
    
    double brandScore = brandStatus ? 5.0 : 0.0;
    double usageScore = treatmentPlans.size() * 1.0;
    
    double allergyPenalty = allergicPatients.size() * 3.0;
    double costPenalty = costPerUnit > 100.0 ? 5.0 : 0.0;
    
    double totalScore = baseScore + dosageScore + frequencyScore + typeScore + brandScore + usageScore - allergyPenalty - costPenalty;
    return std::max(0.0, std::min(totalScore, 100.0));
}

bool Medication::isSuitableForElderly() const {
    bool lowDosage = dosageMg <= 250.0;
    bool simpleFrequency = frequencyPerDay <= 2;
    bool noStrongSideEffects = !hasSideEffects() || dosageMg < 100.0;
    bool affordable = calculateDailyCost() <= 10.0;
    bool commonType = type == "Pain Relief" || type == "Blood Pressure" || type == "Cholesterol";
    
    return lowDosage && simpleFrequency && noStrongSideEffects && affordable && commonType;
}

std::string Medication::determineAdministrationComplexity() const {
    int complexityPoints = 0;
    
    if (frequencyPerDay > 3) complexityPoints += 2;
    if (dosageMg > 500.0) complexityPoints += 2;
    if (type == "Chemotherapy" || type == "Psychiatric") complexityPoints += 2;
    if (hasSideEffects()) complexityPoints += 1;
    if (costPerUnit > 100.0) complexityPoints += 1;
    
    if (complexityPoints >= 5) return "HIGH";
    else if (complexityPoints >= 3) return "MEDIUM";
    else return "LOW";
}

void Medication::addTreatmentPlan(TreatmentPlan* plan) {
    if (plan) {
        treatmentPlans.push_back(plan);
    }
}

void Medication::removeTreatmentPlan(const std::string& planId) {
    treatmentPlans.erase(
        std::remove_if(treatmentPlans.begin(), treatmentPlans.end(),
            [&planId](TreatmentPlan* plan) {
                return plan->getId() == planId;
            }),
        treatmentPlans.end()
    );
}

std::vector<TreatmentPlan*> Medication::getTreatmentPlans() const {
    return treatmentPlans;
}

void Medication::addAllergicPatient(Patient* patient) {
    if (patient) {
        allergicPatients.push_back(patient);
    }
}

void Medication::removeAllergicPatient(const std::string& patientId) {
    allergicPatients.erase(
        std::remove_if(allergicPatients.begin(), allergicPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        allergicPatients.end()
    );
}

std::vector<Patient*> Medication::getAllergicPatients() const {
    return allergicPatients;
}
