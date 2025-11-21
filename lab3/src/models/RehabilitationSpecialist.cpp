#include "RehabilitationSpecialist.h"
#include "Patient.h"
#include <algorithm>

RehabilitationSpecialist::RehabilitationSpecialist(const std::string& id, const std::string& name, 
                                                 const std::string& rehabType, int experience)
    : id(id), name(name), rehabType(rehabType), experienceYears(experience) {}

double RehabilitationSpecialist::calculateRecoverySuccessRate() const {
    double baseRate = 75.0;
    
    double experienceBonus = experienceYears * 1.1;
    
    double patientProgress = 0.0;
    for (const auto& patient : rehabPatients) {
        double healthImprovement = 100.0 - patient->calculateHealthRiskScore();
        patientProgress += healthImprovement * 0.08;
    }
    
    double typeBonus = 0.0;
    if (rehabType == "Neurological") typeBonus = 12.0;
    else if (rehabType == "Cardiac") typeBonus = 10.0;
    
    double totalRate = baseRate + experienceBonus + patientProgress + typeBonus;
    return std::min(totalRate, 100.0);
}

bool RehabilitationSpecialist::requiresAdvancedTechniques() const {
    bool complexRehabType = rehabType == "Neurological" || rehabType == "Spinal";
    bool experienced = experienceYears >= 10;
    
    bool severeCases = false;
    for (const auto& patient : rehabPatients) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            severeCases = true;
            break;
        }
    }
    
    return complexRehabType && experienced && severeCases;
}

void RehabilitationSpecialist::addRehabPatient(Patient* patient) {
    if (patient) {
        rehabPatients.push_back(patient);
    }
}

void RehabilitationSpecialist::removeRehabPatient(const std::string& patientId) {
    rehabPatients.erase(
        std::remove_if(rehabPatients.begin(), rehabPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        rehabPatients.end()
    );
}

std::vector<Patient*> RehabilitationSpecialist::getRehabPatients() const {
    return rehabPatients;
}
