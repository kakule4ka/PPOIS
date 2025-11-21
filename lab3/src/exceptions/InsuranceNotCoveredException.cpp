#include "InsuranceNotCoveredException.h"

InsuranceNotCoveredException::InsuranceNotCoveredException(const std::string& provider, 
                                                          const std::string& treatment, double cost)
    : std::runtime_error("Insurance not covered: " + provider + 
                        " - Treatment: " + treatment + 
                        ", Cost: " + std::to_string(cost)), 
      insuranceProvider(provider), treatmentType(treatment), cost(cost) {}

std::string InsuranceNotCoveredException::getInsuranceProvider() const {
    return insuranceProvider;
}

std::string InsuranceNotCoveredException::getTreatmentType() const {
    return treatmentType;
}

double InsuranceNotCoveredException::getCost() const {
    return cost;
}
