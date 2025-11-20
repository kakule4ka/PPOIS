#include "HRService.h"

HRService::HRService(const std::string& id, int employees, double rate)
    : serviceId(id), managedEmployees(employees), retentionRate(rate) {}

double HRService::calculateWorkforceProductivity() const {
    return retentionRate * 100.0;
}

bool HRService::planRecruitment(int requiredWorkers) const {
    return managedEmployees + requiredWorkers <= 100;
}
