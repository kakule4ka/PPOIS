#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <vector>

class Patient;
class TreatmentPlan;
class Insurance;

class Billing {
private:
    std::string id;
    std::string patientId;
    double totalAmount;
    double paidAmount;
    std::string status;
    std::string billingDate;
    Patient* patient;
    std::vector<TreatmentPlan*> treatmentPlans;
    Insurance* insurance;

public:
    Billing(const std::string& id, const std::string& patientId, double totalAmount);
    
    double calculateOutstandingBalance() const;
    bool isEligibleForDiscount() const;
    double calculateInsuranceCoverage() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void addTreatmentPlan(TreatmentPlan* plan);
    void removeTreatmentPlan(const std::string& planId);
    std::vector<TreatmentPlan*> getTreatmentPlans() const;
    
    void setInsurance(Insurance* insurance);
    Insurance* getInsurance() const;
    
    std::string getId() const { return id; }
    std::string getPatientId() const { return patientId; }
    double getTotalAmount() const { return totalAmount; }
    void setPaidAmount(double amount) { paidAmount = amount; }
    void setStatus(const std::string& status) { this->status = status; }
    void setBillingDate(const std::string& date) { billingDate = date; }
    double getPaidAmount() const { return paidAmount; }
    std::string getStatus() const { return status; }
    std::string getBillingDate() const { return billingDate; }
};

#endif
