#include "EquipmentMaintenanceService.h"

EquipmentMaintenanceService::EquipmentMaintenanceService(const std::string& id, int equipment, double uptime)
    : serviceId(id), maintainedEquipment(equipment), uptimeRate(uptime) {}

double EquipmentMaintenanceService::calculateMaintenanceCost() const {
    double baseCostPerUnit = 1000.0;
    double totalBaseCost = maintainedEquipment * baseCostPerUnit;
    
    double uptimeFactor = 1.0;
    if (uptimeRate > 0.95) {
        uptimeFactor = 0.8;
    } else if (uptimeRate > 0.9) {
        uptimeFactor = 0.9;
    } else if (uptimeRate < 0.8) {
        uptimeFactor = 1.2;
    }
    
    double equipmentAgeFactor = 1.0;
    if (maintainedEquipment > 100) {
        equipmentAgeFactor = 1.1;
    } else if (maintainedEquipment > 50) {
        equipmentAgeFactor = 1.05;
    }
    
    double complexityFactor = 1.0;
    if (serviceId.find("HEAVY") != std::string::npos) {
        complexityFactor = 1.3;
    } else if (serviceId.find("LIGHT") != std::string::npos) {
        complexityFactor = 0.9;
    }
    
    double preventiveFactor = 0.85;
    
    double totalCost = totalBaseCost * uptimeFactor * equipmentAgeFactor * complexityFactor * preventiveFactor;
    
    return totalCost;
}

bool EquipmentMaintenanceService::predictEquipmentFailure() const {
    return uptimeRate < 0.9;
}
