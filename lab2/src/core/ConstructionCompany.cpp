#include "ConstructionCompany.h"
#include "ConstructionProject.h"
#include "Employee.h"
#include <algorithm>

ConstructionCompany::ConstructionCompany(const std::string& name, const std::string& license, int year)
    : name(name), license(license), foundedYear(year) {}

double ConstructionCompany::calculateMaxProjectCapacity() const {
    return foundedYear < 2000 ? 10000000.0 : 5000000.0;
}

bool ConstructionCompany::verifyLicense() const {
    return license.length() >= 8 && license.find("CONST") != std::string::npos;
}

double ConstructionCompany::calculateTotalWorkforceCapacity() const {
    double baseCapacity = employees.size() * 10000.0;
    double experienceBonus = foundedYear < 2010 ? 1.2 : 1.0;
    double licenseBonus = verifyLicense() ? 1.1 : 1.0;
    return baseCapacity * experienceBonus * licenseBonus;
}

bool ConstructionCompany::canHandleProject(double projectBudget, int projectDuration) const {
    double maxCapacity = calculateMaxProjectCapacity();
    double workforceCapacity = calculateTotalWorkforceCapacity();
    double monthlyWorkload = projectBudget / projectDuration;
    return projectBudget <= maxCapacity && monthlyWorkload <= workforceCapacity;
}

void ConstructionCompany::addProject(ConstructionProject* project) {
    if (project) {
        projects.push_back(project);
    }
}

void ConstructionCompany::removeProject(const std::string& projectId) {
    projects.erase(
        std::remove_if(projects.begin(), projects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        projects.end()
    );
}

std::vector<ConstructionProject*> ConstructionCompany::getProjects() const {
    return projects;
}

void ConstructionCompany::addEmployee(Employee* employee) {
    if (employee) {
        employees.push_back(employee);
    }
}

void ConstructionCompany::removeEmployee(const std::string& employeeId) {
    employees.erase(
        std::remove_if(employees.begin(), employees.end(),
            [&employeeId](Employee* employee) {
                return employee->getId() == employeeId;
            }),
        employees.end()
    );
}

std::vector<Employee*> ConstructionCompany::getEmployees() const {
    return employees;
}
