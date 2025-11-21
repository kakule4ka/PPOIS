#include "ComplianceService.h"
#include "Hospital.h"
#include <algorithm>

ComplianceService::ComplianceService(const std::string& serviceId)
    : serviceId(serviceId) {}

double ComplianceService::calculateComplianceScore(const Hospital* hospital) const {
    if (!hospital) return 0.0;
    
    double baseScore = 75.0;
    
    double resourceScore = hospital->calculateResourceUtilization() > 80.0 ? 15.0 : 10.0;
    double capacityScore = hospital->calculateBedOccupancyRate() < 90.0 ? 12.0 : 5.0;
    double satisfactionScore = hospital->calculatePatientSatisfactionScore() * 0.1;
    
    double totalScore = baseScore + resourceScore + capacityScore + satisfactionScore;
    return std::min(totalScore, 100.0);
}

bool ComplianceService::checkRegulatoryRequirements() const {
    if (monitoredHospitals.empty()) return false;
    
    int compliantHospitals = 0;
    for (const auto& hospital : monitoredHospitals) {
        double complianceScore = calculateComplianceScore(hospital);
        if (complianceScore >= 80.0) {
            compliantHospitals++;
        }
    }
    
    double complianceRate = static_cast<double>(compliantHospitals) / monitoredHospitals.size();
    return complianceRate >= 0.8;
}

bool ComplianceService::validateSafetyStandards() const {
    if (monitoredHospitals.empty()) return false;
    
    for (const auto& hospital : monitoredHospitals) {
        if (!hospital->canHandleEmergency(3)) {
            return false;
        }
    }
    
    return true;
}

void ComplianceService::addMonitoredHospital(Hospital* hospital) {
    if (hospital) {
        monitoredHospitals.push_back(hospital);
    }
}

void ComplianceService::removeMonitoredHospital(const std::string& hospitalId) {
    monitoredHospitals.erase(
        std::remove_if(monitoredHospitals.begin(), monitoredHospitals.end(),
            [&hospitalId](Hospital* hospital) {
                return hospital->getName() == hospitalId;
            }),
        monitoredHospitals.end()
    );
}

std::vector<Hospital*> ComplianceService::getMonitoredHospitals() const {
    return monitoredHospitals;
}
