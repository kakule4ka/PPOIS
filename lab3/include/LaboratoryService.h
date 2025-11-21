#ifndef LABORATORYSERVICE_H
#define LABORATORYSERVICE_H

#include <string>
#include <vector>

class LaboratoryTest;

class LaboratoryService {
private:
    std::string serviceId;
    std::vector<LaboratoryTest*> activeTests;

public:
    LaboratoryService(const std::string& serviceId);
    
    double calculateProcessingEfficiency() const;
    bool validateTestAccuracy() const;
    int getPendingTestCount() const;
    
    void addActiveTest(LaboratoryTest* test);
    void removeActiveTest(const std::string& testId);
    std::vector<LaboratoryTest*> getActiveTests() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
