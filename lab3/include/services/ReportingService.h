#ifndef REPORTINGSERVICE_H
#define REPORTINGSERVICE_H

#include <string>
#include <vector>

class ConstructionProject;

class ReportingService {
private:
    std::string serviceId;
    int reportsGenerated;
    double accuracyRate;
    std::vector<ConstructionProject*> reportedProjects; // +1 ассоциация
    
public:
    ReportingService(const std::string& id, int reports, double accuracy);
    
    double calculateReportValue() const;
    bool automateReportGeneration() const;
    
    // Ассоциация
    void addProject(ConstructionProject* project);
    std::vector<ConstructionProject*> getReportedProjects() const;
    
    std::string getId() const { return serviceId; }
};

#endif
