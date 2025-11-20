#ifndef SAFETYINSPECTIONSERVICE_H
#define SAFETYINSPECTIONSERVICE_H

#include <string>

class SafetyInspectionService {
private:
    std::string serviceId;
    int safetyAudits;
    double complianceRate;
    
public:
    SafetyInspectionService(const std::string& id, int audits, double rate);
    
    double calculateRiskScore() const;
    bool identifySafetyHazards() const;
    
    std::string getId() const { return serviceId; }
};

#endif
