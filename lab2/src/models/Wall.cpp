#include "Wall.h"

Wall::Wall(const std::string& id, const std::string& material, double height, double length)
    : wallId(id), material(material), height(height), length(length) {}

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
