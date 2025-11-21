#ifndef SURGERYRISKEXCEPTION_H
#define SURGERYRISKEXCEPTION_H

#include <stdexcept>
#include <string>

class SurgeryRiskException : public std::runtime_error {
private:
    std::string surgeryId;
    std::string patientId;
    double riskPercentage;
    std::string riskFactors;
    
public:
    SurgeryRiskException(const std::string& surgeryId, const std::string& patientId, double riskPercentage, const std::string& riskFactors);
    std::string getSurgeryId() const;
    std::string getPatientId() const;
    double getRiskPercentage() const;
    std::string getRiskFactors() const;
};

#endif
