#include "Rehabilitation.h"
#include "Patient.h"
#include "PhysicalTherapist.h"
#include "TreatmentPlan.h"
#include <algorithm>
#include <cmath>

Rehabilitation::Rehabilitation(const std::string& id, const std::string& type, int duration)
    : id(id), type(type), durationWeeks(duration), successRate(75.0) {}

double Rehabilitation::calculateRecoveryProbability() const {
    double baseProbability = successRate;
    
    double durationProbability = durationWeeks * 1.2;
    
    double therapistProbability = 0.0;
    for (const auto& therapist : assignedTherapists) {
        therapistProbability += therapist->calculateTherapyEffectiveness() * 0.2;
    }
    
    double patientMotivationProbability = 0.0;
    for (const auto& patient : rehabPatients) {
        if (patient->calculateHealthRiskScore() < 50.0) {
            patientMotivationProbability += 3.0;
        }
    }
    
    double planProbability = 0.0;
    for (const auto& plan : rehabPlans) {
        if (plan->calculateTreatmentEffectiveness() > 70.0) {
            planProbability += 2.0;
        }
    }
    
    double rehabTypeProbability = 0.0;
    if (type == "Neurological") rehabTypeProbability = 12.0;
    else if (type == "Orthopedic") rehabTypeProbability = 10.0;
    else if (type == "Cardiac") rehabTypeProbability = 8.0;
    
    double totalProbability = baseProbability + durationProbability + therapistProbability + 
                             patientMotivationProbability + planProbability + rehabTypeProbability;
    return std::min(totalProbability, 100.0);
}

bool Rehabilitation::requiresIntensiveTherapy() const {
    bool complexRehabType = type == "Neurological" || type == "Spinal Cord";
    bool longDuration = durationWeeks >= 12;
    
    bool severeCases = false;
    for (const auto& patient : rehabPatients) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            severeCases = true;
            break;
        }
    }
    
    bool specializedTherapists = false;
    for (const auto& therapist : assignedTherapists) {
        if (therapist->getSpecialization() == type) {
            specializedTherapists = true;
            break;
        }
    }
    
    bool comprehensivePlans = false;
    for (const auto& plan : rehabPlans) {
        if (plan->determineComplexityLevel() == "HIGH") {
            comprehensivePlans = true;
            break;
        }
    }
    
    return complexRehabType || longDuration || 
           (severeCases && specializedTherapists && comprehensivePlans);
}

double Rehabilitation::calculateFunctionalImprovement() const {
    double baseImprovement = successRate * 0.8;
    
    double therapistImprovement = 0.0;
    for (const auto& therapist : assignedTherapists) {
        therapistImprovement += therapist->getExperienceYears() * 0.8;
    }
    
    double patientImprovement = 0.0;
    for (const auto& patient : rehabPatients) {
        double healthImprovement = 100.0 - patient->calculateHealthRiskScore();
        patientImprovement += healthImprovement * 0.1;
    }
    
    double planImprovement = 0.0;
    for (const auto& plan : rehabPlans) {
        if (plan->calculateAdherenceProbability() > 75.0) {
            planImprovement += 4.0;
        }
    }
    
    double durationImprovement = durationWeeks * 0.5;
    
    double typeImprovement = 0.0;
    if (type == "Sports") typeImprovement = 15.0;
    else if (type == "Occupational") typeImprovement = 12.0;
    else if (type == "Geriatric") typeImprovement = 10.0;
    
    double totalImprovement = baseImprovement + therapistImprovement + patientImprovement + 
                             planImprovement + durationImprovement + typeImprovement;
    return std::min(totalImprovement, 100.0);
}

void Rehabilitation::addRehabPatient(Patient* patient) {
    if (patient) {
        rehabPatients.push_back(patient);
    }
}

void Rehabilitation::removeRehabPatient(const std::string& patientId) {
    rehabPatients.erase(
        std::remove_if(rehabPatients.begin(), rehabPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        rehabPatients.end()
    );
}

std::vector<Patient*> Rehabilitation::getRehabPatients() const {
    return rehabPatients;
}

void Rehabilitation::addAssignedTherapist(PhysicalTherapist* therapist) {
    if (therapist) {
        assignedTherapists.push_back(therapist);
    }
}

void Rehabilitation::removeAssignedTherapist(const std::string& therapistId) {
    assignedTherapists.erase(
        std::remove_if(assignedTherapists.begin(), assignedTherapists.end(),
            [&therapistId](PhysicalTherapist* therapist) {
                return therapist->getId() == therapistId;
            }),
        assignedTherapists.end()
    );
}

std::vector<PhysicalTherapist*> Rehabilitation::getAssignedTherapists() const {
    return assignedTherapists;
}

void Rehabilitation::addRehabPlan(TreatmentPlan* plan) {
    if (plan) {
        rehabPlans.push_back(plan);
    }
}

void Rehabilitation::removeRehabPlan(const std::string& planId) {
    rehabPlans.erase(
        std::remove_if(rehabPlans.begin(), rehabPlans.end(),
            [&planId](TreatmentPlan* plan) {
                return plan->getId() == planId;
            }),
        rehabPlans.end()
    );
}

std::vector<TreatmentPlan*> Rehabilitation::getRehabPlans() const {
    return rehabPlans;
}
