#ifndef INSURANCENOTCOVEREDEXCEPTION_H
#define INSURANCENOTCOVEREDEXCEPTION_H

#include <stdexcept>
#include <string>

class InsuranceNotCoveredException : public std::runtime_error {
private:
    std::string insuranceProvider;
    std::string treatmentType;
    double cost;
    
public:
    InsuranceNotCoveredException(const std::string& provider, const std::string& treatment, double cost);
    std::string getInsuranceProvider() const;
    std::string getTreatmentType() const;
    double getCost() const;
};

#endif
