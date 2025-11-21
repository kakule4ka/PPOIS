#include "Task.h"
#include "Employee.h"
#include "BuildingMaterial.h"
#include "Equipment.h"
#include <algorithm>

Task::Task(const std::string& id, const std::string& description, int estimatedHours)
    : taskId(id), description(description), estimatedHours(estimatedHours), actualHours(0),
      assignedEmployee(nullptr) {}

double Task::calculateEfficiency() const {
    if (estimatedHours <= 0 || actualHours <= 0) {
        return 0.0;
    }
    
    double baseEfficiency = static_cast<double>(estimatedHours) / actualHours;
    
    double complexityFactor = 1.0;
    if (description.find("complex") != std::string::npos || description.find("critical") != std::string::npos) {
        complexityFactor = 0.8;
    }
    
    double employeeFactor = assignedEmployee ? assignedEmployee->calculateProductivity() : 0.5;
    double resourceFactor = isResourceSufficient() ? 1.1 : 0.7;
    
    double adjustedEfficiency = baseEfficiency * complexityFactor * employeeFactor * resourceFactor;
    
    if (adjustedEfficiency > 2.0) {
        adjustedEfficiency = 2.0;
    }
    
    return adjustedEfficiency;
}

bool Task::isOverdue() const {
    int timeDeviation = actualHours - estimatedHours;
    
    bool isOverTime = timeDeviation > 0;
    bool hasSignificantDelay = timeDeviation > estimatedHours * 0.2;
    bool isCriticalTask = description.find("critical") != std::string::npos;
    
    if (isCriticalTask) {
        return timeDeviation > 0;
    }
    
    return isOverTime && hasSignificantDelay;
}

double Task::calculateResourceCost() const {
    double materialCost = 0.0;
    for (const auto& material : requiredMaterials) {
        materialCost += material->calculateTotalCost();
    }
    
    double equipmentCost = 0.0;
    for (const auto& equipment : requiredEquipment) {
        equipmentCost += equipment->calculateDepreciation();
    }
    
    double laborCost = actualHours * 50.0;
    double overhead = (materialCost + equipmentCost) * 0.1;
    
    return materialCost + equipmentCost + laborCost + overhead;
}

bool Task::isResourceSufficient() const {
    if (requiredMaterials.empty()) return false;
    
    double totalMaterialQuantity = 0.0;
    for (const auto& material : requiredMaterials) {
        totalMaterialQuantity += material->getQuantity();
    }
    
    double estimatedMaterialNeed = estimatedHours * 0.5;
    bool hasEnoughMaterials = totalMaterialQuantity >= estimatedMaterialNeed;
    bool hasEquipment = !requiredEquipment.empty();
    bool hasAssignedWorker = assignedEmployee != nullptr;
    
    return hasEnoughMaterials && hasEquipment && hasAssignedWorker;
}

void Task::assignEmployee(Employee* employee) {
    this->assignedEmployee = employee;
}

Employee* Task::getAssignedEmployee() const {
    return assignedEmployee;
}

void Task::addRequiredMaterial(BuildingMaterial* material) {
    if (material) {
        requiredMaterials.push_back(material);
    }
}

void Task::removeRequiredMaterial(const std::string& materialId) {
    requiredMaterials.erase(
        std::remove_if(requiredMaterials.begin(), requiredMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        requiredMaterials.end()
    );
}

std::vector<BuildingMaterial*> Task::getRequiredMaterials() const {
    return requiredMaterials;
}

void Task::addRequiredEquipment(Equipment* equipment) {
    if (equipment) {
        requiredEquipment.push_back(equipment);
    }
}

void Task::removeRequiredEquipment(const std::string& equipmentId) {
    requiredEquipment.erase(
        std::remove_if(requiredEquipment.begin(), requiredEquipment.end(),
            [&equipmentId](Equipment* equipment) {
                return equipment->getId() == equipmentId;
            }),
        requiredEquipment.end()
    );
}

std::vector<Equipment*> Task::getRequiredEquipment() const {
    return requiredEquipment;
}
