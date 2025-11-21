#include "BudgetService.h"
#include "ConstructionProject.h"
#include "Budget.h"
#include <algorithm>

BudgetService::BudgetService(const std::string& id, double totalBudget, int items)
    : serviceId(id), totalManagedBudget(totalBudget), budgetItems(items) {}

double BudgetService::calculateBudgetVariance() const {
    return totalManagedBudget * 0.05;
}

bool BudgetService::detectOverspending() const {
    return totalManagedBudget > 1000000;
}

double BudgetService::calculateBudgetEfficiency() const {
    double baseEfficiency = 75.0;
    
    double budgetEfficiency = (totalManagedBudget <= 5000000) ? 10.0 : -5.0;
    double itemEfficiency = (budgetItems >= 10 && budgetItems <= 50) ? 8.0 : -3.0;
    double projectEfficiency = managedProjects.size() * 2.0;
    double budgetManagementEfficiency = projectBudgets.size() * 1.5;
    
    double totalEfficiency = baseEfficiency + budgetEfficiency + itemEfficiency + 
                            projectEfficiency + budgetManagementEfficiency;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool BudgetService::requiresBudgetReview() const {
    double efficiency = calculateBudgetEfficiency();
    bool hasLowEfficiency = efficiency < 70.0;
    bool hasOverspending = detectOverspending();
    bool hasFewProjects = managedProjects.size() < 2;
    bool hasLimitedBudgets = projectBudgets.size() < 3;
    bool hasManyItems = budgetItems > 100;
    
    return hasLowEfficiency || hasOverspending || hasFewProjects || 
           hasLimitedBudgets || hasManyItems;
}

void BudgetService::addManagedProject(ConstructionProject* project) {
    if (project) {
        managedProjects.push_back(project);
    }
}

void BudgetService::removeManagedProject(const std::string& projectId) {
    managedProjects.erase(
        std::remove_if(managedProjects.begin(), managedProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        managedProjects.end()
    );
}

std::vector<ConstructionProject*> BudgetService::getManagedProjects() const {
    return managedProjects;
}

void BudgetService::addProjectBudget(Budget* budget) {
    if (budget) {
        projectBudgets.push_back(budget);
    }
}

void BudgetService::removeProjectBudget(const std::string& budgetId) {
    projectBudgets.erase(
        std::remove_if(projectBudgets.begin(), projectBudgets.end(),
            [&budgetId](Budget* budget) {
                return budget->getId() == budgetId;
            }),
        projectBudgets.end()
    );
}

std::vector<Budget*> BudgetService::getProjectBudgets() const {
    return projectBudgets;
}
