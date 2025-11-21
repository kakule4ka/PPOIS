#include "core/ResourceAllocation.h"
#include "core/ConstructionProject.h"
#include "models/Employee.h"
#include "models/Equipment.h"

ResourceAllocation::ResourceAllocation(const std::string& id, const std::string& resourceId, const std::string& projectId, double amount)
    : allocationId(id), resourceId(resourceId), projectId(projectId), allocatedAmount(amount),
      project(nullptr), assignedEmployee(nullptr), assignedEquipment(nullptr) {}

double ResourceAllocation::calculateUtilizationRate() const {
    return allocatedAmount;
}

bool ResourceAllocation::isOverAllocated() const {
    return allocatedAmount > 100000;
}

double ResourceAllocation::calculateAllocationEfficiency() const {
    double baseEfficiency = 70.0;
    
    double amountEfficiency = 0.0;
    if (allocatedAmount <= 50000) amountEfficiency = 20.0;
    else if (allocatedAmount <= 100000) amountEfficiency = 10.0;
    else amountEfficiency = -10.0;
    
    double projectEfficiency = project ? 5.0 : 0.0;
    double employeeEfficiency = assignedEmployee ? assignedEmployee->calculateProductivity() * 2.0 : 0.0;
    double equipmentEfficiency = assignedEquipment ? 3.0 : 0.0;
    
    double totalEfficiency = baseEfficiency + amountEfficiency + projectEfficiency + 
                           employeeEfficiency + equipmentEfficiency;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool ResourceAllocation::needsAdjustment() const {
    double efficiency = calculateAllocationEfficiency();
    bool isInefficient = efficiency < 60.0;
    bool isOverallocated = isOverAllocated();
    bool hasNoEmployee = assignedEmployee == nullptr;
    bool hasNoEquipment = assignedEquipment == nullptr;
    bool hasNoProject = project == nullptr;
    
    return isInefficient || isOverallocated || hasNoEmployee || hasNoEquipment || hasNoProject;
}

void ResourceAllocation::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* ResourceAllocation::getProject() const {
    return project;
}

void ResourceAllocation::setAssignedEmployee(Employee* employee) {
    this->assignedEmployee = employee;
}

Employee* ResourceAllocation::getAssignedEmployee() const {
    return assignedEmployee;
}

void ResourceAllocation::setAssignedEquipment(Equipment* equipment) {
    this->assignedEquipment = equipment;
}

Equipment* ResourceAllocation::getAssignedEquipment() const {
    return assignedEquipment;
}
