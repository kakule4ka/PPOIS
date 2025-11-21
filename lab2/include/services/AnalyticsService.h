#ifndef ANALYTICSSERVICE_H
#define ANALYTICSSERVICE_H

#include <string>
#include <vector>

class ConstructionProject;
class RiskAssessment;

class AnalyticsService {
private:
    std::string serviceId;
    int dataSources;
    double predictionAccuracy;
    std::vector<ConstructionProject*> monitoredProjects;
    std::vector<RiskAssessment*> riskData;
    
public:
    AnalyticsService(const std::string& id, int sources, double accuracy);
    
    double calculateBusinessInsight() const;
    bool predictProjectSuccess() const;
    double calculateDataReliability() const;
    bool needsDataRefresh() const;
    
    void addMonitoredProject(ConstructionProject* project);
    void removeMonitoredProject(const std::string& projectId);
    std::vector<ConstructionProject*> getMonitoredProjects() const;
    
    void addRiskData(RiskAssessment* assessment);
    void removeRiskData(const std::string& assessmentId);
    std::vector<RiskAssessment*> getRiskData() const;
    
    std::string getId() const { return serviceId; }
};

#endif
