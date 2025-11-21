#include "services/WorkforceManagementService.h"

WorkforceManagementService::WorkforceManagementService(const std::string& id, int workers, double productivity)
    : serviceId(id), managedWorkers(workers), productivityRate(productivity) {}

double WorkforceManagementService::calculateLaborEfficiency() const {
    double baseEfficiency = productivityRate * 100.0;
    
    double scaleFactor = 1.0;
    if (managedWorkers > 100) {
        scaleFactor = 0.9;
    } else if (managedWorkers > 50) {
        scaleFactor = 0.95;
    } else if (managedWorkers < 20) {
        scaleFactor = 1.05;
    }
    
    double skillFactor = 1.0;
    if (serviceId.find("SKILLED") != std::string::npos) {
        skillFactor = 1.1;
    } else if (serviceId.find("GENERAL") != std::string::npos) {
        skillFactor = 0.95;
    }
    
    double trainingFactor = 1.03;
    double toolsFactor = 1.02;
    
    double totalEfficiency = baseEfficiency * scaleFactor * skillFactor * trainingFactor * toolsFactor;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool WorkforceManagementService::optimizeWorkforceAllocation() const {
    return productivityRate > 0.8;
}
