#include "Building.h"

Building::Building(const std::string& id, const std::string& address, int floors, double area)
    : id(id), address(address), floors(floors), area(area) {}

double Building::calculateConstructionCost(double costPerSqm) const {
    return area * costPerSqm * (floors > 5 ? 1.2 : 1.0);
}

bool Building::meetsSafetyStandards() const {
    return floors <= 20 && area / floors <= 2000.0;
}
