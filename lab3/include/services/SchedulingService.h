#ifndef SCHEDULINGSERVICE_H
#define SCHEDULINGSERVICE_H

#include <string>

class SchedulingService {
private:
    std::string serviceId;
    int scheduledTasks;
    double onTimeRate;
    
public:
    SchedulingService(const std::string& id, int tasks, double rate);
    
    double calculateScheduleEfficiency() const;
    bool optimizeResourceAllocation() const;
    
    std::string getId() const { return serviceId; }
};

#endif
