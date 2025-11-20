#include "Elevator.h"

Elevator::Elevator(const std::string& id, int capacity, int floors, double speed)
    : elevatorId(id), capacity(capacity), floorsServed(floors), speed(speed) {}

double Elevator::calculateRoundTripTime() const {
    return floorsServed * 10.0;
}

bool Elevator::validateCapacityRequirements(int buildingOccupancy) const {
    return capacity >= buildingOccupancy * 0.01;
}
