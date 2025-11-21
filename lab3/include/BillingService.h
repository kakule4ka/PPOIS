#ifndef BILLINGSERVICE_H
#define BILLINGSERVICE_H

#include <string>
#include <vector>

class Billing;
class Patient;
class Insurance;

class BillingService {
private:
    std::string serviceId;
    std::vector<Billing*> processedBillings;
    std::vector<Patient*> billingPatients;
    std::vector<Insurance*> supportedInsurances;

public:
    BillingService(const std::string& serviceId);
    
    double calculateTotalRevenue() const;
    double calculateOutstandingDebt() const;
    double processInsuranceClaim(Billing* billing, Insurance* insurance) const;
    bool generateInvoice(Billing* billing) const;
    double calculateCollectionEfficiency() const;
    std::vector<Billing*> identifyDelinquentAccounts() const;
    
    void addProcessedBilling(Billing* billing);
    void removeProcessedBilling(const std::string& billingId);
    std::vector<Billing*> getProcessedBillings() const;
    
    void addBillingPatient(Patient* patient);
    void removeBillingPatient(const std::string& patientId);
    std::vector<Patient*> getBillingPatients() const;
    
    void addSupportedInsurance(Insurance* insurance);
    void removeSupportedInsurance(const std::string& insuranceId);
    std::vector<Insurance*> getSupportedInsurances() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
