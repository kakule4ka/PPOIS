#include "Pediatrician.h"
#include "Patient.h"
#include "Vaccine.h"
#include <algorithm>
#include <cmath>

Pediatrician::Pediatrician(const std::string& id, const std::string& name, int experience, 
                          const std::string& license, int maxPatients, int cases, double vaxRate)
    : Doctor(id, name, "Pediatrics", experience, license, maxPatients),
      pediatricCases(cases), vaccinationRate(vaxRate), ageSpecialization("General Pediatrics") {}

double Pediatrician::calculateChildDevelopmentScore(const Patient* child) const {
    if (!child || child->getAge() > 18) return 0.0;
    
    double baseScore = 75.0;
    
    double ageAppropriateScore = 0.0;
    if (child->getAge() <= 5) {
        ageAppropriateScore = child->calculateBMI() > 0 ? 15.0 : 5.0;
    } else if (child->getAge() <= 12) {
        ageAppropriateScore = 12.0;
    } else {
        ageAppropriateScore = 8.0;
    }
    
    double healthScore = (100.0 - child->calculateHealthRiskScore()) * 0.3;
    double growthScore = child->getAge() * 1.2;
    
    double vaccinationScore = vaccinationRate * 0.2;
    double experienceScore = getExperienceYears() * 0.8;
    
    double totalScore = baseScore + ageAppropriateScore + healthScore + growthScore + vaccinationScore + experienceScore;
    return std::min(totalScore, 100.0);
}

bool Pediatrician::canHandleRarePediatricConditions() const {
    bool extensivePediatricExperience = getExperienceYears() >= 8;
    bool highCaseVolume = pediatricCases >= 150;
    bool specializedTraining = ageSpecialization != "General Pediatrics";
    bool comprehensiveVaccination = vaccinationRate >= 95.0;
    
    bool hasRareConditionExperience = pediatricCases > 300;
    bool advancedCertification = getExperienceYears() > 10;
    
    return (extensivePediatricExperience && highCaseVolume && specializedTraining) || 
           (comprehensiveVaccination && hasRareConditionExperience && advancedCertification);
}

double Pediatrician::calculatePreventiveCareEffectiveness() const {
    double baseEffectiveness = vaccinationRate;
    
    double experienceEffectiveness = getExperienceYears() * 1.5;
    double caseEffectiveness = pediatricCases * 0.1;
    
    double patientHealthEffectiveness = 0.0;
    for (const auto& patient : pediatricPatients) {
        if (patient->calculateHealthRiskScore() < 25.0) {
            patientHealthEffectiveness += 3.0;
        }
    }
    
    double vaccineEffectiveness = 0.0;
    for (const auto& vaccine : administeredVaccines) {
        if (vaccine->getEffectiveness() > 90.0) {
            vaccineEffectiveness += 2.5;
        }
    }
    
    double specializationEffectiveness = ageSpecialization == "Neonatology" ? 12.0 : 
                                       (ageSpecialization == "Adolescent Medicine" ? 8.0 : 5.0);
    
    double totalEffectiveness = baseEffectiveness + experienceEffectiveness + caseEffectiveness + 
                               patientHealthEffectiveness + vaccineEffectiveness + specializationEffectiveness;
    return std::min(totalEffectiveness, 100.0);
}

void Pediatrician::addPediatricPatient(Patient* patient) {
    if (patient && patient->getAge() <= 18) {
        pediatricPatients.push_back(patient);
    }
}

void Pediatrician::removePediatricPatient(const std::string& patientId) {
    pediatricPatients.erase(
        std::remove_if(pediatricPatients.begin(), pediatricPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        pediatricPatients.end()
    );
}

std::vector<Patient*> Pediatrician::getPediatricPatients() const {
    return pediatricPatients;
}

void Pediatrician::addAdministeredVaccine(Vaccine* vaccine) {
    if (vaccine) {
        administeredVaccines.push_back(vaccine);
    }
}

void Pediatrician::removeAdministeredVaccine(const std::string& vaccineId) {
    administeredVaccines.erase(
        std::remove_if(administeredVaccines.begin(), administeredVaccines.end(),
            [&vaccineId](Vaccine* vaccine) {
                return vaccine->getId() == vaccineId;
            }),
        administeredVaccines.end()
    );
}

std::vector<Vaccine*> Pediatrician::getAdministeredVaccines() const {
    return administeredVaccines;
}
