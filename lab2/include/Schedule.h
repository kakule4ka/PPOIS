#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>

class Schedule {
private:
    std::string scheduleId;
    std::string projectId;
    int totalDays;
    int completedDays;
    
public:
    Schedule(const std::string& id, const std::string& projectId, int totalDays);
    
    double calculateProgressPercentage() const;
    bool isAheadOfSchedule() const;
    
    std::string getId() const { return scheduleId; }
    void setCompletedDays(int days) { completedDays = days; }
};

#endif
