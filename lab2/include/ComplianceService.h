#ifndef COMPLIANCESERVICE_H
#define COMPLIANCESERVICE_H

#include <string>

class ComplianceService {
private:
    std::string serviceId;
    int regulationsTracked;
    double complianceScore;
    
public:
    ComplianceService(const std::string& id, int regulations, double score);
    
    double calculateComplianceRisk() const;
    bool monitorRegulatoryChanges() const;
    
    std::string getId() const { return serviceId; }
};

#endif
