#include "Milestone.h"

Milestone::Milestone(const std::string& id, const std::string& name, int targetDay)
    : milestoneId(id), name(name), targetDay(targetDay), completed(false) {}

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
