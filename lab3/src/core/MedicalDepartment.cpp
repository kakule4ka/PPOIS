#include "MedicalDepartment.h"
#include "Doctor.h"
#include "Patient.h"
#include <algorithm>
#include <cmath>

MedicalDepartment::MedicalDepartment(const std::string& id, const std::string& name, const std::string& specialization)
    : id(id), name(name), specialization(specialization), capacity(0), currentPatients(0), budget(0.0), operationalStatus(true) {}

double MedicalDepartment::calculateUtilizationRate() const {
    if (capacity == 0) return 0.0;
    
    double patientUtilization = (static_cast<double>(currentPatients) / capacity) * 100.0;
    
    double doctorUtilization = 0.0;
    if (!doctors.empty()) {
        int availableDoctors = 0;
        for (const auto& doctor : doctors) {
            if (doctor->isAvailableForEmergency()) {
                availableDoctors++;
            }
        }
        doctorUtilization = (static_cast<double>(availableDoctors) / doctors.size()) * 100.0;
    }
    
    double equipmentUtilization = operationalStatus ? 80.0 : 20.0;
    
    double totalUtilization = (patientUtilization * 0.5) + (doctorUtilization * 0.3) + (equipmentUtilization * 0.2);
    return std::min(totalUtilization, 100.0);
}

bool MedicalDepartment::canHandleEmergency() const {
    double utilization = calculateUtilizationRate();
    bool hasSpecializedDoctors = false;
    
    for (const auto& doctor : doctors) {
        if (doctor->getSpecialization() == specialization && doctor->getExperienceYears() >= 3) {
            hasSpecializedDoctors = true;
            break;
        }
    }
    
    bool hasCapacity = currentPatients < capacity * 0.8;
    bool isFullyOperational = operationalStatus && budget > 10000.0;
    
    return utilization < 85.0 && hasSpecializedDoctors && hasCapacity && isFullyOperational;
}

double MedicalDepartment::calculateEfficiencyScore() const {
    double baseScore = 65.0;
    
    double utilizationBonus = calculateUtilizationRate() * 0.3;
    double doctorBonus = doctors.size() * 2.0;
    double budgetEfficiency = budget > 0 ? (10000.0 / budget) * 10.0 : 0.0;
    double patientOutcomeBonus = 0.0;
    
    for (const auto& patient : admittedPatients) {
        if (patient->calculateHealthRiskScore() < 30.0) {
            patientOutcomeBonus += 2.0;
        }
    }
    
    double specializationBonus = 0.0;
    if (specialization == "Emergency") specializationBonus = 15.0;
    else if (specialization == "ICU") specializationBonus = 12.0;
    else if (specialization == "Surgery") specializationBonus = 10.0;
    
    double totalScore = baseScore + utilizationBonus + doctorBonus + budgetEfficiency + patientOutcomeBonus + specializationBonus;
    return std::min(totalScore, 100.0);
}

bool MedicalDepartment::needsAdditionalStaff() const {
    double utilization = calculateUtilizationRate();
    double efficiency = calculateEfficiencyScore();
    
    bool highUtilization = utilization > 85.0;
    bool lowEfficiency = efficiency < 60.0;
    bool doctorPatientRatio = doctors.size() < (currentPatients / 5);
    bool expandingCapacity = capacity < currentPatients * 1.2;
    bool complexSpecialization = specialization == "ICU" || specialization == "Emergency" || specialization == "Oncology";
    
    return highUtilization || lowEfficiency || doctorPatientRatio || expandingCapacity || complexSpecialization;
}

void MedicalDepartment::addDoctor(Doctor* doctor) {
    if (doctor) {
        doctors.push_back(doctor);
    }
}

void MedicalDepartment::removeDoctor(const std::string& doctorId) {
    doctors.erase(
        std::remove_if(doctors.begin(), doctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        doctors.end()
    );
}

std::vector<Doctor*> MedicalDepartment::getDoctors() const {
    return doctors;
}

void MedicalDepartment::admitPatient(Patient* patient) {
    if (patient && currentPatients < capacity) {
        admittedPatients.push_back(patient);
        currentPatients++;
    }
}

void MedicalDepartment::dischargePatient(const std::string& patientId) {
    admittedPatients.erase(
        std::remove_if(admittedPatients.begin(), admittedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        admittedPatients.end()
    );
    currentPatients = admittedPatients.size();
}

std::vector<Patient*> MedicalDepartment::getAdmittedPatients() const {
    return admittedPatients;
}
