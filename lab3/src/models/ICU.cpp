#include "ICU.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalEquipment.h"
#include <algorithm>
#include <cmath>

ICU::ICU(const std::string& id, const std::string& type, int bedCount)
    : id(id), type(type), bedCount(bedCount), occupiedBeds(0), mortalityRate(15.0) {}

double ICU::calculateOccupancyRate() const {
    if (bedCount == 0) return 0.0;
    return (static_cast<double>(occupiedBeds) / bedCount) * 100.0;
}

bool ICU::canAdmitCriticalPatient() const {
    double occupancyRate = calculateOccupancyRate();
    bool hasAvailableBeds = occupiedBeds < bedCount;
    bool hasSpecializedNurses = !specializedNurses.empty();
    bool hasLifeSupport = false;
    
    for (const auto& equipment : lifeSupportEquipment) {
        if (equipment->getIsOperational() && equipment->getType() == "Life Support") {
            hasLifeSupport = true;
            break;
        }
    }
    
    bool adequateNurseRatio = false;
    if (!specializedNurses.empty()) {
        double nursePatientRatio = static_cast<double>(specializedNurses.size()) / (occupiedBeds + 1);
        adequateNurseRatio = nursePatientRatio >= 0.5; // At least 1 nurse per 2 patients
    }
    
    bool notOvercrowded = occupancyRate < 85.0;
    bool specializedICU = type == "Cardiac" || type == "Neurological" || type == "Surgical";
    
    return hasAvailableBeds && hasSpecializedNurses && hasLifeSupport && 
           adequateNurseRatio && notOvercrowded && specializedICU;
}

double ICU::calculatePatientSurvivalProbability() const {
    double baseProbability = 100.0 - mortalityRate;
    
    double nurseExpertiseProbability = 0.0;
    for (const auto& nurse : specializedNurses) {
        nurseExpertiseProbability += nurse->calculatePatientCareScore() * 0.1;
    }
    
    double equipmentReliabilityProbability = 0.0;
    for (const auto& equipment : lifeSupportEquipment) {
        if (equipment->getIsOperational()) {
            equipmentReliabilityProbability += 2.5;
        }
    }
    
    double patientStabilityProbability = 0.0;
    for (const auto& patient : criticalPatients) {
        if (patient->calculateHealthRiskScore() < 70.0) {
            patientStabilityProbability += 3.0;
        }
    }
    
    double occupancyProbability = (100.0 - calculateOccupancyRate()) * 0.2;
    double icuTypeProbability = type == "Cardiac" ? 8.0 : (type == "Neurological" ? 6.0 : 4.0);
    
    double totalProbability = baseProbability + nurseExpertiseProbability + equipmentReliabilityProbability + 
                             patientStabilityProbability + occupancyProbability + icuTypeProbability;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

void ICU::addCriticalPatient(Patient* patient) {
    if (patient && occupiedBeds < bedCount) {
        criticalPatients.push_back(patient);
        occupiedBeds++;
    }
}

void ICU::removeCriticalPatient(const std::string& patientId) {
    criticalPatients.erase(
        std::remove_if(criticalPatients.begin(), criticalPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        criticalPatients.end()
    );
    occupiedBeds = criticalPatients.size();
}

std::vector<Patient*> ICU::getCriticalPatients() const {
    return criticalPatients;
}

void ICU::addSpecializedNurse(Nurse* nurse) {
    if (nurse) {
        specializedNurses.push_back(nurse);
    }
}

void ICU::removeSpecializedNurse(const std::string& nurseId) {
    specializedNurses.erase(
        std::remove_if(specializedNurses.begin(), specializedNurses.end(),
            [&nurseId](Nurse* nurse) {
                return nurse->getId() == nurseId;
            }),
        specializedNurses.end()
    );
}

std::vector<Nurse*> ICU::getSpecializedNurses() const {
    return specializedNurses;
}

void ICU::addLifeSupportEquipment(MedicalEquipment* equipment) {
    if (equipment) {
        lifeSupportEquipment.push_back(equipment);
    }
}

void ICU::removeLifeSupportEquipment(const std::string& equipmentId) {
    lifeSupportEquipment.erase(
        std::remove_if(lifeSupportEquipment.begin(), lifeSupportEquipment.end(),
            [&equipmentId](MedicalEquipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        lifeSupportEquipment.end()
    );
}

std::vector<MedicalEquipment*> ICU::getLifeSupportEquipment() const {
    return lifeSupportEquipment;
}
