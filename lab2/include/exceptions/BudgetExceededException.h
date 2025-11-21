#ifndef BUDGETEXCEEDEDEXCEPTION_H
#define BUDGETEXCEEDEDEXCEPTION_H

#include <stdexcept>
#include <string>

class BudgetExceededException : public std::runtime_error {
private:
    double exceededAmount;
    
public:
    BudgetExceededException(double exceeded);
    double getExceededAmount() const;
};

#endif
