#ifndef COMPLIANCESERVICE_H
#define COMPLIANCESERVICE_H

#include <string>
#include <vector>

class Hospital;

class ComplianceService {
private:
    std::string serviceId;
    std::vector<Hospital*> monitoredHospitals;

public:
    ComplianceService(const std::string& serviceId);
    
    double calculateComplianceScore(const Hospital* hospital) const;
    bool checkRegulatoryRequirements() const;
    bool validateSafetyStandards() const;
    
    void addMonitoredHospital(Hospital* hospital);
    void removeMonitoredHospital(const std::string& hospitalId);
    std::vector<Hospital*> getMonitoredHospitals() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
