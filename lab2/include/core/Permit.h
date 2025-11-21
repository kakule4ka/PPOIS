#ifndef PERMIT_H
#define PERMIT_H

#include <string>
#include <vector>

class ConstructionProject;
class QualityStandard;

class Permit {
private:
    std::string permitId;
    std::string type;
    std::string issuingAuthority;
    bool isActive;
    ConstructionProject* associatedProject;
    std::vector<QualityStandard*> requiredStandards;
    
public:
    Permit(const std::string& id, const std::string& type, const std::string& authority);
    
    bool validateExpiryDate() const;
    double calculateProcessingTime() const;
    double calculateComplianceScore() const;
    bool needsRenewal() const;
    
    void setAssociatedProject(ConstructionProject* project);
    ConstructionProject* getAssociatedProject() const;
    
    void addRequiredStandard(QualityStandard* standard);
    void removeRequiredStandard(const std::string& standardId);
    std::vector<QualityStandard*> getRequiredStandards() const;
    
    std::string getId() const { return permitId; }
};

#endif
