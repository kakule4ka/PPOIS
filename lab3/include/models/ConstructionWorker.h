#ifndef CONSTRUCTIONWORKER_H
#define CONSTRUCTIONWORKER_H

#include "models/Employee.h"
#include <vector>

class Task;
class SafetyProtocol;

class ConstructionWorker : public Employee {
private:
    std::string trade;
    int hoursWorked;
    std::vector<Task*> assignedTasks;
    SafetyProtocol* safetyTraining;
    
public:
    ConstructionWorker(const std::string& id, const std::string& name, double salary, const std::string& trade, int hours);
    
    double calculateWorkEfficiency() const;
    bool isQualifiedForTask(const std::string& task) const;
    double calculateSafetyCompliance() const;
    bool canWorkOvertime() const;
    
    void assignTask(Task* task);
    void removeTask(const std::string& taskId);
    std::vector<Task*> getAssignedTasks() const;
    
    void setSafetyTraining(SafetyProtocol* protocol);
    SafetyProtocol* getSafetyTraining() const;
};

#endif
