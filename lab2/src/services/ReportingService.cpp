#include "ReportingService.h"
#include "ConstructionProject.h"

ReportingService::ReportingService(const std::string& id, int reports, double accuracy)
    : serviceId(id), reportsGenerated(reports), accuracyRate(accuracy) {}

double ReportingService::calculateReportValue() const {
    double baseValue = accuracyRate * 100.0;
    
    // Используем ассоциацию
    double projectBonus = 0.0;
    for (const auto& project : reportedProjects) {
        projectBonus += project->calculateTeamProductivity() * 0.1;
    }
    
    return baseValue + projectBonus;
}

bool ReportingService::automateReportGeneration() const {
    bool hasProjects = !reportedProjects.empty();
    bool hasEnoughReports = reportsGenerated > 20;
    double reportValue = calculateReportValue();
    
    return hasProjects && hasEnoughReports && reportValue > 80.0;
}

void ReportingService::addProject(ConstructionProject* project) {
    if (project) {
        reportedProjects.push_back(project);
    }
}

std::vector<ConstructionProject*> ReportingService::getReportedProjects() const {
    return reportedProjects;
}
