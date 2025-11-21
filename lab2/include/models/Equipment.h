#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>

class ConstructionProject;
class Employee;

class Equipment {
private:
    std::string equipmentId;
    std::string type;
    double maintenanceCost;
    int hoursUsed;
    ConstructionProject* currentProject;
    Employee* assignedOperator;
    
public:
    Equipment(const std::string& id, const std::string& type, double maintenanceCost);
    
    double calculateDepreciation() const;
    bool needsMaintenance() const;
    double calculateUtilizationRate() const;
    bool isAvailableForProject() const;
    
    void setCurrentProject(ConstructionProject* project);
    ConstructionProject* getCurrentProject() const;
    
    void assignOperator(Employee* emp);
    Employee* getAssignedOperator() const;
    
    void setHoursUsed(int hours);
    std::string getId() const { return equipmentId; }
};

#endif
