#include "ProjectManager.h"

ProjectManager::ProjectManager(const std::string& id, const std::string& name, double salary, int projects, double budget)
    : Employee(id, name, "Project Manager", salary), managedProjects(projects), budgetControl(budget) {}

double ProjectManager::calculateManagementEfficiency() const {
    return managedProjects > 0 ? budgetControl / managedProjects / 1000.0 : 0.0;
}

bool ProjectManager::canHandleMoreProjects() const {
    return managedProjects < 5 && budgetControl < 5000000.0;
}
