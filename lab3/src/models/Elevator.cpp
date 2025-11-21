#include "models/Elevator.h"
#include "models/Building.h"
#include "core/SafetyProtocol.h"
#include <algorithm>

Elevator::Elevator(const std::string& id, int capacity, int floors, double speed)
    : elevatorId(id), capacity(capacity), floorsServed(floors), speed(speed),
      building(nullptr) {}

double Elevator::calculateRoundTripTime() const {
    return floorsServed * 10.0;
}

bool Elevator::validateCapacityRequirements(int buildingOccupancy) const {
    return capacity >= buildingOccupancy * 0.01;
}

double Elevator::calculateElevatorEfficiency() const {
    double baseEfficiency = 75.0;
    
    double capacityEfficiency = (capacity >= 10) ? 8.0 : 0.0;
    double speedEfficiency = speed * 5.0;
    double floorEfficiency = (floorsServed >= 5 && floorsServed <= 30) ? 7.0 : -5.0;
    
    double buildingFactor = building ? 5.0 : 0.0;
    double safetyBonus = 0.0;
    
    for (const auto& protocol : safetyProtocols) {
        double riskReduction = protocol->calculateRiskReduction();
        safetyBonus += riskReduction * 0.1;
    }
    
    double totalEfficiency = baseEfficiency + capacityEfficiency + speedEfficiency + 
                            floorEfficiency + buildingFactor + safetyBonus;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool Elevator::meetsSafetyStandards() const {
    double efficiency = calculateElevatorEfficiency();
    bool hasGoodEfficiency = efficiency > 80.0;
    bool hasSafetyProtocols = !safetyProtocols.empty();
    bool hasBuilding = building != nullptr;
    bool hasValidCapacity = capacity >= 8 && capacity <= 20;
    bool hasValidFloors = floorsServed >= 2 && floorsServed <= 50;
    
    return hasGoodEfficiency && hasSafetyProtocols && hasBuilding && 
           hasValidCapacity && hasValidFloors;
}

void Elevator::setBuilding(Building* building) {
    this->building = building;
}

Building* Elevator::getBuilding() const {
    return building;
}

void Elevator::addSafetyProtocol(SafetyProtocol* protocol) {
    if (protocol) {
        safetyProtocols.push_back(protocol);
    }
}

void Elevator::removeSafetyProtocol(const std::string& protocolId) {
    safetyProtocols.erase(
        std::remove_if(safetyProtocols.begin(), safetyProtocols.end(),
            [&protocolId](SafetyProtocol* protocol) {
                return protocol->getId() == protocolId;
            }),
        safetyProtocols.end()
    );
}

std::vector<SafetyProtocol*> Elevator::getSafetyProtocols() const {
    return safetyProtocols;
}
