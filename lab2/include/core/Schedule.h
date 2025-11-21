#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

class ConstructionProject;
class Task;
class Milestone;

class Schedule {
private:
    std::string scheduleId;
    std::string projectId;
    int totalDays;
    int completedDays;
    ConstructionProject* project;
    std::vector<Task*> tasks;
    std::vector<Milestone*> milestones;
    
public:
    Schedule(const std::string& id, const std::string& projectId, int totalDays);
    
    double calculateProgressPercentage() const;
    bool isAheadOfSchedule() const;
    double calculateCriticalPathDuration() const;
    bool hasScheduleConflicts() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addTask(Task* task);
    void removeTask(const std::string& taskId);
    std::vector<Task*> getTasks() const;
    
    void addMilestone(Milestone* milestone);
    void removeMilestone(const std::string& milestoneId);
    std::vector<Milestone*> getMilestones() const;
    
    std::string getId() const { return scheduleId; }
    void setCompletedDays(int days) { completedDays = days; }
};

#endif
