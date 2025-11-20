#ifndef BUDGET_H
#define BUDGET_H

#include <string>

class Budget {
private:
    std::string budgetId;
    double totalAmount;
    double allocatedAmount;
    double spentAmount;
    
public:
    Budget(const std::string& id, double total);
    
    double calculateRemaining() const;
    bool canAllocate(double amount) const;
    
    std::string getId() const { return budgetId; }
};

#endif
