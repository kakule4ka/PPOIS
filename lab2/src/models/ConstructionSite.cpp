#include "ConstructionSite.h"

ConstructionSite::ConstructionSite(const std::string& id, const std::string& location, double size, int maxWorkers)
    : id(id), location(location), size(size), maxWorkers(maxWorkers) {}

bool ConstructionSite::validateWorkerCapacity(int workers) const {
    return workers <= maxWorkers && workers >= maxWorkers * 0.6;
}

double ConstructionSite::calculatePreparationTime() const {
    return size * 0.05 + maxWorkers * 2.5;
}
