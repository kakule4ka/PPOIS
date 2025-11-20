#ifndef CONSTRUCTIONWORKER_H
#define CONSTRUCTIONWORKER_H

#include "Employee.h"

class ConstructionWorker : public Employee {
private:
    std::string trade;
    int hoursWorked;
    
public:
    ConstructionWorker(const std::string& id, const std::string& name, double salary, const std::string& trade, int hours);
    
    double calculateWorkEfficiency() const;
    bool isQualifiedForTask(const std::string& task) const;
};

#endif
