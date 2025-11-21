#include "Ambulance.h"
#include "Patient.h"
#include "EmergencyCase.h"
#include "MedicalEquipment.h"
#include <algorithm>
#include <cmath>

Ambulance::Ambulance(const std::string& id, const std::string& type, bool available)
    : id(id), type(type), availabilityStatus(available), responseTime(8.0), capacity(2) {}

double Ambulance::calculateEmergencyResponseScore() const {
    double baseScore = 70.0;
    
    double availabilityScore = availabilityStatus ? 15.0 : 0.0;
    double responseTimeScore = (15.0 - responseTime) * 3.0; // Faster response = higher score
    
    double equipmentScore = 0.0;
    for (const auto& equipment : onboardEquipment) {
        if (equipment->getIsOperational()) {
            equipmentScore += 4.0;
        }
    }
    
    double experienceScore = handledEmergencies.size() * 0.5;
    double capacityScore = capacity >= 3 ? 8.0 : 5.0;
    
    double patientStabilityScore = 0.0;
    for (const auto& patient : transportedPatients) {
        if (patient->calculateHealthRiskScore() < 50.0) {
            patientStabilityScore += 2.0;
        }
    }
    
    double totalScore = baseScore + availabilityScore + responseTimeScore + equipmentScore + 
                       experienceScore + capacityScore + patientStabilityScore;
    return std::min(totalScore, 100.0);
}

bool Ambulance::canHandleCriticalTransport() const {
    bool advancedAmbulance = type == "ALS" || type == "Mobile ICU";
    bool fastResponse = responseTime <= 6.0;
    bool adequateCapacity = capacity >= 2;
    
    bool hasLifeSupportEquipment = false;
    for (const auto& equipment : onboardEquipment) {
        if (equipment->getType() == "Life Support" || equipment->getName().find("Defibrillator") != std::string::npos) {
            hasLifeSupportEquipment = true;
            break;
        }
    }
    
    bool experiencedWithEmergencies = handledEmergencies.size() >= 20;
    bool currentlyAvailable = availabilityStatus;
    
    return advancedAmbulance && fastResponse && adequateCapacity && 
           hasLifeSupportEquipment && experiencedWithEmergencies && currentlyAvailable;
}

double Ambulance::calculateEquipmentReadiness() const {
    if (onboardEquipment.empty()) return 0.0;
    
    double baseReadiness = 75.0;
    
    double operationalEquipment = 0.0;
    for (const auto& equipment : onboardEquipment) {
        if (equipment->getIsOperational()) {
            operationalEquipment += 1.0;
        }
    }
    double operationalRate = (operationalEquipment / onboardEquipment.size()) * 25.0;
    
    double equipmentDiversity = 0.0;
    bool hasBasicEquipment = false;
    bool hasAdvancedEquipment = false;
    bool hasLifeSupport = false;
    
    for (const auto& equipment : onboardEquipment) {
        if (equipment->getType() == "Basic") hasBasicEquipment = true;
        if (equipment->getType() == "Advanced") hasAdvancedEquipment = true;
        if (equipment->getType() == "Life Support") hasLifeSupport = true;
    }
    
    if (hasBasicEquipment) equipmentDiversity += 10.0;
    if (hasAdvancedEquipment) equipmentDiversity += 8.0;
    if (hasLifeSupport) equipmentDiversity += 7.0;
    
    double maintenanceReadiness = 0.0;
    for (const auto& equipment : onboardEquipment) {
        if (!equipment->needsMaintenance()) {
            maintenanceReadiness += 3.0;
        }
    }
    
    double totalReadiness = baseReadiness + operationalRate + equipmentDiversity + maintenanceReadiness;
    return std::min(totalReadiness, 100.0);
}

void Ambulance::addTransportedPatient(Patient* patient) {
    if (patient && transportedPatients.size() < capacity) {
        transportedPatients.push_back(patient);
    }
}

void Ambulance::removeTransportedPatient(const std::string& patientId) {
    transportedPatients.erase(
        std::remove_if(transportedPatients.begin(), transportedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        transportedPatients.end()
    );
}

std::vector<Patient*> Ambulance::getTransportedPatients() const {
    return transportedPatients;
}

void Ambulance::addHandledEmergency(EmergencyCase* emergency) {
    if (emergency) {
        handledEmergencies.push_back(emergency);
    }
}

void Ambulance::removeHandledEmergency(const std::string& emergencyId) {
    handledEmergencies.erase(
        std::remove_if(handledEmergencies.begin(), handledEmergencies.end(),
            [&emergencyId](EmergencyCase* emergency) {
                return emergency->getId() == emergencyId;
            }),
        handledEmergencies.end()
    );
}

std::vector<EmergencyCase*> Ambulance::getHandledEmergencies() const {
    return handledEmergencies;
}

void Ambulance::addOnboardEquipment(MedicalEquipment* equipment) {
    if (equipment) {
        onboardEquipment.push_back(equipment);
    }
}

void Ambulance::removeOnboardEquipment(const std::string& equipmentId) {
    onboardEquipment.erase(
        std::remove_if(onboardEquipment.begin(), onboardEquipment.end(),
            [&equipmentId](MedicalEquipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        onboardEquipment.end()
    );
}

std::vector<MedicalEquipment*> Ambulance::getOnboardEquipment() const {
    return onboardEquipment;
}
