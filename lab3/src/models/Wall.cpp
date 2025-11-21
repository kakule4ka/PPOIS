#include "models/Wall.h"
#include "models/Building.h"
#include "models/BuildingMaterial.h"
#include <algorithm>

Wall::Wall(const std::string& id, const std::string& material, double height, double length)
    : wallId(id), material(material), height(height), length(length),
      building(nullptr) {}

double Wall::calculateMaterialQuantity() const {
    double area = height * length;
    
    double materialDensity = 1.0;
    if (material == "Concrete") {
        materialDensity = 2.4;
    } else if (material == "Brick") {
        materialDensity = 1.8;
    } else if (material == "Steel") {
        materialDensity = 7.8;
    } else if (material == "Wood") {
        materialDensity = 0.6;
    }
    
    double wasteFactor = 1.1;
    if (height > 3.0) {
        wasteFactor = 1.15;
    }
    
    double openings = area * 0.1;
    double netArea = area - openings;
    
    return netArea * materialDensity * wasteFactor;
}

bool Wall::meetsStructuralRequirements() const {
    double aspectRatio = height / length;
    
    bool hasReasonableRatio = aspectRatio >= 0.2 && aspectRatio <= 3.0;
    bool meetsHeightLimit = height <= 10.0;
    
    double loadCapacity = 0.0;
    if (material == "Concrete") {
        loadCapacity = 5000.0;
    } else if (material == "Brick") {
        loadCapacity = 2000.0;
    } else if (material == "Steel") {
        loadCapacity = 8000.0;
    } else if (material == "Wood") {
        loadCapacity = 1000.0;
    }
    
    double actualLoad = height * length * 100.0;
    bool canSupportLoad = actualLoad <= loadCapacity;
    
    return hasReasonableRatio && meetsHeightLimit && canSupportLoad;
}

double Wall::calculateWallStrength() const {
    double baseStrength = 70.0;
    
    double materialStrength = 0.0;
    if (material == "Concrete") materialStrength = 25.0;
    else if (material == "Steel") materialStrength = 30.0;
    else if (material == "Brick") materialStrength = 20.0;
    else if (material == "Wood") materialStrength = 15.0;
    
    double dimensionFactor = (height * length) / 100.0;
    if (dimensionFactor > 10.0) dimensionFactor = 10.0;
    
    double buildingFactor = building ? 5.0 : 0.0;
    double materialBonus = 0.0;
    
    for (const auto& constructionMaterial : constructionMaterials) {
        if (constructionMaterial->isQuantitySufficient(calculateMaterialQuantity())) {
            materialBonus += 2.0;
        }
    }
    
    double totalStrength = baseStrength + materialStrength + dimensionFactor + 
                          buildingFactor + materialBonus;
    
    return totalStrength > 100.0 ? 100.0 : totalStrength;
}

bool Wall::isLoadBearing() const {
    double strength = calculateWallStrength();
    bool hasGoodStrength = strength > 80.0;
    bool meetsRequirements = meetsStructuralRequirements();
    bool hasBuilding = building != nullptr;
    bool hasConstructionMaterials = !constructionMaterials.empty();
    bool isStructuralMaterial = material == "Concrete" || material == "Steel";
    
    return hasGoodStrength && meetsRequirements && hasBuilding && 
           hasConstructionMaterials && isStructuralMaterial;
}

void Wall::setBuilding(Building* building) {
    this->building = building;
}

Building* Wall::getBuilding() const {
    return building;
}

void Wall::addConstructionMaterial(BuildingMaterial* material) {
    if (material) {
        constructionMaterials.push_back(material);
    }
}

void Wall::removeConstructionMaterial(const std::string& materialId) {
    constructionMaterials.erase(
        std::remove_if(constructionMaterials.begin(), constructionMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        constructionMaterials.end()
    );
}

std::vector<BuildingMaterial*> Wall::getConstructionMaterials() const {
    return constructionMaterials;
}
