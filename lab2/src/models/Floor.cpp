#include "models/Floor.h"
#include "models/Building.h"
#include "models/BuildingMaterial.h"
#include <algorithm>

Floor::Floor(const std::string& id, int level, const std::string& material, double area)
    : floorId(id), level(level), material(material), area(area),
      building(nullptr) {}

double Floor::calculateLoadCapacity() const {
    return area * 100.0;
}

bool Floor::validateFloorPlanCompliance() const {
    return area > 0 && level >= 0;
}

double Floor::calculateFloorStability() const {
    double baseStability = 75.0;
    
    double levelStability = (10 - level) * 2.0;
    if (levelStability < 0) levelStability = 0;
    
    double materialStability = 0.0;
    if (material == "Concrete") materialStability = 20.0;
    else if (material == "Steel") materialStability = 18.0;
    else if (material == "Wood") materialStability = 12.0;
    else if (material == "Composite") materialStability = 15.0;
    
    double areaStability = (area <= 1000.0) ? 5.0 : -5.0;
    double buildingFactor = building ? 5.0 : 0.0;
    
    double materialBonus = 0.0;
    for (const auto& flooringMaterial : flooringMaterials) {
        if (flooringMaterial->isQuantitySufficient(area * 0.05)) {
            materialBonus += 2.0;
        }
    }
    
    double totalStability = baseStability + levelStability + materialStability + 
                           areaStability + buildingFactor + materialBonus;
    
    return totalStability > 100.0 ? 100.0 : totalStability;
}

bool Floor::needsReinforcement() const {
    double stability = calculateFloorStability();
    bool hasLowStability = stability < 70.0;
    bool isHighLevel = level > 5;
    bool hasLargeArea = area > 1500.0;
    bool hasNoMaterials = flooringMaterials.empty();
    bool hasNoBuilding = building == nullptr;
    bool isWeakMaterial = material == "Wood" && level > 3;
    
    return hasLowStability || isHighLevel || hasLargeArea || hasNoMaterials || 
           hasNoBuilding || isWeakMaterial;
}

void Floor::setBuilding(Building* building) {
    this->building = building;
}

Building* Floor::getBuilding() const {
    return building;
}

void Floor::addFlooringMaterial(BuildingMaterial* material) {
    if (material) {
        flooringMaterials.push_back(material);
    }
}

void Floor::removeFlooringMaterial(const std::string& materialId) {
    flooringMaterials.erase(
        std::remove_if(flooringMaterials.begin(), flooringMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        flooringMaterials.end()
    );
}

std::vector<BuildingMaterial*> Floor::getFlooringMaterials() const {
    return flooringMaterials;
}
