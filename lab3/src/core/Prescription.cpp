#include "Prescription.h"
#include "Patient.h"
#include "Doctor.h"
#include "Medication.h"
#include <algorithm>
#include <cmath>

Prescription::Prescription(const std::string& id, const std::string& dateIssued, const std::string& instructions)
    : id(id), dateIssued(dateIssued), instructions(instructions), refillsRemaining(0), isActive(true), 
      patient(nullptr), prescribingDoctor(nullptr) {}

double Prescription::calculateAdherenceProbability() const {
    double baseProbability = 75.0;
    
    double instructionComplexityPenalty = instructions.length() > 100 ? 15.0 : 5.0;
    double medicationCountPenalty = prescribedMedications.size() > 3 ? 10.0 : 0.0;
    
    double patientFactor = patient ? (100.0 - patient->calculateHealthRiskScore()) * 0.2 : 0.0;
    double doctorExperienceFactor = prescribingDoctor ? prescribingDoctor->getExperienceYears() * 0.8 : 0.0;
    
    double refillFactor = refillsRemaining > 0 ? 8.0 : 0.0;
    double activeStatusFactor = isActive ? 5.0 : -10.0;
    
    double totalProbability = baseProbability - instructionComplexityPenalty - medicationCountPenalty + 
                             patientFactor + doctorExperienceFactor + refillFactor + activeStatusFactor;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

bool Prescription::requiresRenewal() const {
    bool noRefillsRemaining = refillsRemaining <= 0;
    bool longTermMedication = false;
    
    for (const auto& medication : prescribedMedications) {
        if (medication->getType() == "Chronic" || medication->getFrequencyPerDay() > 2) {
            longTermMedication = true;
            break;
        }
    }
    
    bool complexMedicationRegimen = prescribedMedications.size() >= 3;
    bool patientHighRisk = patient && patient->calculateHealthRiskScore() > 60.0;
    bool recentPrescription = false; // Simplified - would normally check date
    
    return noRefillsRemaining || (longTermMedication && complexMedicationRegimen) || patientHighRisk;
}

double Prescription::calculateTherapeuticEffectiveness() const {
    double baseEffectiveness = 70.0;
    
    double medicationEffectiveness = 0.0;
    for (const auto& medication : prescribedMedications) {
        medicationEffectiveness += medication->calculateEffectivenessScore() * 0.15;
    }
    
    double patientComplianceFactor = calculateAdherenceProbability() * 0.3;
    double doctorExpertiseFactor = prescribingDoctor ? prescribingDoctor->calculatePatientSuccessRate() * 0.2 : 0.0;
    
    double regimenComplexityFactor = 0.0;
    if (prescribedMedications.size() == 1) regimenComplexityFactor = 10.0;
    else if (prescribedMedications.size() <= 3) regimenComplexityFactor = 5.0;
    
    double instructionClarityFactor = instructions.length() < 50 ? 8.0 : 2.0;
    
    double totalEffectiveness = baseEffectiveness + medicationEffectiveness + patientComplianceFactor + 
                               doctorExpertiseFactor + regimenComplexityFactor + instructionClarityFactor;
    return std::min(totalEffectiveness, 100.0);
}

bool Prescription::hasDrugInteractions() const {
    if (prescribedMedications.size() < 2) return false;
    
    bool hasStrongInteractions = false;
    bool hasMultipleDrugTypes = false;
    
    int painMedCount = 0;
    int antibioticCount = 0;
    int bloodPressureMedCount = 0;
    
    for (const auto& medication : prescribedMedications) {
        if (medication->getType() == "Pain Relief") painMedCount++;
        else if (medication->getType() == "Antibiotic") antibioticCount++;
        else if (medication->getType() == "Blood Pressure") bloodPressureMedCount++;
        
        if (medication->hasSideEffects() && medication->getDosageMg() > 500.0) {
            hasStrongInteractions = true;
        }
    }
    
    hasMultipleDrugTypes = (painMedCount > 0 && antibioticCount > 0) || 
                          (bloodPressureMedCount > 0 && painMedCount > 0);
    
    bool elderlyPatient = patient && patient->getAge() > 65;
    bool complexRegimen = prescribedMedications.size() >= 4;
    
    return hasStrongInteractions || hasMultipleDrugTypes || (elderlyPatient && complexRegimen);
}

std::string Prescription::determineComplexityLevel() const {
    int complexityPoints = 0;
    
    if (prescribedMedications.size() > 3) complexityPoints += 2;
    if (instructions.length() > 150) complexityPoints += 2;
    if (hasDrugInteractions()) complexityPoints += 2;
    if (patient && patient->getAge() > 75) complexityPoints += 1;
    if (refillsRemaining == 0) complexityPoints += 1;
    
    if (complexityPoints >= 5) return "HIGH";
    else if (complexityPoints >= 3) return "MEDIUM";
    else return "LOW";
}

void Prescription::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* Prescription::getPatient() const {
    return patient;
}

void Prescription::setPrescribingDoctor(Doctor* doctor) {
    this->prescribingDoctor = doctor;
}

Doctor* Prescription::getPrescribingDoctor() const {
    return prescribingDoctor;
}

void Prescription::addMedication(Medication* medication) {
    if (medication) {
        prescribedMedications.push_back(medication);
    }
}

void Prescription::removeMedication(const std::string& medicationId) {
    prescribedMedications.erase(
        std::remove_if(prescribedMedications.begin(), prescribedMedications.end(),
            [&medicationId](Medication* medication) {
                return medication->getId() == medicationId;
            }),
        prescribedMedications.end()
    );
}

std::vector<Medication*> Prescription::getPrescribedMedications() const {
    return prescribedMedications;
}
