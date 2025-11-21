#ifndef CONSTRUCTIONCOMPANY_H
#define CONSTRUCTIONCOMPANY_H

#include <string>
#include <vector>

class ConstructionProject;
class Employee;

class ConstructionCompany {
private:
    std::string name;
    std::string license;
    int foundedYear;
    std::vector<ConstructionProject*> projects;
    std::vector<Employee*> employees;
    
public:
    ConstructionCompany(const std::string& name, const std::string& license, int year);
    
    double calculateMaxProjectCapacity() const;
    bool verifyLicense() const;
    double calculateTotalWorkforceCapacity() const;
    bool canHandleProject(double projectBudget, int projectDuration) const;
    
    void addProject(ConstructionProject* project);
    void removeProject(const std::string& projectId);
    std::vector<ConstructionProject*> getProjects() const;
    
    void addEmployee(Employee* employee);
    void removeEmployee(const std::string& employeeId);
    std::vector<Employee*> getEmployees() const;
    
    std::string getName() const { return name; }
};

#endif
