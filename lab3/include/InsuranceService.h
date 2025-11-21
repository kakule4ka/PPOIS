#ifndef INSURANCESERVICE_H
#define INSURANCESERVICE_H

#include <string>
#include <vector>

class Insurance;

class InsuranceService {
private:
    std::string serviceId;
    std::vector<Insurance*> managedInsurances;

public:
    InsuranceService(const std::string& serviceId);
    
    double calculateCoverageEfficiency() const;
    bool validateInsuranceNetwork() const;
    double getAverageCoverageRate() const;
    
    void addManagedInsurance(Insurance* insurance);
    void removeManagedInsurance(const std::string& insuranceId);
    std::vector<Insurance*> getManagedInsurances() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
