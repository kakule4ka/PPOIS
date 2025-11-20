#include "BudgetService.h"

BudgetService::BudgetService(const std::string& id, double totalBudget, int items)
    : serviceId(id), totalManagedBudget(totalBudget), budgetItems(items) {}

double BudgetService::calculateBudgetVariance() const {
    return totalManagedBudget * 0.05;
}

bool BudgetService::detectOverspending() const {
    return totalManagedBudget > 1000000;
}
