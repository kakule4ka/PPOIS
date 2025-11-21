#include "RiskAssessment.h"
#include "ConstructionProject.h"
#include "SafetyProtocol.h"
#include <algorithm>

RiskAssessment::RiskAssessment(const std::string& id, const std::string& projectId, double level, const std::string& type)
    : assessmentId(id), projectId(projectId), riskLevel(level), riskType(type),
      project(nullptr) {}

double RiskAssessment::calculateMitigationCost() const {
    return riskLevel * 5000.0;
}

bool RiskAssessment::requiresImmediateAction() const {
    return riskLevel > 0.5;
}

double RiskAssessment::calculateRiskImpact() const {
    double baseImpact = riskLevel * 100.0;
    
    double typeMultiplier = 1.0;
    if (riskType == "Safety") typeMultiplier = 1.5;
    else if (riskType == "Financial") typeMultiplier = 1.3;
    else if (riskType == "Schedule") typeMultiplier = 1.2;
    
    double projectFactor = project ? 1.1 : 1.0;
    double protocolFactor = 1.0;
    
    for (const auto& protocol : mitigationProtocols) {
        double riskReduction = protocol->calculateRiskReduction();
        protocolFactor *= (1.0 - riskReduction / 100.0);
    }
    
    return baseImpact * typeMultiplier * projectFactor * protocolFactor;
}

bool RiskAssessment::canBeDeferred() const {
    double impact = calculateRiskImpact();
    bool isLowImpact = impact < 30.0;
    bool hasMitigation = !mitigationProtocols.empty();
    bool isNotSafety = riskType != "Safety";
    bool projectNotCritical = project && project->getDuration() > 30;
    
    return isLowImpact && hasMitigation && isNotSafety && projectNotCritical;
}

void RiskAssessment::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* RiskAssessment::getProject() const {
    return project;
}

void RiskAssessment::addMitigationProtocol(SafetyProtocol* protocol) {
    if (protocol) {
        mitigationProtocols.push_back(protocol);
    }
}

void RiskAssessment::removeMitigationProtocol(const std::string& protocolId) {
    mitigationProtocols.erase(
        std::remove_if(mitigationProtocols.begin(), mitigationProtocols.end(),
            [&protocolId](SafetyProtocol* protocol) {
                return protocol->getId() == protocolId;
            }),
        mitigationProtocols.end()
    );
}

std::vector<SafetyProtocol*> RiskAssessment::getMitigationProtocols() const {
    return mitigationProtocols;
}
