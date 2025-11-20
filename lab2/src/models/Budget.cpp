#include "Budget.h"

Budget::Budget(const std::string& id, double total)
    : budgetId(id), totalAmount(total), allocatedAmount(0), spentAmount(0) {}

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
