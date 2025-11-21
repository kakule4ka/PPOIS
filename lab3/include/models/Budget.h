#ifndef BUDGET_H
#define BUDGET_H

#include <string>
#include <vector>

class ConstructionProject;
class CostEstimate;

class Budget {
private:
    std::string budgetId;
    double totalAmount;
    double allocatedAmount;
    double spentAmount;
    ConstructionProject* associatedProject;
    std::vector<CostEstimate*> costEstimates;
    
public:
    Budget(const std::string& id, double total);
    
    double calculateRemaining() const;
    bool canAllocate(double amount) const;
    double calculateCostVariance() const;
    bool isOverBudget() const;
    
    void setAssociatedProject(ConstructionProject* project);
    ConstructionProject* getAssociatedProject() const;
    
    void addCostEstimate(CostEstimate* estimate);
    void removeCostEstimate(const std::string& estimateId);
    std::vector<CostEstimate*> getCostEstimates() const;
    
    std::string getId() const { return budgetId; }
    double getTotalAmount() const { return totalAmount; }  // Добавлен getter
};

#endif
