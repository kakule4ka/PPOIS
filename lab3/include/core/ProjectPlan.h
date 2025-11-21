#ifndef PROJECTPLAN_H
#define PROJECTPLAN_H

#include <string>
#include <vector>

class ConstructionProject;
class RiskAssessment;
class Schedule;

class ProjectPlan {
private:
    std::string planId;
    std::string projectId;
    int phases;
    double riskFactor;
    ConstructionProject* project;
    std::vector<RiskAssessment*> riskAssessments;
    Schedule* projectSchedule;
    
public:
    ProjectPlan(const std::string& id, const std::string& projectId, int phases, double risk);
    
    double calculateCompletionProbability() const;
    bool validateResourceAllocation() const;
    double calculatePlanEfficiency() const;
    bool needsRevision() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addRiskAssessment(RiskAssessment* assessment);
    void removeRiskAssessment(const std::string& assessmentId);
    std::vector<RiskAssessment*> getRiskAssessments() const;
    
    void setProjectSchedule(Schedule* schedule);
    Schedule* getProjectSchedule() const;
    
    std::string getId() const { return planId; }
};

#endif
