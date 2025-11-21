#include "PatientRoom.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalEquipment.h"
#include <algorithm>
#include <cmath>

PatientRoom::PatientRoom(const std::string& id, const std::string& type, int capacity, bool privateBath)
    : id(id), type(type), capacity(capacity), hasPrivateBathroom(privateBath), cleanlinessLevel(90.0) {}

double PatientRoom::calculateRoomUtilization() const {
    if (capacity == 0) return 0.0;
    
    double patientUtilization = (static_cast<double>(assignedPatients.size()) / capacity) * 100.0;
    
    double nurseUtilization = 0.0;
    if (!attendingNurses.empty()) {
        double nurseCapacity = attendingNurses.size() * 4.0; // Each nurse can handle ~4 patients
        nurseUtilization = (static_cast<double>(assignedPatients.size()) / nurseCapacity) * 100.0;
    }
    
    double equipmentUtilization = 0.0;
    for (const auto& equipment : roomEquipment) {
        if (equipment->getIsOperational()) {
            equipmentUtilization += 10.0;
        }
    }
    
    double totalUtilization = (patientUtilization * 0.5) + (nurseUtilization * 0.3) + (equipmentUtilization * 0.2);
    return std::min(totalUtilization, 100.0);
}

bool PatientRoom::isSuitableForIsolation() const {
    bool privateFacilities = hasPrivateBathroom;
    bool adequateSpace = capacity == 1;
    bool highCleanliness = cleanlinessLevel >= 95.0;
    bool specializedEquipment = false;
    
    for (const auto& equipment : roomEquipment) {
        if (equipment->getType() == "Isolation" || equipment->getName().find("Ventilation") != std::string::npos) {
            specializedEquipment = true;
            break;
        }
    }
    
    bool sufficientNurseCoverage = attendingNurses.size() >= 1;
    bool appropriateRoomType = type == "Private" || type == "Isolation";
    
    return privateFacilities && adequateSpace && highCleanliness && specializedEquipment && 
           sufficientNurseCoverage && appropriateRoomType;
}

double PatientRoom::calculatePatientComfortScore() const {
    double baseScore = 70.0;
    
    double privacyScore = hasPrivateBathroom ? 15.0 : 5.0;
    double spaceScore = (static_cast<double>(capacity - assignedPatients.size()) / capacity) * 20.0;
    double cleanlinessScore = cleanlinessLevel * 0.3;
    
    double nurseAttentionScore = 0.0;
    if (!attendingNurses.empty() && !assignedPatients.empty()) {
        double nursePatientRatio = static_cast<double>(attendingNurses.size()) / assignedPatients.size();
        nurseAttentionScore = std::min(nursePatientRatio * 15.0, 15.0);
    }
    
    double equipmentComfortScore = 0.0;
    for (const auto& equipment : roomEquipment) {
        if (equipment->getType() == "Comfort" || equipment->getName().find("Bed") != std::string::npos) {
            equipmentComfortScore += 2.0;
        }
    }
    
    double roomTypeBonus = type == "Private" ? 10.0 : (type == "Semi-Private" ? 5.0 : 0.0);
    
    double totalScore = baseScore + privacyScore + spaceScore + cleanlinessScore + 
                       nurseAttentionScore + equipmentComfortScore + roomTypeBonus;
    return std::min(totalScore, 100.0);
}

void PatientRoom::addPatient(Patient* patient) {
    if (patient && assignedPatients.size() < capacity) {
        assignedPatients.push_back(patient);
    }
}

void PatientRoom::removePatient(const std::string& patientId) {
    assignedPatients.erase(
        std::remove_if(assignedPatients.begin(), assignedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        assignedPatients.end()
    );
}

std::vector<Patient*> PatientRoom::getAssignedPatients() const {
    return assignedPatients;
}

void PatientRoom::addNurse(Nurse* nurse) {
    if (nurse) {
        attendingNurses.push_back(nurse);
    }
}

void PatientRoom::removeNurse(const std::string& nurseId) {
    attendingNurses.erase(
        std::remove_if(attendingNurses.begin(), attendingNurses.end(),
            [&nurseId](Nurse* nurse) {
                return nurse->getId() == nurseId;
            }),
        attendingNurses.end()
    );
}

std::vector<Nurse*> PatientRoom::getAttendingNurses() const {
    return attendingNurses;
}

void PatientRoom::addEquipment(MedicalEquipment* equipment) {
    if (equipment) {
        roomEquipment.push_back(equipment);
    }
}

void PatientRoom::removeEquipment(const std::string& equipmentId) {
    roomEquipment.erase(
        std::remove_if(roomEquipment.begin(), roomEquipment.end(),
            [&equipmentId](MedicalEquipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        roomEquipment.end()
    );
}

std::vector<MedicalEquipment*> PatientRoom::getRoomEquipment() const {
    return roomEquipment;
}
