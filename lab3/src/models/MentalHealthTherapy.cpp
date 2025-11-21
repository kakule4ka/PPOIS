#include "MentalHealthTherapy.h"
#include "Patient.h"
#include "TreatmentPlan.h"
#include <algorithm>
#include <cmath>

MentalHealthTherapy::MentalHealthTherapy(const std::string& id, const std::string& therapyType, int duration)
    : id(id), therapyType(therapyType), sessionDuration(duration), successRate(70.0) {}

double MentalHealthTherapy::calculateTherapeuticOutcome() const {
    double baseOutcome = successRate;
    
    double durationOutcome = sessionDuration * 0.8;
    
    double patientOutcome = 0.0;
    for (const auto& patient : mentalHealthPatients) {
        if (patient->calculateHealthRiskScore() < 45.0) {
            patientOutcome += 2.5;
        }
    }
    
    double planOutcome = 0.0;
    for (const auto& plan : therapyPlans) {
        if (plan->calculateTreatmentEffectiveness() > 75.0) {
            planOutcome += 3.0;
        }
    }
    
    double therapyTypeOutcome = 0.0;
    if (therapyType == "CBT") therapyTypeOutcome = 12.0;
    else if (therapyType == "DBT") therapyTypeOutcome = 10.0;
    else if (therapyType == "Psychodynamic") therapyTypeOutcome = 8.0;
    
    double adherenceOutcome = 0.0;
    for (const auto& plan : therapyPlans) {
        adherenceOutcome += plan->calculateAdherenceProbability() * 0.1;
    }
    
    double totalOutcome = baseOutcome + durationOutcome + patientOutcome + 
                         planOutcome + therapyTypeOutcome + adherenceOutcome;
    return std::min(totalOutcome, 100.0);
}

bool MentalHealthTherapy::requiresSpecializedApproach() const {
    bool complexTherapyType = therapyType == "Trauma" || therapyType == "Addiction";
    bool longSessions = sessionDuration >= 90;
    
    bool severeCases = false;
    for (const auto& patient : mentalHealthPatients) {
        if (patient->calculateHealthRiskScore() > 75.0) {
            severeCases = true;
            break;
        }
    }
    
    bool comprehensivePlans = false;
    for (const auto& plan : therapyPlans) {
        if (plan->determineComplexityLevel() == "HIGH") {
            comprehensivePlans = true;
            break;
        }
    }
    
    bool multiplePatients = mentalHealthPatients.size() >= 10;
    bool lowSuccessRate = successRate < 60.0;
    
    return complexTherapyType || longSessions || 
           (severeCases && comprehensivePlans && multiplePatients && lowSuccessRate);
}

double MentalHealthTherapy::calculatePatientEngagement() const {
    if (mentalHealthPatients.empty()) return 0.0;
    
    double baseEngagement = 65.0;
    
    double durationEngagement = sessionDuration * 0.5;
    
    double patientEngagement = 0.0;
    for (const auto& patient : mentalHealthPatients) {
        double healthEngagement = 100.0 - patient->calculateHealthRiskScore();
        patientEngagement += healthEngagement * 0.08;
    }
    
    double planEngagement = 0.0;
    for (const auto& plan : therapyPlans) {
        planEngagement += plan->calculateAdherenceProbability() * 0.15;
    }
    
    double therapyTypeEngagement = 0.0;
    if (therapyType == "Group") therapyTypeEngagement = 15.0;
    else if (therapyType == "Family") therapyTypeEngagement = 12.0;
    else if (therapyType == "Individual") therapyTypeEngagement = 10.0;
    
    double successEngagement = successRate * 0.2;
    
    double totalEngagement = baseEngagement + durationEngagement + patientEngagement + 
                            planEngagement + therapyTypeEngagement + successEngagement;
    return std::min(totalEngagement, 100.0);
}

void MentalHealthTherapy::addMentalHealthPatient(Patient* patient) {
    if (patient) {
        mentalHealthPatients.push_back(patient);
    }
}

void MentalHealthTherapy::removeMentalHealthPatient(const std::string& patientId) {
    mentalHealthPatients.erase(
        std::remove_if(mentalHealthPatients.begin(), mentalHealthPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        mentalHealthPatients.end()
    );
}

std::vector<Patient*> MentalHealthTherapy::getMentalHealthPatients() const {
    return mentalHealthPatients;
}

void MentalHealthTherapy::addTherapyPlan(TreatmentPlan* plan) {
    if (plan) {
        therapyPlans.push_back(plan);
    }
}

void MentalHealthTherapy::removeTherapyPlan(const std::string& planId) {
    therapyPlans.erase(
        std::remove_if(therapyPlans.begin(), therapyPlans.end(),
            [&planId](TreatmentPlan* plan) {
                return plan->getId() == planId;
            }),
        therapyPlans.end()
    );
}

std::vector<TreatmentPlan*> MentalHealthTherapy::getTherapyPlans() const {
    return therapyPlans;
}
