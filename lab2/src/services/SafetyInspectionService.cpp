#include "services/SafetyInspectionService.h"

SafetyInspectionService::SafetyInspectionService(const std::string& id, int audits, double rate)
    : serviceId(id), safetyAudits(audits), complianceRate(rate) {}

double SafetyInspectionService::calculateRiskScore() const {
    double baseRisk = (1.0 - complianceRate) * 100.0;
    
    double auditFrequencyFactor = 1.0;
    if (safetyAudits > 50) {
        auditFrequencyFactor = 0.9;
    } else if (safetyAudits > 25) {
        auditFrequencyFactor = 0.95;
    } else if (safetyAudits < 10) {
        auditFrequencyFactor = 1.1;
    }
    
    double severityFactor = 1.0;
    if (serviceId.find("HIGH_RISK") != std::string::npos) {
        severityFactor = 1.3;
    } else if (serviceId.find("LOW_RISK") != std::string::npos) {
        severityFactor = 0.8;
    }
    
    double trainingFactor = 1.05;
    double equipmentFactor = 1.02;
    
    double totalRisk = baseRisk * auditFrequencyFactor * severityFactor * trainingFactor * equipmentFactor;
    
    return totalRisk > 100.0 ? 100.0 : totalRisk;
}

bool SafetyInspectionService::identifySafetyHazards() const {
    return complianceRate > 0.8;
}
