#include "SafetyProtocol.h"

SafetyProtocol::SafetyProtocol(const std::string& id, const std::string& name, int trainingHours, bool mandatory)
    : protocolId(id), name(name), requiredTrainingHours(trainingHours), isMandatory(mandatory) {}

bool SafetyProtocol::validateWorkerCompliance(int trainingHours) const {
    int minimumRequired = requiredTrainingHours;
    
    if (isMandatory) {
        minimumRequired = requiredTrainingHours;
    } else {
        minimumRequired = requiredTrainingHours * 0.7;
    }
    
    bool meetsTrainingRequirement = trainingHours >= minimumRequired;
    bool hasRecentTraining = trainingHours >= requiredTrainingHours * 0.5;
    
    if (name.find("Emergency") != std::string::npos) {
        return meetsTrainingRequirement && hasRecentTraining;
    }
    
    return meetsTrainingRequirement;
}

double SafetyProtocol::calculateComplianceRate(int compliantWorkers, int totalWorkers) const {
    if (totalWorkers <= 0) {
        return 0.0;
    }
    
    double baseRate = (static_cast<double>(compliantWorkers) / totalWorkers) * 100.0;
    
    double protocolFactor = 1.0;
    if (isMandatory) {
        protocolFactor = 1.2;
    }
    
    if (requiredTrainingHours > 20) {
        protocolFactor *= 0.9;
    }
    
    double adjustedRate = baseRate * protocolFactor;
    
    if (adjustedRate > 100.0) {
        adjustedRate = 100.0;
    }
    
    return adjustedRate;
}
