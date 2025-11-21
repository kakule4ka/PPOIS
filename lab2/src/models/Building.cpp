#include "Building.h"
#include "ConstructionProject.h"
#include "Foundation.h"
#include "ElectricalSystem.h"

Building::Building(const std::string& id, const std::string& address, int floors, double area)
    : id(id), address(address), floors(floors), area(area),
      project(nullptr), foundation(nullptr), electricalSystem(nullptr) {}

double Building::calculateConstructionCost(double costPerSqm) const {
    return area * costPerSqm * floors;
}

bool Building::meetsSafetyStandards() const {
    bool hasFoundation = foundation != nullptr;
    bool hasElectrical = electricalSystem != nullptr;
    bool reasonableFloors = floors <= 100;  // Увеличили лимит
    bool reasonableArea = area <= 50000.0;  // Увеличили лимит
    
    return hasFoundation && hasElectrical && reasonableFloors && reasonableArea;
}

double Building::calculateBuildingEfficiency() const {
    double baseEfficiency = 80.0;
    double areaEfficiency = (area / 1000.0) * 2.0;
    double floorEfficiency = floors * 1.5;
    double projectEfficiency = project ? 5.0 : 0.0;
    
    return baseEfficiency + areaEfficiency + floorEfficiency + projectEfficiency;
}

bool Building::isConstructionFeasible() const {
    double cost = calculateConstructionCost(1500.0);
    bool affordable = cost < 100000000.0;  // Увеличили бюджет
    bool meetsStandards = meetsSafetyStandards();
    bool hasProject = project != nullptr;
    
    return affordable && meetsStandards && hasProject;
}

void Building::setProject(ConstructionProject* proj) {
    this->project = proj;
}

ConstructionProject* Building::getProject() const {
    return project;
}

void Building::setFoundation(Foundation* found) {
    this->foundation = found;
}

Foundation* Building::getFoundation() const {
    return foundation;
}

void Building::setElectricalSystem(ElectricalSystem* system) {
    this->electricalSystem = system;
}

ElectricalSystem* Building::getElectricalSystem() const {
    return electricalSystem;
}
