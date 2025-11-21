#include "Roof.h"
#include "Building.h"
#include "BuildingMaterial.h"
#include <algorithm>

Roof::Roof(const std::string& id, const std::string& type, double area, double slope)
    : roofId(id), type(type), area(area), slope(slope),
      building(nullptr) {}

double Roof::calculateWaterDrainage() const {
    double baseDrainage = area * 10.0;
    
    if (type == "Flat") {
        return baseDrainage * 0.5;
    } else if (type == "Gable") {
        return baseDrainage * 1.5;
    } else if (type == "Hip") {
        return baseDrainage * 1.2;
    }
    
    return baseDrainage;
}

bool Roof::validateWindResistance(double windSpeed) const {
    double windResistance = 0.0;
    
    if (type == "Flat") {
        windResistance = 120.0;
    } else if (type == "Gable") {
        windResistance = 150.0;
    } else if (type == "Hip") {
        windResistance = 180.0;
    } else {
        windResistance = 100.0;
    }
    
    double slopeFactor = 1.0 + (slope / 100.0);
    windResistance *= slopeFactor;
    
    double areaFactor = 1.0;
    if (area > 200.0) {
        areaFactor = 0.9;
    } else if (area < 50.0) {
        areaFactor = 1.1;
    }
    
    windResistance *= areaFactor;
    
    return windSpeed <= windResistance;
}

double Roof::calculateRoofDurability() const {
    double baseDurability = 80.0;
    
    double typeDurability = 0.0;
    if (type == "Hip") typeDurability = 15.0;
    else if (type == "Gable") typeDurability = 12.0;
    else if (type == "Flat") typeDurability = 8.0;
    
    double slopeDurability = slope * 0.5;
    double areaDurability = (area <= 150.0) ? 5.0 : -5.0;
    double buildingFactor = building ? 5.0 : 0.0;
    
    double materialBonus = 0.0;
    for (const auto& material : roofingMaterials) {
        if (material->isQuantitySufficient(area * 0.1)) {
            materialBonus += 3.0;
        }
    }
    
    double totalDurability = baseDurability + typeDurability + slopeDurability + 
                            areaDurability + buildingFactor + materialBonus;
    
    return totalDurability > 100.0 ? 100.0 : totalDurability;
}

bool Roof::requiresMaintenance() const {
    double durability = calculateRoofDurability();
    bool hasLowDurability = durability < 70.0;
    bool hasNoMaterials = roofingMaterials.empty();
    bool hasNoBuilding = building == nullptr;
    bool isOldType = type == "Flat" && slope < 2.0;
    bool hasLargeArea = area > 300.0;
    
    return hasLowDurability || hasNoMaterials || hasNoBuilding || isOldType || hasLargeArea;
}

void Roof::setBuilding(Building* building) {
    this->building = building;
}

Building* Roof::getBuilding() const {
    return building;
}

void Roof::addRoofingMaterial(BuildingMaterial* material) {
    if (material) {
        roofingMaterials.push_back(material);
    }
}

void Roof::removeRoofingMaterial(const std::string& materialId) {
    roofingMaterials.erase(
        std::remove_if(roofingMaterials.begin(), roofingMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        roofingMaterials.end()
    );
}

std::vector<BuildingMaterial*> Roof::getRoofingMaterials() const {
    return roofingMaterials;
}
