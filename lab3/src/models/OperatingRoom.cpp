#include "OperatingRoom.h"
#include "Surgery.h"
#include "MedicalEquipment.h"
#include "Doctor.h"
#include <algorithm>
#include <cmath>

OperatingRoom::OperatingRoom(const std::string& id, const std::string& type, bool available)
    : id(id), type(type), availabilityStatus(available), sterilizationLevel(98.0), sizeSqm(40) {}

double OperatingRoom::calculateReadinessScore() const {
    double baseScore = 70.0;
    
    double availabilityScore = availabilityStatus ? 15.0 : 0.0;
    double sterilizationScore = sterilizationLevel * 0.3;
    
    double equipmentScore = 0.0;
    for (const auto& equipment : surgicalEquipment) {
        if (equipment->getIsOperational()) {
            equipmentScore += 5.0;
        }
    }
    
    double surgeonScore = authorizedSurgeons.size() * 2.0;
    double sizeScore = sizeSqm >= 50 ? 10.0 : (sizeSqm >= 30 ? 5.0 : 0.0);
    
    double scheduleScore = 0.0;
    if (scheduledSurgeries.size() <= 3) {
        scheduleScore = 10.0;
    } else if (scheduledSurgeries.size() <= 6) {
        scheduleScore = 5.0;
    }
    
    double totalScore = baseScore + availabilityScore + sterilizationScore + equipmentScore + 
                       surgeonScore + sizeScore + scheduleScore;
    return std::min(totalScore, 100.0);
}

bool OperatingRoom::canHandleComplexSurgery() const {
    bool adequateSize = sizeSqm >= 45;
    bool highSterilization = sterilizationLevel >= 99.0;
    bool specializedEquipment = false;
    
    for (const auto& equipment : surgicalEquipment) {
        if (equipment->getType() == "Surgical" && equipment->getName().find("Advanced") != std::string::npos) {
            specializedEquipment = true;
            break;
        }
    }
    
    bool experiencedSurgeons = false;
    for (const auto& surgeon : authorizedSurgeons) {
        if (surgeon->getExperienceYears() >= 8) {
            experiencedSurgeons = true;
            break;
        }
    }
    
    bool appropriateRoomType = type == "Cardiac" || type == "Neurological" || type == "Transplant";
    bool notOverbooked = scheduledSurgeries.size() <= 2;
    
    return adequateSize && highSterilization && specializedEquipment && experiencedSurgeons && 
           appropriateRoomType && notOverbooked;
}

double OperatingRoom::calculateEfficiencyRating() const {
    double baseRating = 75.0;
    
    double equipmentEfficiency = 0.0;
    for (const auto& equipment : surgicalEquipment) {
        double equipmentUtilization = equipment->calculateUtilizationEfficiency();
        equipmentEfficiency += equipmentUtilization * 0.1;
    }
    
    double surgeonEfficiency = 0.0;
    for (const auto& surgeon : authorizedSurgeons) {
        if (surgeon->calculateWorkloadEfficiency() > 70.0) {
            surgeonEfficiency += 3.0;
        }
    }
    
    double scheduleEfficiency = 0.0;
    if (!scheduledSurgeries.empty()) {
        double totalSurgeryTime = 0.0;
        for (const auto& surgery : scheduledSurgeries) {
            totalSurgeryTime += surgery->getDurationMinutes();
        }
        double optimalTime = scheduledSurgeries.size() * 120.0; // 2 hours per surgery
        scheduleEfficiency = (1.0 - (totalSurgeryTime / optimalTime)) * 20.0;
    }
    
    double sterilizationEfficiency = sterilizationLevel * 0.2;
    double availabilityEfficiency = availabilityStatus ? 10.0 : 0.0;
    
    double totalRating = baseRating + equipmentEfficiency + surgeonEfficiency + 
                        scheduleEfficiency + sterilizationEfficiency + availabilityEfficiency;
    return std::min(totalRating, 100.0);
}

void OperatingRoom::addScheduledSurgery(Surgery* surgery) {
    if (surgery) {
        scheduledSurgeries.push_back(surgery);
    }
}

void OperatingRoom::removeScheduledSurgery(const std::string& surgeryId) {
    scheduledSurgeries.erase(
        std::remove_if(scheduledSurgeries.begin(), scheduledSurgeries.end(),
            [&surgeryId](Surgery* surgery) {
                return surgery->getId() == surgeryId;
            }),
        scheduledSurgeries.end()
    );
}

std::vector<Surgery*> OperatingRoom::getScheduledSurgeries() const {
    return scheduledSurgeries;
}

void OperatingRoom::addSurgicalEquipment(MedicalEquipment* equipment) {
    if (equipment) {
        surgicalEquipment.push_back(equipment);
    }
}

void OperatingRoom::removeSurgicalEquipment(const std::string& equipmentId) {
    surgicalEquipment.erase(
        std::remove_if(surgicalEquipment.begin(), surgicalEquipment.end(),
            [&equipmentId](MedicalEquipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        surgicalEquipment.end()
    );
}

std::vector<MedicalEquipment*> OperatingRoom::getSurgicalEquipment() const {
    return surgicalEquipment;
}

void OperatingRoom::addAuthorizedSurgeon(Doctor* surgeon) {
    if (surgeon) {
        authorizedSurgeons.push_back(surgeon);
    }
}

void OperatingRoom::removeAuthorizedSurgeon(const std::string& surgeonId) {
    authorizedSurgeons.erase(
        std::remove_if(authorizedSurgeons.begin(), authorizedSurgeons.end(),
            [&surgeonId](Doctor* surgeon) {
                return surgeon->getId() == surgeonId;
            }),
        authorizedSurgeons.end()
    );
}

std::vector<Doctor*> OperatingRoom::getAuthorizedSurgeons() const {
    return authorizedSurgeons;
}
