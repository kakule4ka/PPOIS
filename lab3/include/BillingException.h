#ifndef BILLINGEXCEPTION_H
#define BILLINGEXCEPTION_H

#include <stdexcept>
#include <string>

class BillingException : public std::runtime_error {
private:
    std::string billingId;
    std::string patientId;
    double amountInDispute;
    std::string disputeReason;
    
public:
    BillingException(const std::string& billingId, const std::string& patientId, double amountInDispute, const std::string& disputeReason);
    std::string getBillingId() const;
    std::string getPatientId() const;
    double getAmountInDispute() const;
    std::string getDisputeReason() const;
};

#endif
