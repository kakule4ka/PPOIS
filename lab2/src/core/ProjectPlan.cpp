#include "ProjectPlan.h"

ProjectPlan::ProjectPlan(const std::string& id, const std::string& projectId, int phases, double risk)
    : planId(id), projectId(projectId), phases(phases), riskFactor(risk) {}

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
