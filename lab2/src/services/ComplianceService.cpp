#include "ComplianceService.h"

ComplianceService::ComplianceService(const std::string& id, int regulations, double score)
    : serviceId(id), regulationsTracked(regulations), complianceScore(score) {}

double ComplianceService::calculateComplianceRisk() const {
    double baseRisk = (1.0 - complianceScore) * 100.0;
    
    double regulationComplexityFactor = 1.0;
    if (regulationsTracked > 50) {
        regulationComplexityFactor = 1.2;
    } else if (regulationsTracked > 25) {
        regulationComplexityFactor = 1.1;
    } else if (regulationsTracked < 10) {
        regulationComplexityFactor = 0.9;
    }
    
    double updateFrequencyFactor = 1.0;
    if (serviceId.find("DYNAMIC") != std::string::npos) {
        updateFrequencyFactor = 1.1;
    } else if (serviceId.find("STATIC") != std::string::npos) {
        updateFrequencyFactor = 0.95;
    }
    
    double documentationFactor = 1.03;
    double auditFactor = 1.02;
    
    double totalRisk = baseRisk * regulationComplexityFactor * updateFrequencyFactor * documentationFactor * auditFactor;
    
    return totalRisk > 100.0 ? 100.0 : totalRisk;
}

bool ComplianceService::monitorRegulatoryChanges() const {
    return complianceScore > 0.85;
}
