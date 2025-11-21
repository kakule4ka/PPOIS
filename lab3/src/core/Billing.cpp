#include "Billing.h"
#include "Patient.h"
#include "TreatmentPlan.h"
#include "Insurance.h"
#include <algorithm>
#include <cmath>

Billing::Billing(const std::string& id, const std::string& patientId, double totalAmount)
    : id(id), patientId(patientId), totalAmount(totalAmount), paidAmount(0.0), status("PENDING"), 
      billingDate(""), patient(nullptr), insurance(nullptr) {}

double Billing::calculateOutstandingBalance() const {
    double baseBalance = totalAmount - paidAmount;
    
    double insuranceDeduction = 0.0;
    if (insurance) {
        insuranceDeduction = insurance->calculateCoverageAmount(totalAmount);
    }
    
    double patientResponsibility = baseBalance - insuranceDeduction;
    
    double treatmentPlanAdjustment = 0.0;
    for (const auto& plan : treatmentPlans) {
        if (plan->getIsActive()) {
            treatmentPlanAdjustment += plan->getCost() * 0.1;
        }
    }
    
    double finalBalance = std::max(0.0, patientResponsibility - treatmentPlanAdjustment);
    return finalBalance;
}

bool Billing::isEligibleForDiscount() const {
    double outstandingBalance = calculateOutstandingBalance();
    bool highBalance = outstandingBalance > 5000.0;
    bool longTermPatient = patient && patient->calculateHealthRiskScore() > 60.0;
    bool multipleTreatmentPlans = treatmentPlans.size() >= 3;
    bool hasInsurance = insurance != nullptr;
    bool lowIncomeIndicator = patient && patient->getAge() > 65;
    
    return (highBalance && longTermPatient) || (multipleTreatmentPlans && !hasInsurance) || lowIncomeIndicator;
}

double Billing::calculateInsuranceCoverage() const {
    if (!insurance) return 0.0;
    
    double baseCoverage = insurance->calculateCoverageAmount(totalAmount);
    
    double patientFactor = patient ? (100.0 - patient->calculateHealthRiskScore()) * 0.1 : 0.0;
    
    double treatmentComplexityFactor = 0.0;
    for (const auto& plan : treatmentPlans) {
        if (plan->determineComplexityLevel() == "HIGH") {
            treatmentComplexityFactor += 5.0;
        }
    }
    
    double paymentHistoryFactor = paidAmount > 0 ? 3.0 : 0.0;
    
    double totalCoverage = baseCoverage + patientFactor + treatmentComplexityFactor + paymentHistoryFactor;
    return std::min(totalCoverage, totalAmount);
}

void Billing::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* Billing::getPatient() const {
    return patient;
}

void Billing::addTreatmentPlan(TreatmentPlan* plan) {
    if (plan) {
        treatmentPlans.push_back(plan);
    }
}

void Billing::removeTreatmentPlan(const std::string& planId) {
    treatmentPlans.erase(
        std::remove_if(treatmentPlans.begin(), treatmentPlans.end(),
            [&planId](TreatmentPlan* plan) {
                return plan->getId() == planId;
            }),
        treatmentPlans.end()
    );
}

std::vector<TreatmentPlan*> Billing::getTreatmentPlans() const {
    return treatmentPlans;
}

void Billing::setInsurance(Insurance* insurance) {
    this->insurance = insurance;
}

Insurance* Billing::getInsurance() const {
    return insurance;
}
