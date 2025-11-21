#ifndef COMPLIANCESERVICE_H
#define COMPLIANCESERVICE_H

#include <string>
#include <vector>

class ConstructionProject;
class QualityStandard;

class ComplianceService {
private:
    std::string serviceId;
    int regulationsTracked;
    double complianceScore;
    std::vector<ConstructionProject*> monitoredProjects;
    std::vector<QualityStandard*> applicableStandards;
    
public:
    ComplianceService(const std::string& id, int regulations, double score);
    
    double calculateComplianceRisk() const;
    bool monitorRegulatoryChanges() const;
    double calculateServiceEfficiency() const;
    bool requiresAudit() const;
    
    void addMonitoredProject(ConstructionProject* project);
    void removeMonitoredProject(const std::string& projectId);
    std::vector<ConstructionProject*> getMonitoredProjects() const;
    
    void addApplicableStandard(QualityStandard* standard);
    void removeApplicableStandard(const std::string& standardId);
    std::vector<QualityStandard*> getApplicableStandards() const;
    
    std::string getId() const { return serviceId; }
};

#endif
