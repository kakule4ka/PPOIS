#include "Foundation.h"

Foundation::Foundation(const std::string& id, const std::string& type, double depth, double capacity)
    : foundationId(id), type(type), depth(depth), loadCapacity(capacity) {}

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
