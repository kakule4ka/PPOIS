#include "BuildingMaterial.h"

BuildingMaterial::BuildingMaterial(const std::string& id, const std::string& name, double quantity, double cost)
    : materialId(id), name(name), quantity(quantity), unitCost(cost) {}

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
