#include "models/ConstructionSite.h"
#include "core/ConstructionProject.h"
#include "core/SafetyProtocol.h"
#include <algorithm>

ConstructionSite::ConstructionSite(const std::string& id, const std::string& location, double size, int maxWorkers)
    : id(id), location(location), size(size), maxWorkers(maxWorkers),
      project(nullptr) {}

bool ConstructionSite::validateWorkerCapacity(int workers) const {
    return workers <= maxWorkers && workers >= maxWorkers * 0.6;
}

double ConstructionSite::calculatePreparationTime() const {
    return size * 0.05 + maxWorkers * 2.5;
}

double ConstructionSite::calculateSiteSafetyScore() const {
    double baseScore = 75.0;
    
    double sizeFactor = size > 10000 ? -10.0 : 0.0;
    double workerFactor = maxWorkers > 50 ? -5.0 : 5.0;
    double projectFactor = project ? 5.0 : 0.0;
    
    double protocolBonus = 0.0;
    for (const auto& protocol : activeSafetyProtocols) {
        double riskReduction = protocol->calculateRiskReduction();
        protocolBonus += riskReduction * 0.1;
    }
    
    double totalScore = baseScore + sizeFactor + workerFactor + projectFactor + protocolBonus;
    return totalScore > 100.0 ? 100.0 : totalScore;
}

bool ConstructionSite::isSiteReady() const {
    double safetyScore = calculateSiteSafetyScore();
    bool hasGoodSafety = safetyScore >= 80.0;
    bool hasProject = project != nullptr;
    bool hasSafetyProtocols = !activeSafetyProtocols.empty();
    bool hasReasonableSize = size > 1000 && size < 50000;
    
    return hasGoodSafety && hasProject && hasSafetyProtocols && hasReasonableSize;
}

void ConstructionSite::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* ConstructionSite::getProject() const {
    return project;
}

void ConstructionSite::addSafetyProtocol(SafetyProtocol* protocol) {
    if (protocol) {
        activeSafetyProtocols.push_back(protocol);
    }
}

void ConstructionSite::removeSafetyProtocol(const std::string& protocolId) {
    activeSafetyProtocols.erase(
        std::remove_if(activeSafetyProtocols.begin(), activeSafetyProtocols.end(),
            [&protocolId](SafetyProtocol* protocol) {
                return protocol->getId() == protocolId;
            }),
        activeSafetyProtocols.end()
    );
}

std::vector<SafetyProtocol*> ConstructionSite::getActiveSafetyProtocols() const {
    return activeSafetyProtocols;
}
