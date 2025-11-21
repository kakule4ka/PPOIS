#include "core/ConstructionProject.h"
#include "models/ProjectManager.h"
#include "models/Employee.h"
#include "models/Budget.h"
#include <algorithm>

ConstructionProject::ConstructionProject(const std::string& id, const std::string& name, double budget, int duration)
    : id(id), name(name), budget(budget), duration(duration),
      projectManager(nullptr), projectBudget(nullptr) {}

double ConstructionProject::calculateMonthlyCost() const {
    return budget / duration;
}

bool ConstructionProject::isOnSchedule(int elapsedMonths, double spent) const {
    double expectedSpent = (budget / duration) * elapsedMonths;
    return spent <= expectedSpent * 1.1;
}

double ConstructionProject::calculateTeamProductivity() const {
    if (teamMembers.empty()) return 0.0;
    
    double totalProductivity = 0.0;
    for (const auto& member : teamMembers) {
        totalProductivity += member->calculateProductivity();
    }
    
    double managerBonus = projectManager ? 1.1 : 1.0;
    double teamSizeFactor = teamMembers.size() > 10 ? 0.9 : 1.0;
    
    return (totalProductivity / teamMembers.size()) * managerBonus * teamSizeFactor;
}

bool ConstructionProject::isBudgetRealistic() const {
    double monthlyCost = calculateMonthlyCost();
    double industryStandard = budget * 0.15;  // Увеличили стандарт
    double teamCapacity = teamMembers.size() * 100000.0;  // Увеличили capacity
    
    return monthlyCost <= industryStandard && monthlyCost <= teamCapacity;
}

void ConstructionProject::setProjectManager(ProjectManager* manager) {
    projectManager = manager;
}

ProjectManager* ConstructionProject::getProjectManager() const {
    return projectManager;
}

void ConstructionProject::addTeamMember(Employee* employee) {
    if (employee) {
        teamMembers.push_back(employee);
    }
}

void ConstructionProject::removeTeamMember(const std::string& employeeId) {
    teamMembers.erase(
        std::remove_if(teamMembers.begin(), teamMembers.end(),
            [&employeeId](Employee* employee) {
                return employee->getId() == employeeId;
            }),
        teamMembers.end()
    );
}

std::vector<Employee*> ConstructionProject::getTeamMembers() const {
    return teamMembers;
}

void ConstructionProject::setBudget(Budget* budget) {
    this->projectBudget = budget;
}

Budget* ConstructionProject::getBudget() const {
    return projectBudget;
}
