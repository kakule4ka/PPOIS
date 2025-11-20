#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "Employee.h"

class ProjectManager : public Employee {
private:
    int managedProjects;
    double budgetControl;
    
public:
    ProjectManager(const std::string& id, const std::string& name, double salary, int projects, double budget);
    
    double calculateManagementEfficiency() const;
    bool canHandleMoreProjects() const;
};

#endif
