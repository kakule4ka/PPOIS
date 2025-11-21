#include "SurgeryRiskException.h"

SurgeryRiskException::SurgeryRiskException(const std::string& surgeryId, 
                                          const std::string& patientId, 
                                          double riskPercentage, 
                                          const std::string& riskFactors)
    : std::runtime_error("Surgery risk too high: Surgery " + surgeryId + 
                        " - Patient: " + patientId + 
                        " - Risk: " + std::to_string(riskPercentage) + "%" +
                        " - Factors: " + riskFactors), 
      surgeryId(surgeryId), patientId(patientId), riskPercentage(riskPercentage), riskFactors(riskFactors) {}

std::string SurgeryRiskException::getSurgeryId() const {
    return surgeryId;
}

std::string SurgeryRiskException::getPatientId() const {
    return patientId;
}

double SurgeryRiskException::getRiskPercentage() const {
    return riskPercentage;
}

std::string SurgeryRiskException::getRiskFactors() const {
    return riskFactors;
}
