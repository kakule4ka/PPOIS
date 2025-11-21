#ifndef RESOURCEALLOCATION_H
#define RESOURCEALLOCATION_H

#include <string>
#include <vector>

class ConstructionProject;
class Employee;
class Equipment;

class ResourceAllocation {
private:
    std::string allocationId;
    std::string resourceId;
    std::string projectId;
    double allocatedAmount;
    ConstructionProject* project;
    Employee* assignedEmployee;
    Equipment* assignedEquipment;
    
public:
    ResourceAllocation(const std::string& id, const std::string& resourceId, const std::string& projectId, double amount);
    
    double calculateUtilizationRate() const;
    bool isOverAllocated() const;
    double calculateAllocationEfficiency() const;
    bool needsAdjustment() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void setAssignedEmployee(Employee* employee);
    Employee* getAssignedEmployee() const;
    
    void setAssignedEquipment(Equipment* equipment);
    Equipment* getAssignedEquipment() const;
    
    std::string getId() const { return allocationId; }
};

#endif
