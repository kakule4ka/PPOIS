#include "Cardiologist.h"
#include "Patient.h"
#include "MedicalEquipment.h"
#include <algorithm>
#include <cmath>

Cardiologist::Cardiologist(const std::string& id, const std::string& name, int experience, 
                          const std::string& license, int maxPatients, int procedures, double successRate)
    : Doctor(id, name, "Cardiology", experience, license, maxPatients),
      cardiacProceduresPerformed(procedures), successRateCardiacSurgery(successRate),
      boardCertification("Board Certified") {}

double Cardiologist::calculateCardiacRiskAssessment(const Patient* patient) const {
    if (!patient) return 0.0;
    
    double baseRisk = 20.0;
    
    double ageRisk = patient->getAge() * 0.8;
    double bmiRisk = patient->calculateBMI() > 30.0 ? 25.0 : 10.0;
    
    double bloodTypeRisk = 0.0;
    if (patient->getBloodType() == "A+" || patient->getBloodType() == "AB+") {
        bloodTypeRisk = 8.0;
    }
    
    double experienceFactor = getExperienceYears() * 0.5;
    double procedureFactor = cardiacProceduresPerformed * 0.1;
    
    double equipmentFactor = 0.0;
    for (const auto& equipment : specializedEquipment) {
        if (equipment->getType() == "Cardiac") {
            equipmentFactor += 3.0;
        }
    }
    
    double totalRisk = baseRisk + ageRisk + bmiRisk + bloodTypeRisk - experienceFactor - procedureFactor - equipmentFactor;
    return std::max(0.0, std::min(totalRisk, 100.0));
}

bool Cardiologist::canPerformComplexProcedure() const {
    bool sufficientExperience = getExperienceYears() >= 8;
    bool highSuccessRate = successRateCardiacSurgery >= 90.0;
    bool adequateProcedures = cardiacProceduresPerformed >= 50;
    bool hasSpecializedEquipment = false;
    
    for (const auto& equipment : specializedEquipment) {
        if (equipment->getName().find("Cardiac") != std::string::npos ||
            equipment->getName().find("ECG") != std::string::npos ||
            equipment->getName().find("Angiography") != std::string::npos) {
            hasSpecializedEquipment = true;
            break;
        }
    }
    
    bool boardCertified = boardCertification == "Board Certified";
    
    return sufficientExperience && highSuccessRate && adequateProcedures && hasSpecializedEquipment && boardCertified;
}

double Cardiologist::calculateTreatmentEffectiveness() const {
    double baseEffectiveness = successRateCardiacSurgery;
    
    double experienceEffectiveness = getExperienceYears() * 1.2;
    double procedureEffectiveness = cardiacProceduresPerformed * 0.15;
    
    double patientOutcomeEffectiveness = 0.0;
    for (const auto& patient : cardiacPatients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientOutcomeEffectiveness += 2.0;
        }
    }
    
    double equipmentEffectiveness = 0.0;
    for (const auto& equipment : specializedEquipment) {
        if (equipment->getIsOperational()) {
            equipmentEffectiveness += 1.5;
        }
    }
    
    double certificationEffectiveness = boardCertification == "Board Certified" ? 10.0 : 0.0;
    
    double totalEffectiveness = baseEffectiveness + experienceEffectiveness + procedureEffectiveness + 
                               patientOutcomeEffectiveness + equipmentEffectiveness + certificationEffectiveness;
    return std::min(totalEffectiveness, 100.0);
}

void Cardiologist::addCardiacPatient(Patient* patient) {
    if (patient) {
        cardiacPatients.push_back(patient);
    }
}

void Cardiologist::removeCardiacPatient(const std::string& patientId) {
    cardiacPatients.erase(
        std::remove_if(cardiacPatients.begin(), cardiacPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        cardiacPatients.end()
    );
}

std::vector<Patient*> Cardiologist::getCardiacPatients() const {
    return cardiacPatients;
}

void Cardiologist::addSpecializedEquipment(MedicalEquipment* equipment) {
    if (equipment) {
        specializedEquipment.push_back(equipment);
    }
}

void Cardiologist::removeSpecializedEquipment(const std::string& equipmentId) {
    specializedEquipment.erase(
        std::remove_if(specializedEquipment.begin(), specializedEquipment.end(),
            [&equipmentId](MedicalEquipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        specializedEquipment.end()
    );
}

std::vector<MedicalEquipment*> Cardiologist::getSpecializedEquipment() const {
    return specializedEquipment;
}
