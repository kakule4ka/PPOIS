#ifndef INSURANCE_H
#define INSURANCE_H

#include <string>
#include <vector>

class Patient;
class Billing;

class Insurance {
private:
    std::string id;
    std::string providerName;
    std::string planType;
    double coveragePercentage;
    double annualLimit;
    double deductible;
    std::vector<Patient*> coveredPatients;
    std::vector<Billing*> processedBillings;

public:
    Insurance(const std::string& id, const std::string& providerName, const std::string& planType);
    
    double calculateCoverageAmount(double medicalCost) const;
    bool isTreatmentCovered(const std::string& treatmentType) const;
    double calculatePatientResponsibility(double totalCost) const;
    
    void addCoveredPatient(Patient* patient);
    void removeCoveredPatient(const std::string& patientId);
    std::vector<Patient*> getCoveredPatients() const;
    
    void addProcessedBilling(Billing* billing);
    void removeProcessedBilling(const std::string& billingId);
    std::vector<Billing*> getProcessedBillings() const;
    
    std::string getId() const { return id; }
    std::string getProviderName() const { return providerName; }
    std::string getPlanType() const { return planType; }
    void setCoveragePercentage(double percentage) { coveragePercentage = percentage; }
    void setAnnualLimit(double limit) { annualLimit = limit; }
    void setDeductible(double deductible) { this->deductible = deductible; }
    double getCoveragePercentage() const { return coveragePercentage; }
    double getAnnualLimit() const { return annualLimit; }
    double getDeductible() const { return deductible; }
};

#endif
