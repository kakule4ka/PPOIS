#include "Floor.h"

Floor::Floor(const std::string& id, int level, const std::string& material, double area)
    : floorId(id), level(level), material(material), area(area) {}

double Floor::calculateLoadCapacity() const {
    return area * 100.0;
}

bool Floor::validateFloorPlanCompliance() const {
    return area > 0 && level >= 0;
}
