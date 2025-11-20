#include "Schedule.h"

Schedule::Schedule(const std::string& id, const std::string& projectId, int totalDays)
    : scheduleId(id), projectId(projectId), totalDays(totalDays), completedDays(0) {}

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
