#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Employee;
class BuildingMaterial;
class Equipment;

class Task {
private:
    std::string taskId;
    std::string description;
    int estimatedHours;
    int actualHours;
    Employee* assignedEmployee;
    std::vector<BuildingMaterial*> requiredMaterials;
    std::vector<Equipment*> requiredEquipment;
    
public:
    Task(const std::string& id, const std::string& description, int estimatedHours);
    
    double calculateEfficiency() const;
    bool isOverdue() const;
    double calculateResourceCost() const;
    bool isResourceSufficient() const;
    
    void assignEmployee(Employee* employee);
    Employee* getAssignedEmployee() const;
    
    void addRequiredMaterial(BuildingMaterial* material);
    void removeRequiredMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getRequiredMaterials() const;
    
    void addRequiredEquipment(Equipment* equipment);
    void removeRequiredEquipment(const std::string& equipmentId);
    std::vector<Equipment*> getRequiredEquipment() const;
    
    std::string getId() const { return taskId; }
    std::string getDescription() const { return description; }  // Добавлен getter
    void setActualHours(int hours) { actualHours = hours; }
    int getEstimatedHours() const { return estimatedHours; }
    int getActualHours() const { return actualHours; }
};

#endif
