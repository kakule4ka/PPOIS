#include "RiskAssessment.h"

RiskAssessment::RiskAssessment(const std::string& id, const std::string& projectId, double level, const std::string& type)
    : assessmentId(id), projectId(projectId), riskLevel(level), riskType(type) {}

double RiskAssessment::calculateMitigationCost() const {
    return riskLevel * 5000.0;
}

bool RiskAssessment::requiresImmediateAction() const {
    return riskLevel > 0.5;
}
