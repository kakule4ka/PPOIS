#include "Surgeon.h"
#include "Surgery.h"
#include "OperatingRoom.h"
#include <algorithm>
#include <cmath>

Surgeon::Surgeon(const std::string& id, const std::string& name, int experience, 
                const std::string& license, int maxPatients, int surgeries, double complicationRate)
    : Doctor(id, name, "Surgery", experience, license, maxPatients),
      surgeriesPerformed(surgeries), complicationRate(complicationRate),
      surgicalSpecialty("General Surgery") {}

double Surgeon::calculateSurgicalRisk(const Surgery* surgery) const {
    if (!surgery) return 0.0;
    
    double baseRisk = complicationRate;
    
    double surgeryComplexityRisk = surgery->getComplexityLevel() * 8.0;
    double durationRisk = surgery->getDurationMinutes() > 180 ? 15.0 : 8.0;
    
    double experienceRiskReduction = getExperienceYears() * 0.7;
    double volumeRiskReduction = surgeriesPerformed * 0.05;
    
    double equipmentRiskFactor = 0.0;
    for (const auto& room : assignedOperatingRooms) {
        if (room->isFullyEquipped()) {
            equipmentRiskFactor -= 5.0;
        }
    }
    
    double specialtyMatchRisk = surgicalSpecialty == surgery->getType() ? -8.0 : 5.0;
    
    double totalRisk = baseRisk + surgeryComplexityRisk + durationRisk - experienceRiskReduction - 
                      volumeRiskReduction + equipmentRiskFactor + specialtyMatchRisk;
    return std::max(0.0, std::min(totalRisk, 100.0));
}

bool Surgeon::canHandleComplexSurgery() const {
    bool extensiveExperience = getExperienceYears() >= 12;
    bool lowComplicationRate = complicationRate <= 5.0;
    bool highSurgeryVolume = surgeriesPerformed >= 200;
    bool hasSpecializedRooms = false;
    
    for (const auto& room : assignedOperatingRooms) {
        if (room->getType() == "Advanced" || room->getType() == surgicalSpecialty) {
            hasSpecializedRooms = true;
            break;
        }
    }
    
    bool complexSpecialty = surgicalSpecialty == "Cardiac" || surgicalSpecialty == "Neurological" || 
                           surgicalSpecialty == "Transplant";
    
    return extensiveExperience && lowComplicationRate && highSurgeryVolume && 
           hasSpecializedRooms && complexSpecialty;
}

double Surgeon::calculateSurgicalOutcomeScore() const {
    double baseScore = 100.0 - complicationRate;
    
    double experienceScore = getExperienceYears() * 1.3;
    double volumeScore = surgeriesPerformed * 0.08;
    
    double successRateScore = 0.0;
    for (const auto& surgery : performedSurgeries) {
        if (surgery->getSuccessRate() > 85.0) {
            successRateScore += 1.2;
        }
    }
    
    double equipmentScore = 0.0;
    for (const auto& room : assignedOperatingRooms) {
        if (room->isAvailable()) {
            equipmentScore += 2.0;
        }
    }
    
    double specialtyScore = surgicalSpecialty == "Cardiac" || surgicalSpecialty == "Neurological" ? 12.0 : 5.0;
    
    double totalScore = baseScore + experienceScore + volumeScore + successRateScore + equipmentScore + specialtyScore;
    return std::min(totalScore, 100.0);
}

void Surgeon::addPerformedSurgery(Surgery* surgery) {
    if (surgery) {
        performedSurgeries.push_back(surgery);
    }
}

void Surgeon::removePerformedSurgery(const std::string& surgeryId) {
    performedSurgeries.erase(
        std::remove_if(performedSurgeries.begin(), performedSurgeries.end(),
            [&surgeryId](Surgery* surgery) {
                return surgery->getId() == surgeryId;
            }),
        performedSurgeries.end()
    );
}

std::vector<Surgery*> Surgeon::getPerformedSurgeries() const {
    return performedSurgeries;
}

void Surgeon::addAssignedOperatingRoom(OperatingRoom* room) {
    if (room) {
        assignedOperatingRooms.push_back(room);
    }
}

void Surgeon::removeAssignedOperatingRoom(const std::string& roomId) {
    assignedOperatingRooms.erase(
        std::remove_if(assignedOperatingRooms.begin(), assignedOperatingRooms.end(),
            [&roomId](OperatingRoom* room) {
                return room->getId() == roomId;
            }),
        assignedOperatingRooms.end()
    );
}

std::vector<OperatingRoom*> Surgeon::getAssignedOperatingRooms() const {
    return assignedOperatingRooms;
}
