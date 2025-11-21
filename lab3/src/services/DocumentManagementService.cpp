#include "services/DocumentManagementService.h"
#include "core/ConstructionProject.h"
#include "models/Blueprint.h"
#include <algorithm>

DocumentManagementService::DocumentManagementService(const std::string& id, int documents, double efficiency)
    : serviceId(id), documentsManaged(documents), retrievalEfficiency(efficiency) {}

double DocumentManagementService::calculateDocumentAccuracy() const {
    double baseAccuracy = retrievalEfficiency * 100.0;
    
    double volumeFactor = 1.0;
    if (documentsManaged > 1000) {
        volumeFactor = 0.95;
    } else if (documentsManaged > 500) {
        volumeFactor = 0.98;
    } else if (documentsManaged < 100) {
        volumeFactor = 1.05;
    }
    
    double complexityFactor = 1.0;
    if (serviceId.find("TECHNICAL") != std::string::npos) {
        complexityFactor = 0.95;
    } else if (serviceId.find("ADMIN") != std::string::npos) {
        complexityFactor = 1.02;
    }
    
    double organizationFactor = 1.03;
    double searchFactor = 1.04;
    
    double totalAccuracy = baseAccuracy * volumeFactor * complexityFactor * organizationFactor * searchFactor;
    
    return totalAccuracy > 100.0 ? 100.0 : totalAccuracy;
}

bool DocumentManagementService::automateDocumentWorkflow() const {
    return documentsManaged > 50 && retrievalEfficiency > 0.8;
}

double DocumentManagementService::calculateServicePerformance() const {
    double basePerformance = 70.0;
    
    double documentPerformance = documentsManaged * 0.3;
    double efficiencyPerformance = retrievalEfficiency * 25.0;
    double projectPerformance = projectDocuments.size() * 2.0;
    double blueprintPerformance = managedBlueprints.size() * 1.5;
    
    double totalPerformance = basePerformance + documentPerformance + efficiencyPerformance + 
                             projectPerformance + blueprintPerformance;
    
    return totalPerformance > 100.0 ? 100.0 : totalPerformance;
}

bool DocumentManagementService::needsSystemUpgrade() const {
    double performance = calculateServicePerformance();
    bool hasLowPerformance = performance < 75.0;
    bool hasLowEfficiency = retrievalEfficiency < 0.75;
    bool hasManyDocuments = documentsManaged > 500;
    bool hasFewProjects = projectDocuments.size() < 2;
    bool hasLimitedBlueprints = managedBlueprints.size() < 5;
    
    return hasLowPerformance || hasLowEfficiency || hasManyDocuments || 
           hasFewProjects || hasLimitedBlueprints;
}

void DocumentManagementService::addProjectDocument(ConstructionProject* project) {
    if (project) {
        projectDocuments.push_back(project);
    }
}

void DocumentManagementService::removeProjectDocument(const std::string& projectId) {
    projectDocuments.erase(
        std::remove_if(projectDocuments.begin(), projectDocuments.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        projectDocuments.end()
    );
}

std::vector<ConstructionProject*> DocumentManagementService::getProjectDocuments() const {
    return projectDocuments;
}

void DocumentManagementService::addManagedBlueprint(Blueprint* blueprint) {
    if (blueprint) {
        managedBlueprints.push_back(blueprint);
    }
}

void DocumentManagementService::removeManagedBlueprint(const std::string& blueprintId) {
    managedBlueprints.erase(
        std::remove_if(managedBlueprints.begin(), managedBlueprints.end(),
            [&blueprintId](Blueprint* blueprint) {
                return blueprint->getId() == blueprintId;
            }),
        managedBlueprints.end()
    );
}

std::vector<Blueprint*> DocumentManagementService::getManagedBlueprints() const {
    return managedBlueprints;
}
