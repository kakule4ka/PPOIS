#ifndef RISKASSESSMENT_H
#define RISKASSESSMENT_H

#include <string>

class RiskAssessment {
private:
    std::string assessmentId;
    std::string projectId;
    double riskLevel;
    std::string riskType;
    
public:
    RiskAssessment(const std::string& id, const std::string& projectId, double level, const std::string& type);
    
    double calculateMitigationCost() const;
    bool requiresImmediateAction() const;
    
    std::string getId() const { return assessmentId; }
};

#endif
