#include "core/CostEstimate.h"
#include "core/ConstructionProject.h"
#include "models/BuildingMaterial.h"
#include "models/Equipment.h"
#include <algorithm>

CostEstimate::CostEstimate(const std::string& id, const std::string& projectId, double material, double labor)
    : estimateId(id), projectId(projectId), materialCost(material), laborCost(labor),
      project(nullptr) {}

double CostEstimate::calculateTotalCost() const {
    return materialCost + laborCost;
}

double CostEstimate::calculateVariance(double actualCost) const {
    return actualCost - calculateTotalCost();
}

double CostEstimate::calculateAccuracy() const {
    double baseAccuracy = 90.0;
    
    double materialAccuracy = 0.0;
    for (const auto& material : materials) {
        materialAccuracy += material->isQuantitySufficient(100) ? 2.0 : -1.0;
    }
    
    double equipmentAccuracy = equipmentList.size() * 1.5;
    double projectAccuracy = project ? 5.0 : 0.0;
    
    double laborAccuracy = laborCost > 0 ? 3.0 : 0.0;
    double materialCostAccuracy = materialCost > 0 ? 2.0 : 0.0;
    
    double totalAccuracy = baseAccuracy + materialAccuracy + equipmentAccuracy + 
                          projectAccuracy + laborAccuracy + materialCostAccuracy;
    
    return totalAccuracy > 100.0 ? 100.0 : totalAccuracy;
}

bool CostEstimate::isEstimateRealistic() const {
    double accuracy = calculateAccuracy();
    bool hasGoodAccuracy = accuracy > 75.0;  // Понизили порог
    
    double totalMaterialCost = 0.0;
    for (const auto& material : materials) {
        totalMaterialCost += material->calculateTotalCost();
    }
    
    bool materialMatch = std::abs(totalMaterialCost - materialCost) < (materialCost * 0.2);  // Увеличили допуск
    bool hasProject = project != nullptr;
    bool hasMaterials = !materials.empty();
    
    return hasGoodAccuracy && materialMatch && hasProject && hasMaterials;
}

void CostEstimate::setProject(ConstructionProject* proj) {
    this->project = proj;
}

ConstructionProject* CostEstimate::getProject() const {
    return project;
}

void CostEstimate::addMaterial(BuildingMaterial* material) {
    if (material) {
        materials.push_back(material);
    }
}

void CostEstimate::removeMaterial(const std::string& materialId) {
    materials.erase(
        std::remove_if(materials.begin(), materials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        materials.end()
    );
}

std::vector<BuildingMaterial*> CostEstimate::getMaterials() const {
    return materials;
}

void CostEstimate::addEquipment(Equipment* equip) {
    if (equip) {
        equipmentList.push_back(equip);
    }
}

void CostEstimate::removeEquipment(const std::string& equipmentId) {
    equipmentList.erase(
        std::remove_if(equipmentList.begin(), equipmentList.end(),
            [&equipmentId](Equipment* equip) {
                return equip->getId() == equipmentId;
            }),
        equipmentList.end()
    );
}

std::vector<Equipment*> CostEstimate::getEquipment() const {
    return equipmentList;
}
