#include "TreatmentPlan.h"
#include "Patient.h"
#include "Medication.h"
#include <algorithm>
#include <cmath>

TreatmentPlan::TreatmentPlan(const std::string& id, const std::string& description, int duration)
    : id(id), description(description), durationDays(duration), successRate(70.0), isActive(true), cost(0.0), patient(nullptr) {}

double TreatmentPlan::calculateTreatmentEffectiveness() const {
    double baseEffectiveness = successRate;
    
    double durationFactor = 0.0;
    if (durationDays <= 7) durationFactor = 10.0;
    else if (durationDays <= 30) durationFactor = 5.0;
    else if (durationDays > 90) durationFactor = -5.0;
    
    double medicationFactor = prescribedMedications.size() * 2.0;
    double costFactor = cost > 1000.0 ? -8.0 : 3.0;
    
    double patientFactor = patient ? 5.0 : 0.0;
    double descriptionFactor = description.length() > 50 ? 2.0 : 0.0;
    
    double totalEffectiveness = baseEffectiveness + durationFactor + medicationFactor + costFactor + patientFactor + descriptionFactor;
    return std::max(0.0, std::min(totalEffectiveness, 100.0));
}

bool TreatmentPlan::isCostEffective() const {
    double effectiveness = calculateTreatmentEffectiveness();
    double costPerEffectiveness = cost > 0 ? cost / effectiveness : 0.0;
    
    bool hasReasonableCost = cost <= 5000.0;
    bool hasGoodEffectiveness = effectiveness >= 60.0;
    bool usesGenericMeds = true;
    
    for (const auto& medication : prescribedMedications) {
        if (medication->isBrandName()) {
            usesGenericMeds = false;
            break;
        }
    }
    
    bool shortTermPlan = durationDays <= 30;
    bool hasPatientCoverage = patient != nullptr;
    
    return hasReasonableCost && hasGoodEffectiveness && (usesGenericMeds || shortTermPlan) && hasPatientCoverage;
}

double TreatmentPlan::calculateAdherenceProbability() const {
    double baseProbability = 75.0;
    
    double durationPenalty = durationDays > 30 ? (durationDays - 30) * 0.5 : 0.0;
    double medicationPenalty = prescribedMedications.size() > 3 ? 10.0 : 0.0;
    double costPenalty = cost > 500.0 ? 5.0 : 0.0;
    
    double simplicityBonus = description.length() < 100 ? 5.0 : 0.0;
    double patientBonus = patient ? 3.0 : 0.0;
    double successBonus = successRate > 80.0 ? 5.0 : 0.0;
    
    double totalProbability = baseProbability - durationPenalty - medicationPenalty - costPenalty + simplicityBonus + patientBonus + successBonus;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

bool TreatmentPlan::needsModification() const {
    double effectiveness = calculateTreatmentEffectiveness();
    double adherenceProbability = calculateAdherenceProbability();
    
    bool lowEffectiveness = effectiveness < 50.0;
    bool poorAdherence = adherenceProbability < 60.0;
    bool highCost = cost > 2000.0;
    bool longDuration = durationDays > 90;
    bool multipleMedications = prescribedMedications.size() > 5;
    
    return lowEffectiveness || poorAdherence || highCost || longDuration || multipleMedications;
}

std::string TreatmentPlan::determineComplexityLevel() const {
    int complexityScore = 0;
    
    if (durationDays > 60) complexityScore += 2;
    if (prescribedMedications.size() > 3) complexityScore += 2;
    if (cost > 1000.0) complexityScore += 1;
    if (successRate < 60.0) complexityScore += 1;
    if (description.length() > 200) complexityScore += 1;
    
    if (complexityScore >= 5) return "HIGH";
    else if (complexityScore >= 3) return "MEDIUM";
    else return "LOW";
}

void TreatmentPlan::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* TreatmentPlan::getPatient() const {
    return patient;
}

void TreatmentPlan::addMedication(Medication* medication) {
    if (medication) {
        prescribedMedications.push_back(medication);
    }
}

void TreatmentPlan::removeMedication(const std::string& medicationId) {
    prescribedMedications.erase(
        std::remove_if(prescribedMedications.begin(), prescribedMedications.end(),
            [&medicationId](Medication* medication) {
                return medication->getId() == medicationId;
            }),
        prescribedMedications.end()
    );
}

std::vector<Medication*> TreatmentPlan::getPrescribedMedications() const {
    return prescribedMedications;
}
