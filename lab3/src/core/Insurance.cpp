#include "Insurance.h"
#include "Patient.h"
#include "Billing.h"
#include <algorithm>
#include <cmath>

Insurance::Insurance(const std::string& id, const std::string& providerName, const std::string& planType)
    : id(id), providerName(providerName), planType(planType), coveragePercentage(80.0), annualLimit(10000.0), deductible(500.0) {}

double Insurance::calculateCoverageAmount(double medicalCost) const {
    double baseCoverage = medicalCost * (coveragePercentage / 100.0);
    
    double planMultiplier = 1.0;
    if (planType == "Premium") planMultiplier = 1.1;
    else if (planType == "Basic") planMultiplier = 0.9;
    
    double deductibleAdjustment = std::max(0.0, baseCoverage - deductible);
    
    double patientHealthFactor = 1.0;
    if (!coveredPatients.empty()) {
        double avgHealthRisk = 0.0;
        for (const auto& patient : coveredPatients) {
            avgHealthRisk += patient->calculateHealthRiskScore();
        }
        avgHealthRisk /= coveredPatients.size();
        patientHealthFactor = 1.0 - (avgHealthRisk * 0.005);
    }
    
    double annualUsageFactor = 1.0;
    double totalBilledAmount = 0.0;
    for (const auto& billing : processedBillings) {
        totalBilledAmount += billing->getTotalAmount();
    }
    if (totalBilledAmount > annualLimit * 0.8) {
        annualUsageFactor = 0.8;
    }
    
    double finalCoverage = deductibleAdjustment * planMultiplier * patientHealthFactor * annualUsageFactor;
    return std::min(finalCoverage, annualLimit - totalBilledAmount);
}

bool Insurance::isTreatmentCovered(const std::string& treatmentType) const {
    bool basicCoverage = treatmentType == "Emergency" || treatmentType == "Hospitalization" || 
                        treatmentType == "Surgery" || treatmentType == "Diagnostic";
    
    bool premiumCoverage = planType == "Premium" && 
                          (treatmentType == "Rehabilitation" || treatmentType == "Mental Health" ||
                           treatmentType == "Physical Therapy" || treatmentType == "Preventive");
    
    bool specializedCoverage = treatmentType == "Transplant" || treatmentType == "Cancer Treatment";
    
    bool hasAvailableLimit = true;
    double totalBilled = 0.0;
    for (const auto& billing : processedBillings) {
        totalBilled += billing->getTotalAmount();
    }
    if (totalBilled >= annualLimit) {
        hasAvailableLimit = false;
    }
    
    return (basicCoverage || premiumCoverage || specializedCoverage) && hasAvailableLimit;
}

double Insurance::calculatePatientResponsibility(double totalCost) const {
    double insuranceCoverage = calculateCoverageAmount(totalCost);
    double patientResponsibility = totalCost - insuranceCoverage;
    
    double deductibleAdjustment = patientResponsibility < deductible ? patientResponsibility : deductible;
    double remainingAfterDeductible = std::max(0.0, patientResponsibility - deductible);
    
    double coInsurance = remainingAfterDeductible * (1.0 - (coveragePercentage / 100.0));
    
    double finalResponsibility = deductibleAdjustment + coInsurance;
    return std::max(0.0, finalResponsibility);
}

void Insurance::addCoveredPatient(Patient* patient) {
    if (patient) {
        coveredPatients.push_back(patient);
    }
}

void Insurance::removeCoveredPatient(const std::string& patientId) {
    coveredPatients.erase(
        std::remove_if(coveredPatients.begin(), coveredPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        coveredPatients.end()
    );
}

std::vector<Patient*> Insurance::getCoveredPatients() const {
    return coveredPatients;
}

void Insurance::addProcessedBilling(Billing* billing) {
    if (billing) {
        processedBillings.push_back(billing);
    }
}

void Insurance::removeProcessedBilling(const std::string& billingId) {
    processedBillings.erase(
        std::remove_if(processedBillings.begin(), processedBillings.end(),
            [&billingId](Billing* billing) {
                return billing->getId() == billingId;
            }),
        processedBillings.end()
    );
}

std::vector<Billing*> Insurance::getProcessedBillings() const {
    return processedBillings;
}
