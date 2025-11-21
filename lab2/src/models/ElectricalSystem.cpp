#include "ElectricalSystem.h"
#include "Building.h"
#include "QualityStandard.h"
#include <algorithm>

ElectricalSystem::ElectricalSystem(const std::string& id, double voltage, double capacity, int circuits)
    : systemId(id), voltage(voltage), powerCapacity(capacity), circuits(circuits),
      building(nullptr) {}

double ElectricalSystem::calculatePowerConsumption(double usageHours) const {
    return powerCapacity * usageHours / 1000.0;
}

bool ElectricalSystem::validateCircuitLoad() const {
    return circuits > 0 && powerCapacity > 0;
}

double ElectricalSystem::calculateSystemEfficiency() const {
    double baseEfficiency = 85.0;
    
    double voltageEfficiency = (voltage >= 220.0 && voltage <= 240.0) ? 5.0 : -5.0;
    double capacityEfficiency = (powerCapacity >= 10000.0) ? 3.0 : 0.0;
    double circuitEfficiency = (circuits >= 10 && circuits <= 30) ? 2.0 : -2.0;
    
    double buildingFactor = building ? 3.0 : 0.0;
    double standardBonus = 0.0;
    
    for (const auto& standard : complianceStandards) {
        if (standard->validateCompliance(voltage)) {
            standardBonus += 1.5;
        }
    }
    
    double totalEfficiency = baseEfficiency + voltageEfficiency + capacityEfficiency + 
                            circuitEfficiency + buildingFactor + standardBonus;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool ElectricalSystem::isCodeCompliant() const {
    double efficiency = calculateSystemEfficiency();
    bool hasGoodEfficiency = efficiency > 80.0;
    bool hasValidLoad = validateCircuitLoad();
    bool hasBuilding = building != nullptr;
    bool hasComplianceStandards = !complianceStandards.empty();
    bool hasProperVoltage = voltage >= 110.0 && voltage <= 480.0;
    
    return hasGoodEfficiency && hasValidLoad && hasBuilding && 
           hasComplianceStandards && hasProperVoltage;
}

void ElectricalSystem::setBuilding(Building* building) {
    this->building = building;
}

Building* ElectricalSystem::getBuilding() const {
    return building;
}

void ElectricalSystem::addComplianceStandard(QualityStandard* standard) {
    if (standard) {
        complianceStandards.push_back(standard);
    }
}

void ElectricalSystem::removeComplianceStandard(const std::string& standardId) {
    complianceStandards.erase(
        std::remove_if(complianceStandards.begin(), complianceStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        complianceStandards.end()
    );
}

std::vector<QualityStandard*> ElectricalSystem::getComplianceStandards() const {
    return complianceStandards;
}
