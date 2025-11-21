#include "EquipmentMaintenanceService.h"
#include "Equipment.h"
#include "ConstructionProject.h"
#include <algorithm>

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

double EquipmentMaintenanceService::calculateServiceReliability() const {
    double baseReliability = 75.0;
    
    double equipmentReliability = maintainedEquipment * 0.4;
    double uptimeReliability = uptimeRate * 20.0;
    double equipmentManagementReliability = equipmentList.size() * 1.2;
    double projectSupportReliability = supportedProjects.size() * 1.5;
    
    double totalReliability = baseReliability + equipmentReliability + uptimeReliability + 
                             equipmentManagementReliability + projectSupportReliability;
    
    return totalReliability > 100.0 ? 100.0 : totalReliability;
}

bool EquipmentMaintenanceService::requiresPreventiveMaintenance() const {
    double reliability = calculateServiceReliability();
    bool hasLowReliability = reliability < 80.0;
    bool predictsFailure = predictEquipmentFailure();
    bool hasManyEquipment = maintainedEquipment > 50;
    bool hasFewSupportedProjects = supportedProjects.size() < 2;
    bool hasLimitedEquipmentList = equipmentList.size() < 10;
    
    return hasLowReliability || predictsFailure || hasManyEquipment || 
           hasFewSupportedProjects || hasLimitedEquipmentList;
}

void EquipmentMaintenanceService::addEquipment(Equipment* equipment) {
    if (equipment) {
        equipmentList.push_back(equipment);
    }
}

void EquipmentMaintenanceService::removeEquipment(const std::string& equipmentId) {
    equipmentList.erase(
        std::remove_if(equipmentList.begin(), equipmentList.end(),
            [&equipmentId](Equipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        equipmentList.end()
    );
}

std::vector<Equipment*> EquipmentMaintenanceService::getEquipmentList() const {
    return equipmentList;
}

void EquipmentMaintenanceService::addSupportedProject(ConstructionProject* project) {
    if (project) {
        supportedProjects.push_back(project);
    }
}

void EquipmentMaintenanceService::removeSupportedProject(const std::string& projectId) {
    supportedProjects.erase(
        std::remove_if(supportedProjects.begin(), supportedProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        supportedProjects.end()
    );
}

std::vector<ConstructionProject*> EquipmentMaintenanceService::getSupportedProjects() const {
    return supportedProjects;
}
