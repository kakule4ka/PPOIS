#ifndef RISKASSESSMENT_H
#define RISKASSESSMENT_H

#include <string>
#include <vector>

class ConstructionProject;
class SafetyProtocol;

class RiskAssessment {
private:
    std::string assessmentId;
    std::string projectId;
    double riskLevel;
    std::string riskType;
    ConstructionProject* project;
    std::vector<SafetyProtocol*> mitigationProtocols;
    
public:
    RiskAssessment(const std::string& id, const std::string& projectId, double level, const std::string& type);
    
    double calculateMitigationCost() const;
    bool requiresImmediateAction() const;
    double calculateRiskImpact() const;
    bool canBeDeferred() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addMitigationProtocol(SafetyProtocol* protocol);
    void removeMitigationProtocol(const std::string& protocolId);
    std::vector<SafetyProtocol*> getMitigationProtocols() const;
    
    std::string getId() const { return assessmentId; }
};

#endif
