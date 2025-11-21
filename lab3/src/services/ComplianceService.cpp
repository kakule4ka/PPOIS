#include "services/ComplianceService.h"
#include "core/ConstructionProject.h"
#include "core/QualityStandard.h"
#include <algorithm>

ComplianceService::ComplianceService(const std::string& id, int regulations, double score)
    : serviceId(id), regulationsTracked(regulations), complianceScore(score) {}

double ComplianceService::calculateComplianceRisk() const {
    double baseRisk = (1.0 - complianceScore) * 100.0;
    
    double regulationComplexityFactor = 1.0;
    if (regulationsTracked > 50) {
        regulationComplexityFactor = 1.2;
    } else if (regulationsTracked > 25) {
        regulationComplexityFactor = 1.1;
    } else if (regulationsTracked < 10) {
        regulationComplexityFactor = 0.9;
    }
    
    double updateFrequencyFactor = 1.0;
    if (serviceId.find("DYNAMIC") != std::string::npos) {
        updateFrequencyFactor = 1.1;
    } else if (serviceId.find("STATIC") != std::string::npos) {
        updateFrequencyFactor = 0.95;
    }
    
    double documentationFactor = 1.03;
    double auditFactor = 1.02;
    
    double totalRisk = baseRisk * regulationComplexityFactor * updateFrequencyFactor * documentationFactor * auditFactor;
    
    return totalRisk > 100.0 ? 100.0 : totalRisk;
}

bool ComplianceService::monitorRegulatoryChanges() const {
    return complianceScore > 0.85;
}

double ComplianceService::calculateServiceEfficiency() const {
    double baseEfficiency = 75.0;
    
    double regulationEfficiency = regulationsTracked * 0.8;
    double complianceEfficiency = complianceScore * 20.0;
    double projectEfficiency = monitoredProjects.size() * 1.5;
    double standardEfficiency = applicableStandards.size() * 1.2;
    
    double totalEfficiency = baseEfficiency + regulationEfficiency + complianceEfficiency + 
                            projectEfficiency + standardEfficiency;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool ComplianceService::requiresAudit() const {
    double efficiency = calculateServiceEfficiency();
    bool hasLowEfficiency = efficiency < 70.0;
    bool hasHighRisk = calculateComplianceRisk() > 30.0;
    bool hasFewProjects = monitoredProjects.size() < 3;
    bool hasLimitedStandards = applicableStandards.size() < 5;
    bool hasLowCompliance = complianceScore < 0.8;
    
    return hasLowEfficiency || hasHighRisk || hasFewProjects || 
           hasLimitedStandards || hasLowCompliance;
}

void ComplianceService::addMonitoredProject(ConstructionProject* project) {
    if (project) {
        monitoredProjects.push_back(project);
    }
}

void ComplianceService::removeMonitoredProject(const std::string& projectId) {
    monitoredProjects.erase(
        std::remove_if(monitoredProjects.begin(), monitoredProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        monitoredProjects.end()
    );
}

std::vector<ConstructionProject*> ComplianceService::getMonitoredProjects() const {
    return monitoredProjects;
}

void ComplianceService::addApplicableStandard(QualityStandard* standard) {
    if (standard) {
        applicableStandards.push_back(standard);
    }
}

void ComplianceService::removeApplicableStandard(const std::string& standardId) {
    applicableStandards.erase(
        std::remove_if(applicableStandards.begin(), applicableStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        applicableStandards.end()
    );
}

std::vector<QualityStandard*> ComplianceService::getApplicableStandards() const {
    return applicableStandards;
}
