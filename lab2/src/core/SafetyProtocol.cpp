#include "SafetyProtocol.h"
#include "ConstructionProject.h"
#include "Employee.h"
#include "Equipment.h"
#include <algorithm>

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
    
    double projectFactor = 1.0 + (applicableProjects.size() * 0.02);
    double equipmentFactor = 1.0 + (relatedEquipment.size() * 0.01);
    
    double adjustedRate = baseRate * protocolFactor * projectFactor * equipmentFactor;
    
    if (adjustedRate > 100.0) {
        adjustedRate = 100.0;
    }
    
    return adjustedRate;
}

double SafetyProtocol::calculateRiskReduction() const {
    double baseReduction = 30.0;
    
    double trainingFactor = requiredTrainingHours * 1.5;
    double mandatoryFactor = isMandatory ? 1.2 : 1.0;
    double projectFactor = 1.0 + (applicableProjects.size() * 0.05);
    double employeeFactor = 1.0 + (trainedEmployees.size() * 0.01);
    
    double totalReduction = baseReduction + trainingFactor;
    totalReduction *= mandatoryFactor * projectFactor * employeeFactor;
    
    return totalReduction > 95.0 ? 95.0 : totalReduction;
}

bool SafetyProtocol::needsRetraining() const {
    int totalTrained = trainedEmployees.size();
    int totalProjects = applicableProjects.size();
    
    bool hasLowCompliance = totalTrained < (totalProjects * 2);
    bool isOutdated = requiredTrainingHours < 10;
    bool hasEquipmentChanges = !relatedEquipment.empty();
    
    return hasLowCompliance || isOutdated || hasEquipmentChanges;
}

void SafetyProtocol::addApplicableProject(ConstructionProject* project) {
    if (project) {
        applicableProjects.push_back(project);
    }
}

void SafetyProtocol::removeApplicableProject(const std::string& projectId) {
    applicableProjects.erase(
        std::remove_if(applicableProjects.begin(), applicableProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        applicableProjects.end()
    );
}

std::vector<ConstructionProject*> SafetyProtocol::getApplicableProjects() const {
    return applicableProjects;
}

void SafetyProtocol::addTrainedEmployee(Employee* employee) {
    if (employee) {
        trainedEmployees.push_back(employee);
    }
}

void SafetyProtocol::removeTrainedEmployee(const std::string& employeeId) {
    trainedEmployees.erase(
        std::remove_if(trainedEmployees.begin(), trainedEmployees.end(),
            [&employeeId](Employee* employee) {
                return employee->getId() == employeeId;
            }),
        trainedEmployees.end()
    );
}

std::vector<Employee*> SafetyProtocol::getTrainedEmployees() const {
    return trainedEmployees;
}

void SafetyProtocol::addRelatedEquipment(Equipment* equipment) {
    if (equipment) {
        relatedEquipment.push_back(equipment);
    }
}

void SafetyProtocol::removeRelatedEquipment(const std::string& equipmentId) {
    relatedEquipment.erase(
        std::remove_if(relatedEquipment.begin(), relatedEquipment.end(),
            [&equipmentId](Equipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        relatedEquipment.end()
    );
}

std::vector<Equipment*> SafetyProtocol::getRelatedEquipment() const {
    return relatedEquipment;
}
