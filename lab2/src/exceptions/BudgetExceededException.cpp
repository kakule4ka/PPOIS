#include "exceptions/BudgetExceededException.h"

BudgetExceededException::BudgetExceededException(double exceeded)
    : std::runtime_error("Budget exceeded by " + std::to_string(exceeded)),
      exceededAmount(exceeded) {}

double BudgetExceededException::getExceededAmount() const {
    return exceededAmount;
}
