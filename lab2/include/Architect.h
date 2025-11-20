#ifndef ARCHITECT_H
#define ARCHITECT_H

#include "Employee.h"

class Architect : public Employee {
private:
    int completedDesigns;
    std::string specialty;
    
public:
    Architect(const std::string& id, const std::string& name, double salary, int designs, const std::string& specialty);
    
    double calculateDesignComplexity() const;
    bool validateCodeCompliance(const std::string& code) const;
};

#endif
