#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "Employee.h"
#include <vector>

class ConstructionProject;
class Budget;
class Schedule;

class ProjectManager : public Employee {
private:
    int managedProjects;
    double budgetControl;
    std::vector<ConstructionProject*> currentProjects;
    Budget* managedBudget;
    Schedule* projectSchedule;
    
public:
    ProjectManager(const std::string& id, const std::string& name, double salary, int projects, double budget);
    
    double calculateManagementEfficiency() const;
    bool canHandleMoreProjects() const;
    double calculateRiskMitigationScore() const;
    bool isBudgetOptimized() const;
    
    void assignToProject(ConstructionProject* project);
    void removeFromProject(const std::string& projectId);
    std::vector<ConstructionProject*> getCurrentProjects() const;
    
    void setManagedBudget(Budget* budget);
    Budget* getManagedBudget() const;
    
    void setProjectSchedule(Schedule* schedule);
    Schedule* getProjectSchedule() const;
};

#endif
