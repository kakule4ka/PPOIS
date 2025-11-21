#include "Door.h"
#include "Building.h"
#include "SafetyProtocol.h"
#include <algorithm>

Door::Door(const std::string& id, const std::string& type, const std::string& material, double width)
    : doorId(id), type(type), material(material), width(width),
      building(nullptr) {}

double Door::calculateSecurityLevel() const {
    double baseSecurity = 50.0;
    
    double typeMultiplier = 1.0;
    if (type == "Security") {
        typeMultiplier = 2.0;
    } else if (type == "Fire") {
        typeMultiplier = 1.8;
    } else if (type == "Standard") {
        typeMultiplier = 1.0;
    } else if (type == "Glass") {
        typeMultiplier = 0.6;
    }
    
    double materialMultiplier = 1.0;
    if (material == "Steel") {
        materialMultiplier = 2.0;
    } else if (material == "SolidWood") {
        materialMultiplier = 1.5;
    } else if (material == "Hollow") {
        materialMultiplier = 0.7;
    } else if (material == "Aluminum") {
        materialMultiplier = 1.2;
    }
    
    double widthFactor = 1.0;
    if (width > 1.0) {
        widthFactor = 0.9;
    } else if (width < 0.8) {
        widthFactor = 1.1;
    }
    
    double lockingFactor = 1.2;
    double frameFactor = 1.1;
    
    return baseSecurity * typeMultiplier * materialMultiplier * widthFactor * lockingFactor * frameFactor;
}

bool Door::validateAccessibility() const {
    double minWidth = 0.8;
    double maxWidth = 1.2;
    
    bool hasProperWidth = width >= minWidth && width <= maxWidth;
    
    bool isAccessibleType = type != "Security" || width >= 0.9;
    
    bool hasLowThreshold = true;
    
    double handleHeight = 1.0;
    bool hasProperHandleHeight = handleHeight >= 0.9 && handleHeight <= 1.1;
    
    double openingForce = 50.0;
    if (type == "Fire") {
        openingForce = 30.0;
    }
    bool hasReasonableOpeningForce = openingForce <= 60.0;
    
    return hasProperWidth && isAccessibleType && hasLowThreshold && hasProperHandleHeight && hasReasonableOpeningForce;
}

double Door::calculateDoorPerformance() const {
    double basePerformance = 75.0;
    
    double securityPerformance = calculateSecurityLevel() * 0.3;
    double accessibilityPerformance = validateAccessibility() ? 15.0 : 0.0;
    double buildingFactor = building ? 5.0 : 0.0;
    
    double safetyBonus = 0.0;
    for (const auto& feature : safetyFeatures) {
        double riskReduction = feature->calculateRiskReduction();
        safetyBonus += riskReduction * 0.2;
    }
    
    double typeBonus = 0.0;
    if (type == "Fire") typeBonus = 8.0;
    else if (type == "Security") typeBonus = 6.0;
    
    double totalPerformance = basePerformance + securityPerformance + accessibilityPerformance + 
                             buildingFactor + safetyBonus + typeBonus;
    
    return totalPerformance > 100.0 ? 100.0 : totalPerformance;
}

bool Door::meetsBuildingCode() const {
    double performance = calculateDoorPerformance();
    bool hasGoodPerformance = performance > 80.0;
    bool isAccessible = validateAccessibility();
    bool hasBuilding = building != nullptr;
    bool hasSafetyFeatures = !safetyFeatures.empty();
    bool hasProperWidth = width >= 0.8 && width <= 1.2;
    
    return hasGoodPerformance && isAccessible && hasBuilding && 
           hasSafetyFeatures && hasProperWidth;
}

void Door::setBuilding(Building* building) {
    this->building = building;
}

Building* Door::getBuilding() const {
    return building;
}

void Door::addSafetyFeature(SafetyProtocol* protocol) {
    if (protocol) {
        safetyFeatures.push_back(protocol);
    }
}

void Door::removeSafetyFeature(const std::string& protocolId) {
    safetyFeatures.erase(
        std::remove_if(safetyFeatures.begin(), safetyFeatures.end(),
            [&protocolId](SafetyProtocol* protocol) {
                return protocol->getId() == protocolId;
            }),
        safetyFeatures.end()
    );
}

std::vector<SafetyProtocol*> Door::getSafetyFeatures() const {
    return safetyFeatures;
}
