#include "ElectricalSystem.h"

ElectricalSystem::ElectricalSystem(const std::string& id, double voltage, double capacity, int circuits)
    : systemId(id), voltage(voltage), powerCapacity(capacity), circuits(circuits) {}

double ElectricalSystem::calculatePowerConsumption(double usageHours) const {
    return powerCapacity * usageHours / 1000.0;
}

bool ElectricalSystem::validateCircuitLoad() const {
    return circuits > 0 && powerCapacity > 0;
}
