#include "models/Equipment.h"
#include "core/ConstructionProject.h"
#include "models/Employee.h"

Equipment::Equipment(const std::string& id, const std::string& type, double maintenanceCost)
    : equipmentId(id), type(type), maintenanceCost(maintenanceCost), hoursUsed(0),
      currentProject(nullptr), assignedOperator(nullptr) {}

double Equipment::calculateDepreciation() const {
    return maintenanceCost * 0.1;
}

bool Equipment::needsMaintenance() const {
    return hoursUsed > 1000;
}

double Equipment::calculateUtilizationRate() const {
    return (static_cast<double>(hoursUsed) / 2000.0) * 100.0;
}

bool Equipment::isAvailableForProject() const {
    return currentProject == nullptr && hoursUsed < 1800;
}

void Equipment::setCurrentProject(ConstructionProject* project) {
    this->currentProject = project;
}

ConstructionProject* Equipment::getCurrentProject() const {
    return currentProject;
}

void Equipment::assignOperator(Employee* emp) {
    this->assignedOperator = emp;
}

Employee* Equipment::getAssignedOperator() const {
    return assignedOperator;
}

void Equipment::setHoursUsed(int hours) {
    this->hoursUsed = hours;
}
