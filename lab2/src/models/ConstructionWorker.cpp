#include "ConstructionWorker.h"
#include "Task.h"
#include "SafetyProtocol.h"
#include <algorithm>  // Добавлен для std::remove_if

ConstructionWorker::ConstructionWorker(const std::string& id, const std::string& name, double salary, const std::string& trade, int hours)
    : Employee(id, name, "Construction Worker", salary), trade(trade), hoursWorked(hours),
      safetyTraining(nullptr) {}

double ConstructionWorker::calculateWorkEfficiency() const {
    double baseEfficiency = 70.0;
    double hoursEfficiency = (hoursWorked / 2000.0) * 20.0;
    double taskEfficiency = assignedTasks.size() * 3.0;
    double safetyEfficiency = safetyTraining ? 5.0 : 0.0;
    
    return baseEfficiency + hoursEfficiency + taskEfficiency + safetyEfficiency;
}

bool ConstructionWorker::isQualifiedForTask(const std::string& taskType) const {
    return taskType == trade;
}

double ConstructionWorker::calculateSafetyCompliance() const {
    double baseCompliance = 80.0;
    double trainingCompliance = safetyTraining ? 15.0 : 0.0;
    double hoursCompliance = (hoursWorked > 1000) ? 5.0 : 0.0;
    
    return baseCompliance + trainingCompliance + hoursCompliance;
}

bool ConstructionWorker::canWorkOvertime() const {
    return hoursWorked < 1800 && assignedTasks.size() < 5;
}

void ConstructionWorker::assignTask(Task* task) {
    if (task) {
        assignedTasks.push_back(task);
    }
}

void ConstructionWorker::removeTask(const std::string& taskId) {
    assignedTasks.erase(
        std::remove_if(assignedTasks.begin(), assignedTasks.end(),
            [&taskId](Task* task) {
                return task->getId() == taskId;
            }),
        assignedTasks.end()
    );
}

std::vector<Task*> ConstructionWorker::getAssignedTasks() const {
    return assignedTasks;
}

void ConstructionWorker::setSafetyTraining(SafetyProtocol* protocol) {
    this->safetyTraining = protocol;
}

SafetyProtocol* ConstructionWorker::getSafetyTraining() const {
    return safetyTraining;
}
