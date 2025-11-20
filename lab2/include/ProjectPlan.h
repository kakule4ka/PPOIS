#ifndef PROJECTPLAN_H
#define PROJECTPLAN_H

#include <string>

class ProjectPlan {
private:
    std::string planId;
    std::string projectId;
    int phases;
    double riskFactor;
    
public:
    ProjectPlan(const std::string& id, const std::string& projectId, int phases, double risk);
    
    double calculateCompletionProbability() const;
    bool validateResourceAllocation() const;
    
    std::string getId() const { return planId; }
};

#endif
