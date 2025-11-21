#include "AnalyticsService.h"
#include "ConstructionProject.h"
#include "RiskAssessment.h"
#include <algorithm>

AnalyticsService::AnalyticsService(const std::string& id, int sources, double accuracy)
    : serviceId(id), dataSources(sources), predictionAccuracy(accuracy) {}

double AnalyticsService::calculateBusinessInsight() const {
    return predictionAccuracy * 100.0;
}

bool AnalyticsService::predictProjectSuccess() const {
    return predictionAccuracy > 0.7;
}

double AnalyticsService::calculateDataReliability() const {
    double baseReliability = 70.0;
    
    double sourceReliability = dataSources * 3.0;
    double accuracyReliability = predictionAccuracy * 20.0;
    double projectReliability = monitoredProjects.size() * 2.0;
    double riskReliability = riskData.size() * 1.5;
    
    double totalReliability = baseReliability + sourceReliability + accuracyReliability + 
                             projectReliability + riskReliability;
    
    return totalReliability > 100.0 ? 100.0 : totalReliability;
}

bool AnalyticsService::needsDataRefresh() const {
    double reliability = calculateDataReliability();
    bool hasLowReliability = reliability < 80.0;
    bool hasFewProjects = monitoredProjects.size() < 3;
    bool hasLimitedRiskData = riskData.size() < 5;
    bool hasLowAccuracy = predictionAccuracy < 0.75;
    bool hasFewSources = dataSources < 5;
    
    return hasLowReliability || hasFewProjects || hasLimitedRiskData || 
           hasLowAccuracy || hasFewSources;
}

void AnalyticsService::addMonitoredProject(ConstructionProject* project) {
    if (project) {
        monitoredProjects.push_back(project);
    }
}

void AnalyticsService::removeMonitoredProject(const std::string& projectId) {
    monitoredProjects.erase(
        std::remove_if(monitoredProjects.begin(), monitoredProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        monitoredProjects.end()
    );
}

std::vector<ConstructionProject*> AnalyticsService::getMonitoredProjects() const {
    return monitoredProjects;
}

void AnalyticsService::addRiskData(RiskAssessment* assessment) {
    if (assessment) {
        riskData.push_back(assessment);
    }
}

void AnalyticsService::removeRiskData(const std::string& assessmentId) {
    riskData.erase(
        std::remove_if(riskData.begin(), riskData.end(),
            [&assessmentId](RiskAssessment* assessment) {
                return assessment->getId() == assessmentId;
            }),
        riskData.end()
    );
}

std::vector<RiskAssessment*> AnalyticsService::getRiskData() const {
    return riskData;
}
