#include "ProjectPlan.h"
#include "ConstructionProject.h"
#include "RiskAssessment.h"
#include "Schedule.h"
#include <algorithm>

ProjectPlan::ProjectPlan(const std::string& id, const std::string& projectId, int phases, double risk)
    : planId(id), projectId(projectId), phases(phases), riskFactor(risk),
      project(nullptr), projectSchedule(nullptr) {}

double ProjectPlan::calculateCompletionProbability() const {
    double baseProbability = 0.8;
    
    double phasePenalty = (phases - 3) * 0.05;
    baseProbability -= phasePenalty;
    
    double riskPenalty = riskFactor * 0.3;
    baseProbability -= riskPenalty;
    
    if (projectId.find("URGENT") != std::string::npos) {
        baseProbability *= 0.9;
    }
    
    if (baseProbability < 0.3) {
        baseProbability = 0.3;
    }
    
    return baseProbability;
}

bool ProjectPlan::validateResourceAllocation() const {
    int optimalPhases = 4;
    int phaseDeviation = std::abs(phases - optimalPhases);
    
    bool hasReasonablePhases = phaseDeviation <= 2;
    bool hasManageableRisk = riskFactor <= 0.7;
    bool hasValidStructure = phases >= 2 && phases <= 8;
    
    double resourceEfficiency = 1.0 / phases;
    bool isEfficient = resourceEfficiency >= 0.15;
    
    return hasReasonablePhases && hasManageableRisk && hasValidStructure && isEfficient;
}

double ProjectPlan::calculatePlanEfficiency() const {
    double baseEfficiency = 70.0;
    
    double phaseEfficiency = (5.0 - std::abs(phases - 4)) * 5.0;
    double riskEfficiency = (1.0 - riskFactor) * 20.0;
    double projectEfficiency = project ? 5.0 : 0.0;
    
    double riskAssessmentBonus = 0.0;
    for (const auto& assessment : riskAssessments) {
        if (!assessment->requiresImmediateAction()) {
            riskAssessmentBonus += 2.0;
        }
    }
    
    double scheduleEfficiency = projectSchedule ? 3.0 : 0.0;
    
    double totalEfficiency = baseEfficiency + phaseEfficiency + riskEfficiency + 
                           projectEfficiency + riskAssessmentBonus + scheduleEfficiency;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool ProjectPlan::needsRevision() const {
    double efficiency = calculatePlanEfficiency();
    bool isInefficient = efficiency < 75.0;
    
    bool hasHighRiskAssessments = false;
    for (const auto& assessment : riskAssessments) {
        if (assessment->requiresImmediateAction()) {
            hasHighRiskAssessments = true;
            break;
        }
    }
    
    bool scheduleIssues = projectSchedule && !projectSchedule->isAheadOfSchedule();
    bool projectChanged = project && project->getDuration() > 18;
    
    return isInefficient || hasHighRiskAssessments || scheduleIssues || projectChanged;
}

void ProjectPlan::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* ProjectPlan::getProject() const {
    return project;
}

void ProjectPlan::addRiskAssessment(RiskAssessment* assessment) {
    if (assessment) {
        riskAssessments.push_back(assessment);
    }
}

void ProjectPlan::removeRiskAssessment(const std::string& assessmentId) {
    riskAssessments.erase(
        std::remove_if(riskAssessments.begin(), riskAssessments.end(),
            [&assessmentId](RiskAssessment* assessment) {
                return assessment->getId() == assessmentId;
            }),
        riskAssessments.end()
    );
}

std::vector<RiskAssessment*> ProjectPlan::getRiskAssessments() const {
    return riskAssessments;
}

void ProjectPlan::setProjectSchedule(Schedule* schedule) {
    this->projectSchedule = schedule;
}

Schedule* ProjectPlan::getProjectSchedule() const {
    return projectSchedule;
}
