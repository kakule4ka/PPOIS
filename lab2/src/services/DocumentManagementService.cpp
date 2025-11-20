#include "DocumentManagementService.h"

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
