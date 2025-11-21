#include "BillingException.h"

BillingException::BillingException(const std::string& billingId, 
                                  const std::string& patientId, 
                                  double amountInDispute, 
                                  const std::string& disputeReason)
    : std::runtime_error("Billing dispute: Invoice " + billingId + 
                        " - Patient: " + patientId + 
                        " - Amount: $" + std::to_string(amountInDispute) +
                        " - Reason: " + disputeReason), 
      billingId(billingId), patientId(patientId), amountInDispute(amountInDispute), disputeReason(disputeReason) {}

std::string BillingException::getBillingId() const {
    return billingId;
}

std::string BillingException::getPatientId() const {
    return patientId;
}

double BillingException::getAmountInDispute() const {
    return amountInDispute;
}

std::string BillingException::getDisputeReason() const {
    return disputeReason;
}
