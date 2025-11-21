#ifndef HRSERVICE_H
#define HRSERVICE_H

#include <string>
#include <vector>

class Employee;
class ConstructionProject;

class HRService {
private:
    std::string serviceId;
    int managedEmployees;
    double retentionRate;
    std::vector<Employee*> employees;
    std::vector<ConstructionProject*> staffedProjects;
    
public:
    HRService(const std::string& id, int employees, double rate);
    
    double calculateWorkforceProductivity() const;
    bool planRecruitment(int requiredWorkers) const;
    double calculateHRServiceEffectiveness() const;
    bool needsWorkforcePlanning() const;
    
    void addEmployee(Employee* employee);
    void removeEmployee(const std::string& employeeId);
    std::vector<Employee*> getEmployees() const;
    
    void addStaffedProject(ConstructionProject* project);
    void removeStaffedProject(const std::string& projectId);
    std::vector<ConstructionProject*> getStaffedProjects() const;
    
    std::string getId() const { return serviceId; }
};

#endif
