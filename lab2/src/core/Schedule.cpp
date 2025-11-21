#include "Schedule.h"
#include "ConstructionProject.h"
#include "Task.h"
#include "Milestone.h"
#include <algorithm>

Schedule::Schedule(const std::string& id, const std::string& projectId, int totalDays)
    : scheduleId(id), projectId(projectId), totalDays(totalDays), completedDays(0),
      project(nullptr) {}

double Schedule::calculateProgressPercentage() const {
    if (totalDays <= 0) {
        return 0.0;
    }
    
    double baseProgress = (static_cast<double>(completedDays) / totalDays) * 100.0;
    
    double efficiencyFactor = 1.0;
    if (projectId.find("FAST") != std::string::npos) {
        efficiencyFactor = 1.1;
    } else if (projectId.find("COMPLEX") != std::string::npos) {
        efficiencyFactor = 0.9;
    }
    
    double adjustedProgress = baseProgress * efficiencyFactor;
    
    if (adjustedProgress > 100.0) {
        adjustedProgress = 100.0;
    }
    
    return adjustedProgress;
}

bool Schedule::isAheadOfSchedule() const {
    double expectedProgress = (static_cast<double>(completedDays) / totalDays) * 100.0;
    double actualProgress = calculateProgressPercentage();
    
    bool isAhead = actualProgress > expectedProgress;
    bool hasBuffer = (totalDays - completedDays) >= 7;
    bool isConsistent = completedDays >= totalDays * 0.1;
    
    return isAhead && hasBuffer && isConsistent;
}

double Schedule::calculateCriticalPathDuration() const {
    double totalTaskDuration = 0.0;
    int criticalTasks = 0;
    
    for (const auto& task : tasks) {
        if (task->isOverdue()) {
            totalTaskDuration += task->getEstimatedHours() * 1.2;
            criticalTasks++;
        } else {
            totalTaskDuration += task->getEstimatedHours();
        }
    }
    
    double milestoneBuffer = milestones.size() * 2.0;
    double complexityFactor = criticalTasks > 0 ? 1.15 : 1.0;
    
    return (totalTaskDuration / 8.0) * complexityFactor + milestoneBuffer;
}

bool Schedule::hasScheduleConflicts() const {
    if (tasks.empty()) return false;
    
    int overdueTasks = 0;
    double totalEstimated = 0.0;
    double totalActual = 0.0;
    
    for (const auto& task : tasks) {
        if (task->isOverdue()) {
            overdueTasks++;
        }
        totalEstimated += task->getEstimatedHours();
        totalActual += task->getActualHours();
    }
    
    double efficiencyRatio = totalActual > 0 ? totalEstimated / totalActual : 1.0;
    bool hasManyOverdue = overdueTasks > (tasks.size() * 0.3);
    bool isInefficient = efficiencyRatio < 0.8;
    
    return hasManyOverdue || isInefficient;
}

void Schedule::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* Schedule::getProject() const {
    return project;
}

void Schedule::addTask(Task* task) {
    if (task) {
        tasks.push_back(task);
    }
}

void Schedule::removeTask(const std::string& taskId) {
    tasks.erase(
        std::remove_if(tasks.begin(), tasks.end(),
            [&taskId](Task* task) {
                return task->getId() == taskId;
            }),
        tasks.end()
    );
}

std::vector<Task*> Schedule::getTasks() const {
    return tasks;
}

void Schedule::addMilestone(Milestone* milestone) {
    if (milestone) {
        milestones.push_back(milestone);
    }
}

void Schedule::removeMilestone(const std::string& milestoneId) {
    milestones.erase(
        std::remove_if(milestones.begin(), milestones.end(),
            [&milestoneId](Milestone* milestone) {
                return milestone->getId() == milestoneId;
            }),
        milestones.end()
    );
}

std::vector<Milestone*> Schedule::getMilestones() const {
    return milestones;
}
