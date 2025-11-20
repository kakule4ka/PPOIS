#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string id;
    std::string name;
    std::string position;
    double salary;
    
public:
    Employee(const std::string& id, const std::string& name, const std::string& position, double salary);
    
    double calculateProductivity() const;
    bool isEligibleForPromotion() const;
    
    std::string getId() const { return id; }
    double getSalary() const { return salary; }
    std::string getPosition() const { return position; }
};

#endif
