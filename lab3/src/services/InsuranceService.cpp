#include "InsuranceService.h"
#include "Insurance.h"
#include <algorithm>

InsuranceService::InsuranceService(const std::string& serviceId)
    : serviceId(serviceId) {}

double InsuranceService::calculateCoverageEfficiency() const {
    if (managedInsurances.empty()) return 0.0;
    
    double totalEfficiency = 0.0;
    int comprehensivePlans = 0;
    
    for (const auto& insurance : managedInsurances) {
        if (insurance->getPlanType() == "Premium") {
            comprehensivePlans++;
        }
        
        // Simulate efficiency calculation
        double efficiency = insurance->getCoveragePercentage() * 0.8;
        totalEfficiency += efficiency;
    }
    
    double avgEfficiency = totalEfficiency / managedInsurances.size();
    double premiumPlanBonus = (static_cast<double>(comprehensivePlans) / managedInsurances.size()) * 20.0;
    
    return std::min(avgEfficiency + premiumPlanBonus, 100.0);
}

bool InsuranceService::validateInsuranceNetwork() const {
    if (managedInsurances.empty()) return false;
    
    int validInsurances = 0;
    for (const auto& insurance : managedInsurances) {
        if (insurance->getCoveragePercentage() >= 70.0) {
            validInsurances++;
        }
    }
    
    double validRate = static_cast<double>(validInsurances) / managedInsurances.size();
    return validRate >= 0.8;
}

double InsuranceService::getAverageCoverageRate() const {
    if (managedInsurances.empty()) return 0.0;
    
    double totalCoverage = 0.0;
    for (const auto& insurance : managedInsurances) {
        totalCoverage += insurance->getCoveragePercentage();
    }
    
    return totalCoverage / managedInsurances.size();
}

void InsuranceService::addManagedInsurance(Insurance* insurance) {
    if (insurance) {
        managedInsurances.push_back(insurance);
    }
}

void InsuranceService::removeManagedInsurance(const std::string& insuranceId) {
    managedInsurances.erase(
        std::remove_if(managedInsurances.begin(), managedInsurances.end(),
            [&insuranceId](Insurance* insurance) {
                return insurance->getId() == insuranceId;
            }),
        managedInsurances.end()
    );
}

std::vector<Insurance*> InsuranceService::getManagedInsurances() const {
    return managedInsurances;
}
