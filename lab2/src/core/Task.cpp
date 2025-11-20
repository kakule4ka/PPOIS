#include "Task.h"

Task::Task(const std::string& id, const std::string& description, int estimatedHours)
    : taskId(id), description(description), estimatedHours(estimatedHours), actualHours(0) {}

double Task::calculateEfficiency() const {
    if (estimatedHours <= 0 || actualHours <= 0) {
        return 0.0;
    }
    
    double baseEfficiency = static_cast<double>(estimatedHours) / actualHours;
    
    double complexityFactor = 1.0;
    if (description.find("complex") != std::string::npos || description.find("critical") != std::string::npos) {
        complexityFactor = 0.8;
    }
    
    double adjustedEfficiency = baseEfficiency * complexityFactor;
    
    if (adjustedEfficiency > 2.0) {
        adjustedEfficiency = 2.0;
    }
    
    return adjustedEfficiency;
}

bool Task::isOverdue() const {
    int timeDeviation = actualHours - estimatedHours;
    
    bool isOverTime = timeDeviation > 0;
    bool hasSignificantDelay = timeDeviation > estimatedHours * 0.2;
    bool isCriticalTask = description.find("critical") != std::string::npos;
    
    if (isCriticalTask) {
        return timeDeviation > 0;
    }
    
    return isOverTime && hasSignificantDelay;
}
