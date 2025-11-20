#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>

class Milestone {
private:
    std::string milestoneId;
    std::string name;
    int targetDay;
    bool completed;
    
public:
    Milestone(const std::string& id, const std::string& name, int targetDay);
    
    int calculateDaysUntilDeadline(int currentDay) const;
    bool isCriticalPath() const;
    
    std::string getId() const { return milestoneId; }
};

#endif
