#include "EmergencyCase.h"
#include "Patient.h"
#include "Doctor.h"
#include "MedicalDepartment.h"
#include <algorithm>
#include <cmath>

EmergencyCase::EmergencyCase(const std::string& id, const std::string& description, int severityLevel)
    : id(id), description(description), severityLevel(severityLevel), arrivalTime(""), status("TRIAGE"), 
      treatmentDuration(0), patient(nullptr), assignedDoctor(nullptr), treatmentDepartment(nullptr) {}

double EmergencyCase::calculateUrgencyScore() const {
    double baseScore = severityLevel * 15.0;
    
    double descriptionScore = 0.0;
    if (description.find("cardiac") != std::string::npos || description.find("heart") != std::string::npos) {
        descriptionScore = 25.0;
    } else if (description.find("trauma") != std::string::npos || description.find("accident") != std::string::npos) {
        descriptionScore = 20.0;
    } else if (description.find("respiratory") != std::string::npos || description.find("breathing") != std::string::npos) {
        descriptionScore = 18.0;
    }
    
    double patientScore = patient ? patient->calculateHealthRiskScore() * 0.5 : 20.0;
    double timeFactor = treatmentDuration > 60 ? -10.0 : 5.0;
    
    double departmentScore = treatmentDepartment ? 10.0 : 0.0;
    double doctorScore = assignedDoctor ? assignedDoctor->calculatePatientSuccessRate() * 0.2 : 0.0;
    
    double totalScore = baseScore + descriptionScore + patientScore + timeFactor + departmentScore + doctorScore;
    return std::min(totalScore, 100.0);
}

bool EmergencyCase::requiresImmediateSurgery() const {
    bool criticalSeverity = severityLevel >= 4;
    bool lifeThreateningDescription = description.find("internal bleeding") != std::string::npos ||
                                     description.find("major trauma") != std::string::npos ||
                                     description.find("organ damage") != std::string::npos;
    
    bool patientCritical = patient && patient->calculateHealthRiskScore() > 80.0;
    bool hasSurgicalDepartment = treatmentDepartment && 
                                (treatmentDepartment->getSpecialization() == "Surgery" || 
                                 treatmentDepartment->getSpecialization() == "Trauma");
    
    bool qualifiedSurgeonAvailable = assignedDoctor && 
                                   (assignedDoctor->getSpecialization() == "Surgery" || 
                                    assignedDoctor->getSpecialization() == "Trauma") &&
                                   assignedDoctor->getExperienceYears() >= 5;
    
    return criticalSeverity || lifeThreateningDescription || (patientCritical && hasSurgicalDepartment && qualifiedSurgeonAvailable);
}

double EmergencyCase::calculateResourceAllocationPriority() const {
    double urgencyScore = calculateUrgencyScore();
    
    double departmentCapacity = treatmentDepartment ? treatmentDepartment->calculateUtilizationRate() : 100.0;
    double departmentAvailability = 100.0 - departmentCapacity;
    
    double doctorAvailability = assignedDoctor ? assignedDoctor->calculateWorkloadEfficiency() : 0.0;
    
    double patientStability = patient ? (100.0 - patient->calculateHealthRiskScore()) : 0.0;
    
    double timeCriticality = treatmentDuration > 30 ? 15.0 : 5.0;
    
    double totalPriority = (urgencyScore * 0.4) + (departmentAvailability * 0.2) + 
                          (doctorAvailability * 0.2) + (patientStability * 0.1) + timeCriticality;
    return std::min(totalPriority, 100.0);
}

void EmergencyCase::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* EmergencyCase::getPatient() const {
    return patient;
}

void EmergencyCase::setAssignedDoctor(Doctor* doctor) {
    this->assignedDoctor = doctor;
}

Doctor* EmergencyCase::getAssignedDoctor() const {
    return assignedDoctor;
}

void EmergencyCase::setTreatmentDepartment(MedicalDepartment* department) {
    this->treatmentDepartment = department;
}

MedicalDepartment* EmergencyCase::getTreatmentDepartment() const {
    return treatmentDepartment;
}
