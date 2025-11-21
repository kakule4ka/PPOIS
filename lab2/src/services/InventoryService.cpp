#include "InventoryService.h"
#include "BuildingMaterial.h"
#include <algorithm>

InventoryService::InventoryService(const std::string& id, int items, double rate)
    : serviceId(id), totalItems(items), turnoverRate(rate) {}

double InventoryService::calculateStockOutRisk() const {
    double baseRisk = (1.0 / turnoverRate) * 50.0;
    
    // Используем ассоциацию
    double materialRisk = 0.0;
    for (const auto& material : managedMaterials) {
        if (material->needsReordering()) {
            materialRisk += 5.0;
        }
    }
    
    return baseRisk + materialRisk;
}

bool InventoryService::optimizeInventoryLevels() const {
    double stockOutRisk = calculateStockOutRisk();
    bool hasCriticalMaterials = false;
    
    for (const auto& material : managedMaterials) {
        if (material->getQuantity() < 10.0) {
            hasCriticalMaterials = true;
            break;
        }
    }
    
    bool isRiskAcceptable = stockOutRisk < 30.0;
    return !hasCriticalMaterials && isRiskAcceptable;
}

void InventoryService::addMaterial(BuildingMaterial* material) {
    if (material) {
        managedMaterials.push_back(material);
    }
}

std::vector<BuildingMaterial*> InventoryService::getManagedMaterials() const {
    return managedMaterials;
}
