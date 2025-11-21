#ifndef EMERGENCYSERVICE_H
#define EMERGENCYSERVICE_H

#include <string>
#include <vector>

class EmergencyCase;

class EmergencyService {
private:
    std::string serviceId;
    std::vector<EmergencyCase*> activeCases;

public:
    EmergencyService(const std::string& serviceId);
    
    double calculateResponseEffectiveness() const;
    bool canHandleMassCasualty() const;
    int getActiveCaseCount() const;
    
    void addActiveCase(EmergencyCase* emergency);
    void removeActiveCase(const std::string& caseId);
    std::vector<EmergencyCase*> getActiveCases() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
