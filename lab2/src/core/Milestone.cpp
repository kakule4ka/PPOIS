#include "Milestone.h"
#include "ConstructionProject.h"
#include "Task.h"
#include <algorithm>

Milestone::Milestone(const std::string& id, const std::string& name, int targetDay)
    : milestoneId(id), name(name), targetDay(targetDay), completed(false),
      project(nullptr) {}

int Milestone::calculateDaysUntilDeadline(int currentDay) const {
    if (completed) {
        return 0;
    }
    return targetDay - currentDay;
}

bool Milestone::isCriticalPath() const {
    bool isStructural = name.find("Foundation") != std::string::npos || 
                       name.find("Structure") != std::string::npos ||
                       name.find("Frame") != std::string::npos;
    
    bool isEarlyStage = targetDay <= 30;
    bool hasDependencies = name.find("Completion") == std::string::npos;
    
    return isStructural || (isEarlyStage && hasDependencies);
}

double Milestone::calculateCompletionProbability() const {
    double baseProbability = 0.8;
    
    double daysFactor = 1.0 - (targetDay * 0.005);
    if (daysFactor < 0.5) daysFactor = 0.5;
    
    double dependencyFactor = 1.0;
    for (const auto& task : dependentTasks) {
        if (task->isOverdue()) {
            dependencyFactor -= 0.1;
        }
    }
    
    double projectFactor = project ? 1.05 : 1.0;
    double criticalFactor = isCriticalPath() ? 0.9 : 1.0;
    
    double finalProbability = baseProbability * daysFactor * dependencyFactor * projectFactor * criticalFactor;
    return finalProbability > 1.0 ? 1.0 : finalProbability;
}

bool Milestone::hasDependenciesCompleted() const {
    if (dependentTasks.empty()) return true;
    
    int completedTasks = 0;
    for (const auto& task : dependentTasks) {
        if (task->getActualHours() >= task->getEstimatedHours()) {
            completedTasks++;
        }
    }
    
    double completionRate = static_cast<double>(completedTasks) / dependentTasks.size();
    return completionRate >= 0.9;
}

void Milestone::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* Milestone::getProject() const {
    return project;
}

void Milestone::addDependentTask(Task* task) {
    if (task) {
        dependentTasks.push_back(task);
    }
}

void Milestone::removeDependentTask(const std::string& taskId) {
    dependentTasks.erase(
        std::remove_if(dependentTasks.begin(), dependentTasks.end(),
            [&taskId](Task* task) {
                return task->getId() == taskId;
            }),
        dependentTasks.end()
    );
}

std::vector<Task*> Milestone::getDependentTasks() const {
    return dependentTasks;
}
