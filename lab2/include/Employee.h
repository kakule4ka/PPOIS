#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class ConstructionProject;

class Employee {
private:
    std::string id;
    std::string name;
    std::string position;
    double salary;
    std::vector<ConstructionProject*> assignedProjects;
    
public:
    Employee(const std::string& id, const std::string& name, const std::string& position, double salary);
    
    double calculateProductivity() const;
    bool isEligibleForPromotion() const;
    double calculateWorkload() const;
    bool canTakeMoreProjects() const;
    
    void assignToProject(ConstructionProject* project);
    void removeFromProject(const std::string& projectId);
    std::vector<ConstructionProject*> getAssignedProjects() const;
    
    std::string getId() const { return id; }
    double getSalary() const { return salary; }
    std::string getPosition() const { return position; }
};

#endif
