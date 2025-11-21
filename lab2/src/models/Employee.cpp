#include "models/Employee.h"
#include "core/ConstructionProject.h"
#include <algorithm>

Employee::Employee(const std::string& id, const std::string& name, const std::string& position, double salary)
    : id(id), name(name), position(position), salary(salary) {}

double Employee::calculateProductivity() const {
    double baseProductivity = 1.0;
    if (position == "Manager") baseProductivity = 1.5;
    if (position == "Architect") baseProductivity = 1.3;
    if (position == "Construction Worker") baseProductivity = 0.8;
    
    double salaryFactor = salary / 50000.0;
    if (salaryFactor > 2.0) salaryFactor = 2.0;
    
    double projectFactor = 1.0 + (assignedProjects.size() * 0.1);
    if (projectFactor > 1.5) projectFactor = 1.5;
    
    return baseProductivity * salaryFactor * projectFactor;
}

bool Employee::isEligibleForPromotion() const {
    return salary < 80000.0 && position != "Director";
}

double Employee::calculateWorkload() const {
    double baseWorkload = assignedProjects.size() * 0.3;
    double positionMultiplier = 1.0;
    
    if (position == "Manager") positionMultiplier = 1.8;
    else if (position == "Architect") positionMultiplier = 1.5;
    else if (position == "Construction Worker") positionMultiplier = 1.2;
    
    double salaryAdjustment = salary > 60000 ? 0.9 : 1.1;
    
    return baseWorkload * positionMultiplier * salaryAdjustment;
}

bool Employee::canTakeMoreProjects() const {
    double currentWorkload = calculateWorkload();
    double maxWorkload = position == "Manager" ? 2.5 : 1.8;
    return currentWorkload < maxWorkload;
}

void Employee::assignToProject(ConstructionProject* project) {
    if (project && canTakeMoreProjects()) {
        assignedProjects.push_back(project);
    }
}

void Employee::removeFromProject(const std::string& projectId) {
    assignedProjects.erase(
        std::remove_if(assignedProjects.begin(), assignedProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        assignedProjects.end()
    );
}

std::vector<ConstructionProject*> Employee::getAssignedProjects() const {
    return assignedProjects;
}
