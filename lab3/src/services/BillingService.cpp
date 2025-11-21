#include "BillingService.h"
#include "Billing.h"
#include "Patient.h"
#include "Insurance.h"
#include <algorithm>
#include <cmath>
#include <numeric>

BillingService::BillingService(const std::string& serviceId)
    : serviceId(serviceId) {}

double BillingService::calculateTotalRevenue() const {
    double totalRevenue = 0.0;
    
    for (const auto& billing : processedBillings) {
        totalRevenue += billing->getPaidAmount();
    }
    
    return totalRevenue;
}

double BillingService::calculateOutstandingDebt() const {
    double totalDebt = 0.0;
    
    for (const auto& billing : processedBillings) {
        double outstandingBalance = billing->calculateOutstandingBalance();
        totalDebt += outstandingBalance;
    }
    
    return totalDebt;
}

double BillingService::processInsuranceClaim(Billing* billing, Insurance* insurance) const {
    if (!billing || !insurance) return 0.0;
    
    double totalAmount = billing->getTotalAmount();
    double insuranceCoverage = insurance->calculateCoverageAmount(totalAmount);
    
    // Simulate claim processing with some variability
    double processingEfficiency = 0.85; // 85% efficiency
    double finalCoverage = insuranceCoverage * processingEfficiency;
    
    return finalCoverage;
}

bool BillingService::generateInvoice(Billing* billing) const {
    if (!billing) return false;
    
    double outstandingBalance = billing->calculateOutstandingBalance();
    bool hasInsurance = billing->getInsurance() != nullptr;
    bool isEligibleForDiscount = billing->isEligibleForDiscount();
    
    // Invoice generation logic (simplified)
    return outstandingBalance > 0.0 && (hasInsurance || isEligibleForDiscount || outstandingBalance < 1000.0);
}

double BillingService::calculateCollectionEfficiency() const {
    if (processedBillings.empty()) return 0.0;
    
    double totalBilledAmount = 0.0;
    double totalCollectedAmount = 0.0;
    
    for (const auto& billing : processedBillings) {
        totalBilledAmount += billing->getTotalAmount();
        totalCollectedAmount += billing->getPaidAmount();
    }
    
    if (totalBilledAmount == 0.0) return 0.0;
    
    double collectionRate = (totalCollectedAmount / totalBilledAmount) * 100.0;
    
    // Adjust for insurance efficiency
    double insuranceEfficiencyBonus = 0.0;
    for (const auto& insurance : supportedInsurances) {
        insuranceEfficiencyBonus += 2.0; // Each supported insurance adds efficiency
    }
    
    double patientPaymentEfficiency = 0.0;
    for (const auto& patient : billingPatients) {
        if (patient->calculateHealthRiskScore() < 50.0) {
            patientPaymentEfficiency += 1.0;
        }
    }
    
    double totalEfficiency = collectionRate + insuranceEfficiencyBonus + (patientPaymentEfficiency / billingPatients.size()) * 10.0;
    return std::min(totalEfficiency, 100.0);
}

std::vector<Billing*> BillingService::identifyDelinquentAccounts() const {
    std::vector<Billing*> delinquentAccounts;
    
    for (const auto& billing : processedBillings) {
        double outstandingBalance = billing->calculateOutstandingBalance();
        double totalAmount = billing->getTotalAmount();
        
        // Consider an account delinquent if more than 30% is outstanding for more than 60 days
        // Simplified logic for demonstration
        if (outstandingBalance > (totalAmount * 0.3)) {
            delinquentAccounts.push_back(billing);
        }
    }
    
    return delinquentAccounts;
}

void BillingService::addProcessedBilling(Billing* billing) {
    if (billing) {
        processedBillings.push_back(billing);
    }
}

void BillingService::removeProcessedBilling(const std::string& billingId) {
    processedBillings.erase(
        std::remove_if(processedBillings.begin(), processedBillings.end(),
            [&billingId](Billing* billing) {
                return billing->getId() == billingId;
            }),
        processedBillings.end()
    );
}

std::vector<Billing*> BillingService::getProcessedBillings() const {
    return processedBillings;
}

void BillingService::addBillingPatient(Patient* patient) {
    if (patient) {
        billingPatients.push_back(patient);
    }
}

void BillingService::removeBillingPatient(const std::string& patientId) {
    billingPatients.erase(
        std::remove_if(billingPatients.begin(), billingPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        billingPatients.end()
    );
}

std::vector<Patient*> BillingService::getBillingPatients() const {
    return billingPatients;
}

void BillingService::addSupportedInsurance(Insurance* insurance) {
    if (insurance) {
        supportedInsurances.push_back(insurance);
    }
}

void BillingService::removeSupportedInsurance(const std::string& insuranceId) {
    supportedInsurances.erase(
        std::remove_if(supportedInsurances.begin(), supportedInsurances.end(),
            [&insuranceId](Insurance* insurance) {
                return insurance->getId() == insuranceId;
            }),
        supportedInsurances.end()
    );
}

std::vector<Insurance*> BillingService::getSupportedInsurances() const {
    return supportedInsurances;
}
