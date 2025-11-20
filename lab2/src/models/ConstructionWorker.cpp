#include "ConstructionWorker.h"

ConstructionWorker::ConstructionWorker(const std::string& id, const std::string& name, double salary, const std::string& trade, int hours)
    : Employee(id, name, "Construction Worker", salary), trade(trade), hoursWorked(hours) {}

double ConstructionWorker::calculateWorkEfficiency() const {
    return hoursWorked > 0 ? (getSalary() / hoursWorked) * 0.01 : 0.0;
}

bool ConstructionWorker::isQualifiedForTask(const std::string& task) const {
    return task.find(trade) != std::string::npos || trade == "General";
}
