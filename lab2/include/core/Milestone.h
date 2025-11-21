#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
#include <vector>

class ConstructionProject;
class Task;

class Milestone {
private:
    std::string milestoneId;
    std::string name;
    int targetDay;
    bool completed;
    ConstructionProject* project;
    std::vector<Task*> dependentTasks;
    
public:
    Milestone(const std::string& id, const std::string& name, int targetDay);
    
    int calculateDaysUntilDeadline(int currentDay) const;
    bool isCriticalPath() const;
    double calculateCompletionProbability() const;
    bool hasDependenciesCompleted() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addDependentTask(Task* task);
    void removeDependentTask(const std::string& taskId);
    std::vector<Task*> getDependentTasks() const;
    
    std::string getId() const { return milestoneId; }
};

#endif
