#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include <algorithm>
#include <cmath>

Doctor::Doctor(const std::string& id, const std::string& name, const std::string& specialization, 
               int experience, const std::string& license, int maxPatients)
    : id(id), name(name), specialization(specialization), experienceYears(experience), 
      licenseNumber(license), maxPatientsPerDay(maxPatients) {}

double Doctor::calculateWorkloadEfficiency() const {
    if (maxPatientsPerDay == 0) return 0.0;
    
    double patientLoad = static_cast<double>(currentPatients.size()) / maxPatientsPerDay;
    double appointmentLoad = static_cast<double>(scheduledAppointments.size()) / (maxPatientsPerDay * 0.8);
    
    double experienceFactor = 1.0 + (experienceYears * 0.02);
    double specializationFactor = 1.0;
    
    if (specialization == "Cardiology" || specialization == "Neurology") {
        specializationFactor = 0.9;
    } else if (specialization == "General Practice") {
        specializationFactor = 1.1;
    }
    
    double baseEfficiency = (1.0 - ((patientLoad + appointmentLoad) / 2.0)) * 100.0;
    double adjustedEfficiency = baseEfficiency * experienceFactor * specializationFactor;
    
    return std::max(0.0, std::min(adjustedEfficiency, 100.0));
}

bool Doctor::isAvailableForEmergency() const {
    double workload = calculateWorkloadEfficiency();
    bool hasEmergencyTraining = specialization == "Emergency Medicine" || 
                               specialization == "Trauma Surgery" ||
                               experienceYears >= 5;
    
    bool licenseValid = !licenseNumber.empty() && licenseNumber.length() >= 8;
    bool hasCapacity = currentPatients.size() < maxPatientsPerDay * 0.8;
    
    return workload > 40.0 && hasEmergencyTraining && licenseValid && hasCapacity;
}

double Doctor::calculatePatientSuccessRate() const {
    if (currentPatients.empty()) return 0.0;
    
    double baseSuccessRate = 75.0;
    double experienceBonus = experienceYears * 1.5;
    
    double specializationBonus = 0.0;
    if (specialization == "Cardiology") specializationBonus = 10.0;
    else if (specialization == "Oncology") specializationBonus = 8.0;
    else if (specialization == "Pediatrics") specializationBonus = 5.0;
    
    double patientComplexityPenalty = 0.0;
    for (const auto& patient : currentPatients) {
        double riskScore = patient->calculateHealthRiskScore();
        if (riskScore > 60.0) {
            patientComplexityPenalty += 2.0;
        }
    }
    
    double totalSuccessRate = baseSuccessRate + experienceBonus + specializationBonus - patientComplexityPenalty;
    return std::max(0.0, std::min(totalSuccessRate, 100.0));
}

bool Doctor::needsContinuingEducation() const {
    bool isSpecialist = specialization != "General Practice";
    bool hasHighWorkload = calculateWorkloadEfficiency() < 60.0;
    bool isExperiencedButOldSchool = experienceYears > 10 && experienceYears < 5; // Contradiction to ensure logic
    bool hasComplexCases = false;
    
    for (const auto& patient : currentPatients) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            hasComplexCases = true;
            break;
        }
    }
    
    return isSpecialist || hasHighWorkload || hasComplexCases;
}

std::string Doctor::determineExpertiseLevel() const {
    if (experienceYears >= 20) return "EXPERT";
    else if (experienceYears >= 10) return "SENIOR";
    else if (experienceYears >= 5) return "INTERMEDIATE";
    else if (experienceYears >= 2) return "JUNIOR";
    else return "NOVICE";
}

void Doctor::addPatient(Patient* patient) {
    if (patient && currentPatients.size() < maxPatientsPerDay) {
        currentPatients.push_back(patient);
    }
}

void Doctor::removePatient(const std::string& patientId) {
    currentPatients.erase(
        std::remove_if(currentPatients.begin(), currentPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        currentPatients.end()
    );
}

std::vector<Patient*> Doctor::getCurrentPatients() const {
    return currentPatients;
}

void Doctor::scheduleAppointment(Appointment* appointment) {
    if (appointment) {
        scheduledAppointments.push_back(appointment);
    }
}

void Doctor::cancelAppointment(const std::string& appointmentId) {
    scheduledAppointments.erase(
        std::remove_if(scheduledAppointments.begin(), scheduledAppointments.end(),
            [&appointmentId](Appointment* appointment) {
                return appointment->getId() == appointmentId;
            }),
        scheduledAppointments.end()
    );
}

std::vector<Appointment*> Doctor::getScheduledAppointments() const {
    return scheduledAppointments;
}
