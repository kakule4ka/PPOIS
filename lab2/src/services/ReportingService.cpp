#include "ReportingService.h"

ReportingService::ReportingService(const std::string& id, int reports, double accuracy)
    : serviceId(id), reportsGenerated(reports), accuracyRate(accuracy) {}

double ReportingService::calculateReportValue() const {
    double baseValue = accuracyRate * 100.0;
    
    double volumeFactor = 1.0;
    if (reportsGenerated > 100) {
        volumeFactor = 0.95;
    } else if (reportsGenerated > 50) {
        volumeFactor = 0.98;
    } else if (reportsGenerated < 20) {
        volumeFactor = 1.05;
    }
    
    double timelinessFactor = 1.0;
    if (serviceId.find("REALTIME") != std::string::npos) {
        timelinessFactor = 1.1;
    } else if (serviceId.find("BATCH") != std::string::npos) {
        timelinessFactor = 0.95;
    }
    
    double complexityFactor = 1.0;
    if (serviceId.find("ANALYTICAL") != std::string::npos) {
        complexityFactor = 1.05;
    } else if (serviceId.find("BASIC") != std::string::npos) {
        complexityFactor = 0.98;
    }
    
    double automationFactor = 1.03;
    
    double totalValue = baseValue * volumeFactor * timelinessFactor * complexityFactor * automationFactor;
    
    return totalValue > 100.0 ? 100.0 : totalValue;
}

bool ReportingService::automateReportGeneration() const {
    return reportsGenerated > 30 && accuracyRate > 0.85;
}
