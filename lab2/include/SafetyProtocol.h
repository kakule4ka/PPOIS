#ifndef SAFETYPROTOCOL_H
#define SAFETYPROTOCOL_H

#include <string>

class SafetyProtocol {
private:
    std::string protocolId;
    std::string name;
    int requiredTrainingHours;
    bool isMandatory;
    
public:
    SafetyProtocol(const std::string& id, const std::string& name, int trainingHours, bool mandatory);
    
    bool validateWorkerCompliance(int trainingHours) const;
    double calculateComplianceRate(int compliantWorkers, int totalWorkers) const;
    
    std::string getId() const { return protocolId; }
};

#endif
