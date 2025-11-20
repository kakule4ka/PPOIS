#ifndef HRSERVICE_H
#define HRSERVICE_H

#include <string>

class HRService {
private:
    std::string serviceId;
    int managedEmployees;
    double retentionRate;
    
public:
    HRService(const std::string& id, int employees, double rate);
    
    double calculateWorkforceProductivity() const;
    bool planRecruitment(int requiredWorkers) const;
    
    std::string getId() const { return serviceId; }
};

#endif
