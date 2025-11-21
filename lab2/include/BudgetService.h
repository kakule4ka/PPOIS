#ifndef BUDGETSERVICE_H
#define BUDGETSERVICE_H

#include <string>
#include <vector>

class ConstructionProject;
class Budget;

class BudgetService {
private:
    std::string serviceId;
    double totalManagedBudget;
    int budgetItems;
    std::vector<ConstructionProject*> managedProjects;
    std::vector<Budget*> projectBudgets;
    
public:
    BudgetService(const std::string& id, double totalBudget, int items);
    
    double calculateBudgetVariance() const;
    bool detectOverspending() const;
    double calculateBudgetEfficiency() const;
    bool requiresBudgetReview() const;
    
    void addManagedProject(ConstructionProject* project);
    void removeManagedProject(const std::string& projectId);
    std::vector<ConstructionProject*> getManagedProjects() const;
    
    void addProjectBudget(Budget* budget);
    void removeProjectBudget(const std::string& budgetId);
    std::vector<Budget*> getProjectBudgets() const;
    
    std::string getId() const { return serviceId; }
};

#endif
