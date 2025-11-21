#include "services/ProjectManagementService.h"

ProjectManagementService::ProjectManagementService(const std::string& id, int projects, double rate)
    : serviceId(id), managedProjects(projects), successRate(rate) {}

double ProjectManagementService::calculateResourceEfficiency() const {
    double baseEfficiency = successRate * 100.0;
    
    double projectLoadFactor = 1.0;
    if (managedProjects > 10) {
        projectLoadFactor = 0.8;
    } else if (managedProjects > 5) {
        projectLoadFactor = 0.9;
    } else if (managedProjects < 3) {
        projectLoadFactor = 1.1;
    }
    
    double experienceFactor = 1.0;
    if (serviceId.find("SENIOR") != std::string::npos) {
        experienceFactor = 1.2;
    } else if (serviceId.find("JUNIOR") != std::string::npos) {
        experienceFactor = 0.8;
    }
    
    double toolEfficiency = 1.1;
    double communicationFactor = 1.05;
    
    double totalEfficiency = baseEfficiency * projectLoadFactor * experienceFactor * toolEfficiency * communicationFactor;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool ProjectManagementService::canTakeNewProject() const {
    int maxRecommendedProjects = 8;
    bool hasCapacity = managedProjects < maxRecommendedProjects;
    
    double currentSuccessRate = successRate;
    bool hasGoodPerformance = currentSuccessRate >= 0.75;
    
    double resourceUtilization = static_cast<double>(managedProjects) / maxRecommendedProjects;
    bool hasResourceBuffer = resourceUtilization <= 0.8;
    
    bool hasRecentExperience = managedProjects >= 1;
    bool isQualified = serviceId.find("CERTIFIED") != std::string::npos;
    
    return hasCapacity && hasGoodPerformance && hasResourceBuffer && hasRecentExperience && isQualified;
}
