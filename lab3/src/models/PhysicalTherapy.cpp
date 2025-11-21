#include "PhysicalTherapy.h"
#include "Patient.h"
#include "Rehabilitation.h"
#include <algorithm>
#include <cmath>

PhysicalTherapy::PhysicalTherapy(const std::string& id, const std::string& name, const std::string& specialization, int experience)
    : id(id), name(name), specialization(specialization), experienceYears(experience), sessionsPerWeek(3) {}

double PhysicalTherapy::calculateTherapyEffectiveness() const {
    double baseEffectiveness = 70.0;
    
    double experienceEffectiveness = experienceYears * 1.5;
    double sessionEffectiveness = sessionsPerWeek * 2.0;
    
    double patientEffectiveness = 0.0;
    for (const auto& patient : therapyPatients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientEffectiveness += 3.0;
        }
    }
    
    double rehabEffectiveness = 0.0;
    for (const auto& rehab : rehabPrograms) {
        rehabEffectiveness += rehab->calculateFunctionalImprovement() * 0.1;
    }
    
    double specializationEffectiveness = 0.0;
    if (specialization == "Orthopedic") specializationEffectiveness = 12.0;
    else if (specialization == "Neurological") specializationEffectiveness = 15.0;
    else if (specialization == "Sports") specializationEffectiveness = 10.0;
    
    double totalEffectiveness = baseEffectiveness + experienceEffectiveness + sessionEffectiveness + 
                               patientEffectiveness + rehabEffectiveness + specializationEffectiveness;
    return std::min(totalEffectiveness, 100.0);
}

bool PhysicalTherapy::canHandleComplexCases() const {
    bool extensiveExperience = experienceYears >= 8;
    bool highSessionFrequency = sessionsPerWeek >= 4;
    bool specializedTraining = specialization == "Neurological" || specialization == "Spinal";
    
    bool complexPatientCases = false;
    for (const auto& patient : therapyPatients) {
        if (patient->calculateHealthRiskScore() > 65.0) {
            complexPatientCases = true;
            break;
        }
    }
    
    bool advancedRehabPrograms = false;
    for (const auto& rehab : rehabPrograms) {
        if (rehab->requiresIntensiveTherapy()) {
            advancedRehabPrograms = true;
            break;
        }
    }
    
    return extensiveExperience && highSessionFrequency && specializedTraining && 
           complexPatientCases && advancedRehabPrograms;
}

double PhysicalTherapy::calculatePatientProgressRate() const {
    if (therapyPatients.empty()) return 0.0;
    
    double baseProgress = 60.0;
    
    double experienceProgress = experienceYears * 1.2;
    double sessionProgress = sessionsPerWeek * 1.5;
    
    double patientProgress = 0.0;
    for (const auto& patient : therapyPatients) {
        double healthImprovement = 100.0 - patient->calculateHealthRiskScore();
        patientProgress += healthImprovement * 0.05;
    }
    
    double rehabProgress = 0.0;
    for (const auto& rehab : rehabPrograms) {
        rehabProgress += rehab->calculateRecoveryProbability() * 0.08;
    }
    
    double specializationProgress = 0.0;
    if (specialization == "Pediatric") specializationProgress = 8.0;
    else if (specialization == "Geriatric") specializationProgress = 6.0;
    
    double totalProgress = baseProgress + experienceProgress + sessionProgress + 
                          patientProgress + rehabProgress + specializationProgress;
    return std::min(totalProgress, 100.0);
}

void PhysicalTherapy::addTherapyPatient(Patient* patient) {
    if (patient) {
        therapyPatients.push_back(patient);
    }
}

void PhysicalTherapy::removeTherapyPatient(const std::string& patientId) {
    therapyPatients.erase(
        std::remove_if(therapyPatients.begin(), therapyPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        therapyPatients.end()
    );
}

std::vector<Patient*> PhysicalTherapy::getTherapyPatients() const {
    return therapyPatients;
}

void PhysicalTherapy::addRehabProgram(Rehabilitation* rehab) {
    if (rehab) {
        rehabPrograms.push_back(rehab);
    }
}

void PhysicalTherapy::removeRehabProgram(const std::string& rehabId) {
    rehabPrograms.erase(
        std::remove_if(rehabPrograms.begin(), rehabPrograms.end(),
            [&rehabId](Rehabilitation* rehab) {
                return rehab->getId() == rehabId;
            }),
        rehabPrograms.end()
    );
}

std::vector<Rehabilitation*> PhysicalTherapy::getRehabPrograms() const {
    return rehabPrograms;
}
