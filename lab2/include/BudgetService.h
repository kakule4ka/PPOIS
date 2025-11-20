#ifndef BUDGETSERVICE_H
#define BUDGETSERVICE_H

#include <string>

class BudgetService {
private:
    std::string serviceId;
    double totalManagedBudget;
    int budgetItems;
    
public:
    BudgetService(const std::string& id, double totalBudget, int items);
    
    double calculateBudgetVariance() const;
    bool detectOverspending() const;
    
    std::string getId() const { return serviceId; }
};

#endif
