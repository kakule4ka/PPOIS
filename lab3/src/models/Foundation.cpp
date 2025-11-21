#include "models/Foundation.h"
#include "models/Building.h"
#include "core/QualityStandard.h"
#include <algorithm>

Foundation::Foundation(const std::string& id, const std::string& type, double depth, double capacity)
    : foundationId(id), type(type), depth(depth), loadCapacity(capacity),
      building(nullptr) {}

double Foundation::calculateConstructionTime() const {
    double baseTime = depth * 2.0;
    
    double typeMultiplier = 1.0;
    if (type == "Pile") {
        typeMultiplier = 1.8;
    } else if (type == "Raft") {
        typeMultiplier = 1.5;
    } else if (type == "Strip") {
        typeMultiplier = 1.2;
    }
    
    double capacityFactor = 1.0;
    if (loadCapacity > 1000) {
        capacityFactor = 1.3;
    } else if (loadCapacity > 500) {
        capacityFactor = 1.1;
    }
    
    double weatherFactor = 1.1;
    double safetyBuffer = baseTime * 0.15;
    
    return (baseTime * typeMultiplier * capacityFactor * weatherFactor) + safetyBuffer;
}

bool Foundation::validateSoilCompatibility(const std::string& soilType) const {
    bool isSuitable = true;
    
    if (soilType == "Clay" && type == "Pile") {
        isSuitable = depth <= 15.0;
    } else if (soilType == "Sand" && type == "Strip") {
        isSuitable = loadCapacity <= 300.0;
    } else if (soilType == "Rock" && type == "Raft") {
        isSuitable = depth >= 3.0;
    }
    
    bool hasAdequateCapacity = loadCapacity >= 200.0;
    bool meetsDepthRequirements = depth >= 1.5 && depth <= 20.0;
    
    return isSuitable && hasAdequateCapacity && meetsDepthRequirements;
}

double Foundation::calculateStabilityFactor() const {
    double baseStability = 80.0;
    
    double depthFactor = depth * 2.0;
    double capacityFactor = loadCapacity * 0.05;
    double typeFactor = 1.0;
    
    if (type == "Pile") typeFactor = 1.2;
    else if (type == "Raft") typeFactor = 1.1;
    else if (type == "Strip") typeFactor = 1.0;
    
    double buildingFactor = building ? 5.0 : 0.0;
    double standardBonus = 0.0;
    
    for (const auto& standard : complianceStandards) {
        if (standard->validateCompliance(loadCapacity)) {
            standardBonus += 2.0;
        }
    }
    
    double totalStability = baseStability + depthFactor + capacityFactor + 
                           buildingFactor + standardBonus;
    return totalStability * typeFactor;
}

bool Foundation::meetsStructuralRequirements() const {
    double stability = calculateStabilityFactor();
    bool hasGoodStability = stability > 100.0;
    bool hasBuilding = building != nullptr;
    bool hasComplianceStandards = !complianceStandards.empty();
    bool hasValidType = type == "Pile" || type == "Raft" || type == "Strip";
    
    return hasGoodStability && hasBuilding && hasComplianceStandards && hasValidType;
}

void Foundation::setBuilding(Building* building) {
    this->building = building;
}

Building* Foundation::getBuilding() const {
    return building;
}

void Foundation::addComplianceStandard(QualityStandard* standard) {
    if (standard) {
        complianceStandards.push_back(standard);
    }
}

void Foundation::removeComplianceStandard(const std::string& standardId) {
    complianceStandards.erase(
        std::remove_if(complianceStandards.begin(), complianceStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        complianceStandards.end()
    );
}

std::vector<QualityStandard*> Foundation::getComplianceStandards() const {
    return complianceStandards;
}
