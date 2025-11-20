#include "Employee.h"
#include <algorithm>

Employee::Employee(const std::string& id, const std::string& name, const std::string& position, double salary)
    : id(id), name(name), position(position), salary(salary) {}

double Employee::calculateProductivity() const {
    double baseProductivity = 1.0;
    if (position == "Manager") baseProductivity = 1.5;
    if (position == "Architect") baseProductivity = 1.3;
    if (position == "Construction Worker") baseProductivity = 0.8;
    
    double salaryFactor = std::min(salary / 50000.0, 2.0);
    return baseProductivity * salaryFactor;
}

bool Employee::isEligibleForPromotion() const {
    return salary < 80000.0 && position != "Director";
}
