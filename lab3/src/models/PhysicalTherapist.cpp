#include "PhysicalTherapist.h"
#include "Patient.h"
#include <algorithm>

PhysicalTherapist::PhysicalTherapist(const std::string& id, const std::string& name, 
                                   const std::string& specialization, int experience)
    : id(id), name(name), specialization(specialization), experienceYears(experience) {}

double PhysicalTherapist::calculateTherapyEffectiveness() const {
    double baseEffectiveness = 70.0;
    
    double experienceBonus = experienceYears * 1.2;
    
    double patientImprovement = 0.0;
    for (const auto& patient : therapyPatients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientImprovement += 3.0;
        }
    }
    
    double specializationBonus = 0.0;
    if (specialization == "Orthopedic") specializationBonus = 12.0;
    else if (specialization == "Neurological") specializationBonus = 15.0;
    
    double totalEffectiveness = baseEffectiveness + experienceBonus + patientImprovement + specializationBonus;
    return std::min(totalEffectiveness, 100.0);
}

bool PhysicalTherapist::canHandleComplexCases() const {
    bool extensiveExperience = experienceYears >= 8;
    bool specializedTraining = specialization == "Neurological" || specialization == "Spinal";
    
    bool complexPatientCases = false;
    for (const auto& patient : therapyPatients) {
        if (patient->calculateHealthRiskScore() > 65.0) {
            complexPatientCases = true;
            break;
        }
    }
    
    return extensiveExperience && specializedTraining && complexPatientCases;
}

void PhysicalTherapist::addTherapyPatient(Patient* patient) {
    if (patient) {
        therapyPatients.push_back(patient);
    }
}

void PhysicalTherapist::removeTherapyPatient(const std::string& patientId) {
    therapyPatients.erase(
        std::remove_if(therapyPatients.begin(), therapyPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        therapyPatients.end()
    );
}

std::vector<Patient*> PhysicalTherapist::getTherapyPatients() const {
    return therapyPatients;
}
