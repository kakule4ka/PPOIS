#include "HVACSystem.h"

HVACSystem::HVACSystem(const std::string& id, double cooling, double heating, double efficiency)
    : systemId(id), coolingCapacity(cooling), heatingCapacity(heating), efficiency(efficiency) {}

double HVACSystem::calculateEnergyConsumption() const {
    return (coolingCapacity + heatingCapacity) * 0.5;
}

bool HVACSystem::validateRoomComfort(double roomSize) const {
    // ПРОСТАЯ ЛОГИКА: система должна иметь мощность больше чем площадь комнаты
    return coolingCapacity > roomSize;
}
