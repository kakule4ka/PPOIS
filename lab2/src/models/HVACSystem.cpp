#include "HVACSystem.h"
#include "Building.h"
#include "QualityStandard.h"
#include <algorithm>

HVACSystem::HVACSystem(const std::string& id, double cooling, double heating, double efficiency)
    : systemId(id), coolingCapacity(cooling), heatingCapacity(heating), efficiency(efficiency),
      building(nullptr) {}

double HVACSystem::calculateEnergyConsumption() const {
    return (coolingCapacity + heatingCapacity) * 0.5;
}

bool HVACSystem::validateRoomComfort(double roomSize) const {
    return coolingCapacity > roomSize;
}

double HVACSystem::calculateSystemPerformance() const {
    double basePerformance = 75.0;
    
    double capacityPerformance = ((coolingCapacity + heatingCapacity) / 20000.0) * 10.0;
    double efficiencyPerformance = efficiency * 15.0;
    double balancePerformance = (coolingCapacity / heatingCapacity > 0.8 && 
                                coolingCapacity / heatingCapacity < 1.2) ? 5.0 : -5.0;
    
    double buildingFactor = building ? 3.0 : 0.0;
    double standardBonus = 0.0;
    
    for (const auto& standard : complianceStandards) {
        if (standard->validateCompliance(efficiency * 100.0)) {
            standardBonus += 2.0;
        }
    }
    
    double totalPerformance = basePerformance + capacityPerformance + 
                             efficiencyPerformance + balancePerformance + 
                             buildingFactor + standardBonus;
    
    return totalPerformance > 100.0 ? 100.0 : totalPerformance;
}

bool HVACSystem::isEnergyEfficient() const {
    double performance = calculateSystemPerformance();
    bool hasGoodPerformance = performance > 80.0;
    bool hasHighEfficiency = efficiency > 0.8;
    bool hasBuilding = building != nullptr;
    bool hasComplianceStandards = !complianceStandards.empty();
    bool hasAdequateCapacity = coolingCapacity > 5000 && heatingCapacity > 5000;
    
    return hasGoodPerformance && hasHighEfficiency && hasBuilding && 
           hasComplianceStandards && hasAdequateCapacity;
}

void HVACSystem::setBuilding(Building* building) {
    this->building = building;
}

Building* HVACSystem::getBuilding() const {
    return building;
}

void HVACSystem::addComplianceStandard(QualityStandard* standard) {
    if (standard) {
        complianceStandards.push_back(standard);
    }
}

void HVACSystem::removeComplianceStandard(const std::string& standardId) {
    complianceStandards.erase(
        std::remove_if(complianceStandards.begin(), complianceStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        complianceStandards.end()
    );
}

std::vector<QualityStandard*> HVACSystem::getComplianceStandards() const {
    return complianceStandards;
}
