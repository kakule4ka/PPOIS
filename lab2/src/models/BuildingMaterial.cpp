#include "models/BuildingMaterial.h"
#include <algorithm>
#include "core/ConstructionProject.h"
#include <algorithm>
#include "models/Supplier.h"
#include <algorithm>

BuildingMaterial::BuildingMaterial(const std::string& id, const std::string& name, double quantity, double cost)
    : materialId(id), name(name), quantity(quantity), unitCost(cost),
      usedInProject(nullptr), supplier(nullptr) {}

double BuildingMaterial::calculateTotalCost() const {
    double baseCost = quantity * unitCost;
    double bulkDiscount = 0.0;
    
    if (quantity > 1000) {
        bulkDiscount = 0.15;
    } else if (quantity > 500) {
        bulkDiscount = 0.1;
    } else if (quantity > 100) {
        bulkDiscount = 0.05;
    }
    
    double transportationCost = 0.0;
    if (name == "Concrete" || name == "Steel") {
        transportationCost = baseCost * 0.1;
    }
    
    return baseCost * (1.0 - bulkDiscount) + transportationCost;
}

bool BuildingMaterial::isQuantitySufficient(double required) const {
    double safetyMargin = 0.0;
    
    if (name == "Concrete") {
        safetyMargin = 0.2;
    } else if (name == "Rebar") {
        safetyMargin = 0.15;
    } else {
        safetyMargin = 0.1;
    }
    
    double adjustedRequired = required * (1.0 + safetyMargin);
    bool hasEnoughMaterial = quantity >= adjustedRequired;
    bool hasMinimumStock = quantity >= 50.0;
    
    return hasEnoughMaterial && hasMinimumStock;
}

double BuildingMaterial::calculateWasteEstimate() const {
    double baseWasteRate = 0.0;
    
    if (name == "Concrete") {
        baseWasteRate = 0.05;
    } else if (name == "Wood") {
        baseWasteRate = 0.08;
    } else if (name == "Steel") {
        baseWasteRate = 0.03;
    } else if (name == "Bricks") {
        baseWasteRate = 0.04;
    } else {
        baseWasteRate = 0.06;
    }
    
    double projectComplexityFactor = usedInProject ? 1.1 : 1.0;
    double supplierQualityFactor = supplier ? (supplier->getReliability() > 0.8 ? 0.9 : 1.1) : 1.0;
    
    return quantity * baseWasteRate * projectComplexityFactor * supplierQualityFactor;
}

bool BuildingMaterial::needsReordering() const {
    double minimumStockLevel = 0.0;
    
    if (name == "Concrete") {
        minimumStockLevel = 100.0;
    } else if (name == "Steel") {
        minimumStockLevel = 50.0;
    } else if (name == "Wood") {
        minimumStockLevel = 80.0;
    } else {
        minimumStockLevel = 30.0;
    }
    
    bool isLowStock = quantity < minimumStockLevel;
    bool isCriticalMaterial = name == "Concrete" || name == "Steel";
    bool hasActiveProject = usedInProject != nullptr;
    
    return isLowStock && (isCriticalMaterial || hasActiveProject);
}

void BuildingMaterial::setUsedInProject(ConstructionProject* project) {
    this->usedInProject = project;
}

ConstructionProject* BuildingMaterial::getUsedInProject() const {
    return usedInProject;
}

void BuildingMaterial::setSupplier(Supplier* supplier) {
    this->supplier = supplier;
}

Supplier* BuildingMaterial::getSupplier() const {
    return supplier;
}
