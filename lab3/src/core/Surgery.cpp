#include "Surgery.h"
#include "Patient.h"
#include "Doctor.h"
#include "OperatingRoom.h"
#include <algorithm>
#include <cmath>

Surgery::Surgery(const std::string& id, const std::string& type, int duration)
    : id(id), type(type), durationMinutes(duration), successRate(85.0), status("SCHEDULED"), complexityLevel(2), 
      patient(nullptr), surgeon(nullptr), operatingRoom(nullptr) {}

double Surgery::calculateRiskLevel() const {
    double baseRisk = 15.0;
    
    double complexityRisk = complexityLevel * 10.0;
    double durationRisk = durationMinutes > 120 ? 20.0 : (durationMinutes > 60 ? 10.0 : 5.0);
    
    double patientRisk = patient ? (patient->calculateHealthRiskScore() * 0.3) : 25.0;
    double surgeonRisk = surgeon ? (100.0 - surgeon->calculatePatientSuccessRate()) * 0.2 : 30.0;
    
    double typeRisk = 0.0;
    if (type == "Cardiac") typeRisk = 25.0;
    else if (type == "Neurological") typeRisk = 30.0;
    else if (type == "Transplant") typeRisk = 35.0;
    
    double totalRisk = baseRisk + complexityRisk + durationRisk + patientRisk + surgeonRisk + typeRisk;
    return std::min(totalRisk, 100.0);
}

bool Surgery::requiresSpecialEquipment() const {
    bool complexSurgery = complexityLevel >= 4;
    bool longDuration = durationMinutes > 180;
    bool specializedType = type == "Cardiac" || type == "Neurological" || type == "Transplant" || type == "Robotic";
    
    bool highRiskPatient = patient && patient->calculateHealthRiskScore() > 60.0;
    bool requiresExpertSurgeon = surgeon && surgeon->getExperienceYears() < 10;
    
    return complexSurgery || longDuration || specializedType || highRiskPatient || requiresExpertSurgeon;
}

double Surgery::calculateRecoveryProbability() const {
    double baseProbability = successRate;
    
    double riskPenalty = calculateRiskLevel() * 0.5;
    double patientBonus = patient ? (100.0 - patient->calculateHealthRiskScore()) * 0.2 : 0.0;
    double surgeonBonus = surgeon ? surgeon->calculatePatientSuccessRate() * 0.3 : 0.0;
    
    double durationPenalty = durationMinutes > 240 ? 15.0 : (durationMinutes > 120 ? 8.0 : 0.0);
    double complexityPenalty = complexityLevel * 3.0;
    
    double equipmentBonus = operatingRoom ? 5.0 : 0.0;
    
    double totalProbability = baseProbability - riskPenalty + patientBonus + surgeonBonus - durationPenalty - complexityPenalty + equipmentBonus;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

void Surgery::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* Surgery::getPatient() const {
    return patient;
}

void Surgery::setSurgeon(Doctor* surgeon) {
    this->surgeon = surgeon;
}

Doctor* Surgery::getSurgeon() const {
    return surgeon;
}

void Surgery::setOperatingRoom(OperatingRoom* room) {
    this->operatingRoom = room;
}

OperatingRoom* Surgery::getOperatingRoom() const {
    return operatingRoom;
}
