#include "ProjectManager.h"
#include "ConstructionProject.h"
#include "Budget.h"
#include "Schedule.h"
#include <algorithm>

ProjectManager::ProjectManager(const std::string& id, const std::string& name, double salary, int projects, double budget)
    : Employee(id, name, "Project Manager", salary), managedProjects(projects), budgetControl(budget),
      managedBudget(nullptr), projectSchedule(nullptr) {}

double ProjectManager::calculateManagementEfficiency() const {
    if (currentProjects.empty()) return 0.0;
    
    double baseEfficiency = 70.0;
    double projectEfficiency = currentProjects.size() * 5.0;
    double budgetEfficiency = managedBudget ? managedBudget->calculateRemaining() * 0.0001 : 0.0;
    double scheduleEfficiency = projectSchedule ? 10.0 : 0.0;
    
    return baseEfficiency + projectEfficiency + budgetEfficiency + scheduleEfficiency;
}

bool ProjectManager::canHandleMoreProjects() const {
    return currentProjects.size() < managedProjects;
}

double ProjectManager::calculateRiskMitigationScore() const {
    double baseScore = 60.0;
    double projectScore = currentProjects.size() * 3.0;
    double budgetScore = budgetControl * 0.1;  // Уменьшили множитель
    double experienceScore = managedProjects * 2.0;
    
    double totalScore = baseScore + projectScore + budgetScore + experienceScore;
    return totalScore > 100.0 ? 100.0 : totalScore;  // Ограничили сверху
}

bool ProjectManager::isBudgetOptimized() const {
    if (!managedBudget) return false;
    
    double remaining = managedBudget->calculateRemaining();
    double total = managedBudget->getTotalAmount();
    double utilization = (total - remaining) / total;
    
    return utilization > 0.7 && utilization < 0.9;
}

void ProjectManager::assignToProject(ConstructionProject* project) {
    if (project && currentProjects.size() < managedProjects) {
        currentProjects.push_back(project);
    }
}

void ProjectManager::removeFromProject(const std::string& projectId) {
    currentProjects.erase(
        std::remove_if(currentProjects.begin(), currentProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        currentProjects.end()
    );
}

std::vector<ConstructionProject*> ProjectManager::getCurrentProjects() const {
    return currentProjects;
}

void ProjectManager::setManagedBudget(Budget* budget) {
    this->managedBudget = budget;
}

Budget* ProjectManager::getManagedBudget() const {
    return managedBudget;
}

void ProjectManager::setProjectSchedule(Schedule* schedule) {
    this->projectSchedule = schedule;
}

Schedule* ProjectManager::getProjectSchedule() const {
    return projectSchedule;
}
