#ifndef SAFETYPROTOCOL_H
#define SAFETYPROTOCOL_H

#include <string>
#include <vector>

class ConstructionProject;
class Employee;
class Equipment;

class SafetyProtocol {
private:
    std::string protocolId;
    std::string name;
    int requiredTrainingHours;
    bool isMandatory;
    std::vector<ConstructionProject*> applicableProjects;
    std::vector<Employee*> trainedEmployees;
    std::vector<Equipment*> relatedEquipment;
    
public:
    SafetyProtocol(const std::string& id, const std::string& name, int trainingHours, bool mandatory);
    
    bool validateWorkerCompliance(int trainingHours) const;
    double calculateComplianceRate(int compliantWorkers, int totalWorkers) const;
    double calculateRiskReduction() const;
    bool needsRetraining() const;
    
    void addApplicableProject(ConstructionProject* project);
    void removeApplicableProject(const std::string& projectId);
    std::vector<ConstructionProject*> getApplicableProjects() const;
    
    void addTrainedEmployee(Employee* employee);
    void removeTrainedEmployee(const std::string& employeeId);
    std::vector<Employee*> getTrainedEmployees() const;
    
    void addRelatedEquipment(Equipment* equipment);
    void removeRelatedEquipment(const std::string& equipmentId);
    std::vector<Equipment*> getRelatedEquipment() const;
    
    std::string getId() const { return protocolId; }
};

#endif
