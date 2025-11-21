#include "services/SchedulingService.h"

SchedulingService::SchedulingService(const std::string& id, int tasks, double rate)
    : serviceId(id), scheduledTasks(tasks), onTimeRate(rate) {}

double SchedulingService::calculateScheduleEfficiency() const {
    double baseEfficiency = onTimeRate * 100.0;
    
    double taskLoadFactor = 1.0;
    if (scheduledTasks > 100) {
        taskLoadFactor = 0.85;
    } else if (scheduledTasks > 50) {
        taskLoadFactor = 0.9;
    } else if (scheduledTasks > 20) {
        taskLoadFactor = 0.95;
    } else if (scheduledTasks < 10) {
        taskLoadFactor = 1.05;
    }
    
    double complexityFactor = 1.0;
    if (serviceId.find("COMPLEX") != std::string::npos) {
        complexityFactor = 0.9;
    } else if (serviceId.find("SIMPLE") != std::string::npos) {
        complexityFactor = 1.1;
    }
    
    double resourceFactor = 1.0;
    double toolsFactor = 1.05;
    
    double totalEfficiency = baseEfficiency * taskLoadFactor * complexityFactor * resourceFactor * toolsFactor;
    
    if (totalEfficiency > 100.0) {
        totalEfficiency = 100.0;
    }
    
    return totalEfficiency;
}

bool SchedulingService::optimizeResourceAllocation() const {
    return onTimeRate > 0.8;
}
