#include "ConstructionProject.h"

ConstructionProject::ConstructionProject(const std::string& id, const std::string& name, double budget, int duration)
    : id(id), name(name), budget(budget), duration(duration) {}

double ConstructionProject::calculateMonthlyCost() const {
    return budget / duration;
}

bool ConstructionProject::isOnSchedule(int elapsedMonths, double spent) const {
    double expectedSpent = (budget / duration) * elapsedMonths;
    return spent <= expectedSpent * 1.1;
}
