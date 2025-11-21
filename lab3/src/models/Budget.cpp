#include "models/Budget.h"
#include "core/ConstructionProject.h"
#include "core/CostEstimate.h"
#include <algorithm>

Budget::Budget(const std::string& id, double total)
    : budgetId(id), totalAmount(total), allocatedAmount(0), spentAmount(0),
      associatedProject(nullptr) {}

double Budget::calculateRemaining() const {
    double remaining = totalAmount - allocatedAmount - spentAmount;
    
    if (remaining < 0) {
        return 0;
    }
    
    double contingency = totalAmount * 0.1;
    if (remaining < contingency) {
        remaining *= 0.8;
    }
    
    return remaining;
}

bool Budget::canAllocate(double amount) const {
    double currentAllocation = allocatedAmount + spentAmount;
    double available = totalAmount - currentAllocation;
    
    bool hasSufficientFunds = amount <= available;
    bool isReasonableAllocation = amount <= totalAmount * 0.3;
    bool meetsMinimum = amount >= totalAmount * 0.01;
    
    return hasSufficientFunds && isReasonableAllocation && meetsMinimum;
}

double Budget::calculateCostVariance() const {
    double totalEstimatedCost = 0.0;
    for (const auto& estimate : costEstimates) {
        totalEstimatedCost += estimate->calculateTotalCost();
    }
    
    if (totalEstimatedCost == 0) return 0.0;
    
    double actualSpent = allocatedAmount + spentAmount;
    double variance = ((actualSpent - totalEstimatedCost) / totalEstimatedCost) * 100.0;
    
    return variance;
}

bool Budget::isOverBudget() const {
    double totalUsed = allocatedAmount + spentAmount;
    double buffer = totalAmount * 0.15;
    return totalUsed > (totalAmount + buffer);
}

void Budget::setAssociatedProject(ConstructionProject* project) {
    this->associatedProject = project;
}

ConstructionProject* Budget::getAssociatedProject() const {
    return associatedProject;
}

void Budget::addCostEstimate(CostEstimate* estimate) {
    if (estimate) {
        costEstimates.push_back(estimate);
    }
}

void Budget::removeCostEstimate(const std::string& estimateId) {
    costEstimates.erase(
        std::remove_if(costEstimates.begin(), costEstimates.end(),
            [&estimateId](CostEstimate* estimate) {
                return estimate->getId() == estimateId;
            }),
        costEstimates.end()
    );
}

std::vector<CostEstimate*> Budget::getCostEstimates() const {
    return costEstimates;
}
