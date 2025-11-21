#ifndef CONSTRUCTIONPROJECT_H
#define CONSTRUCTIONPROJECT_H

#include <string>
#include <vector>

class ProjectManager;
class Employee;
class Budget;

class ConstructionProject {
private:
    std::string id;
    std::string name;
    double budget;
    int duration;
    ProjectManager* projectManager;
    std::vector<Employee*> teamMembers;
    Budget* projectBudget;
    
public:
    ConstructionProject(const std::string& id, const std::string& name, double budget, int duration);
    
    double calculateMonthlyCost() const;
    bool isOnSchedule(int elapsedMonths, double spent) const;
    double calculateTeamProductivity() const;
    bool isBudgetRealistic() const;
    
    void setProjectManager(ProjectManager* manager);
    ProjectManager* getProjectManager() const;
    
    void addTeamMember(Employee* employee);
    void removeTeamMember(const std::string& employeeId);
    std::vector<Employee*> getTeamMembers() const;
    
    void setBudget(Budget* budget);
    Budget* getBudget() const;
    
    std::string getId() const { return id; }
    int getDuration() const { return duration; } // Добавлен getter
};

#endif
