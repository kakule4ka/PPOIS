#include "services/HRService.h"
#include "models/Employee.h"
#include "core/ConstructionProject.h"
#include <algorithm>

HRService::HRService(const std::string& id, int employees, double rate)
    : serviceId(id), managedEmployees(employees), retentionRate(rate) {}

double HRService::calculateWorkforceProductivity() const {
    return retentionRate * 100.0;
}

bool HRService::planRecruitment(int requiredWorkers) const {
    return managedEmployees + requiredWorkers <= 100;
}

double HRService::calculateHRServiceEffectiveness() const {
    double baseEffectiveness = 70.0;
    
    double employeeEffectiveness = managedEmployees * 0.6;
    double retentionEffectiveness = retentionRate * 25.0;
    double employeeManagementEffectiveness = employees.size() * 1.0;
    double projectStaffingEffectiveness = staffedProjects.size() * 1.8;
    
    double totalEffectiveness = baseEffectiveness + employeeEffectiveness + retentionEffectiveness + 
                               employeeManagementEffectiveness + projectStaffingEffectiveness;
    
    return totalEffectiveness > 100.0 ? 100.0 : totalEffectiveness;
}

bool HRService::needsWorkforcePlanning() const {
    double effectiveness = calculateHRServiceEffectiveness();
    bool hasLowEffectiveness = effectiveness < 75.0;
    bool hasHighTurnover = retentionRate < 0.75;
    bool hasManyEmployees = managedEmployees > 80;
    bool hasFewStaffedProjects = staffedProjects.size() < 3;
    bool hasLimitedEmployeeManagement = employees.size() < 10;
    
    return hasLowEffectiveness || hasHighTurnover || hasManyEmployees || 
           hasFewStaffedProjects || hasLimitedEmployeeManagement;
}

void HRService::addEmployee(Employee* employee) {
    if (employee) {
        employees.push_back(employee);
    }
}

void HRService::removeEmployee(const std::string& employeeId) {
    employees.erase(
        std::remove_if(employees.begin(), employees.end(),
            [&employeeId](Employee* employee) {
                return employee->getId() == employeeId;
            }),
        employees.end()
    );
}

std::vector<Employee*> HRService::getEmployees() const {
    return employees;
}

void HRService::addStaffedProject(ConstructionProject* project) {
    if (project) {
        staffedProjects.push_back(project);
    }
}

void HRService::removeStaffedProject(const std::string& projectId) {
    staffedProjects.erase(
        std::remove_if(staffedProjects.begin(), staffedProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        staffedProjects.end()
    );
}

std::vector<ConstructionProject*> HRService::getStaffedProjects() const {
    return staffedProjects;
}
