#include "PlumbingSystem.h"
#include "Building.h"
#include "QualityStandard.h"
#include <algorithm>

PlumbingSystem::PlumbingSystem(const std::string& id, const std::string& material, double pressure, int fixtures)
    : systemId(id), pipeMaterial(material), waterPressure(pressure), fixtures(fixtures),
      building(nullptr) {}

double PlumbingSystem::calculateWaterFlow() const {
    double baseFlow = waterPressure * 2.5;
    
    double materialFactor = 1.0;
    if (pipeMaterial == "Copper") {
        materialFactor = 1.2;
    } else if (pipeMaterial == "PVC") {
        materialFactor = 1.1;
    } else if (pipeMaterial == "Galvanized") {
        materialFactor = 0.9;
    } else if (pipeMaterial == "PEX") {
        materialFactor = 1.15;
    }
    
    double fixtureFactor = 1.0;
    if (fixtures > 10) {
        fixtureFactor = 0.85;
    } else if (fixtures > 5) {
        fixtureFactor = 0.9;
    } else if (fixtures < 3) {
        fixtureFactor = 1.1;
    }
    
    double efficiencyLoss = (fixtures * 0.02) * baseFlow;
    double netFlow = (baseFlow * materialFactor * fixtureFactor) - efficiencyLoss;
    
    return netFlow > 0 ? netFlow : 0;
}

bool PlumbingSystem::validatePressureRequirements() const {
    return waterPressure >= 2.0 && waterPressure <= 8.0;
}

double PlumbingSystem::calculateSystemReliability() const {
    double baseReliability = 80.0;
    
    double pressureReliability = (waterPressure >= 3.0 && waterPressure <= 6.0) ? 10.0 : -5.0;
    double materialReliability = 0.0;
    if (pipeMaterial == "Copper") materialReliability = 8.0;
    else if (pipeMaterial == "PEX") materialReliability = 7.0;
    else if (pipeMaterial == "PVC") materialReliability = 6.0;
    else materialReliability = 3.0;
    
    double fixtureReliability = (fixtures >= 5 && fixtures <= 20) ? 5.0 : -3.0;
    double buildingFactor = building ? 4.0 : 0.0;
    
    double standardBonus = 0.0;
    for (const auto& standard : complianceStandards) {
        if (standard->validateCompliance(waterPressure)) {
            standardBonus += 1.5;
        }
    }
    
    double totalReliability = baseReliability + pressureReliability + materialReliability + 
                             fixtureReliability + buildingFactor + standardBonus;
    
    return totalReliability > 100.0 ? 100.0 : totalReliability;
}

bool PlumbingSystem::meetsPlumbingCode() const {
    double reliability = calculateSystemReliability();
    bool hasGoodReliability = reliability > 85.0;
    bool hasValidPressure = validatePressureRequirements();
    bool hasBuilding = building != nullptr;
    bool hasComplianceStandards = !complianceStandards.empty();
    bool hasProperMaterial = pipeMaterial == "Copper" || pipeMaterial == "PEX" || pipeMaterial == "PVC";
    
    return hasGoodReliability && hasValidPressure && hasBuilding && 
           hasComplianceStandards && hasProperMaterial;
}

void PlumbingSystem::setBuilding(Building* building) {
    this->building = building;
}

Building* PlumbingSystem::getBuilding() const {
    return building;
}

void PlumbingSystem::addComplianceStandard(QualityStandard* standard) {
    if (standard) {
        complianceStandards.push_back(standard);
    }
}

void PlumbingSystem::removeComplianceStandard(const std::string& standardId) {
    complianceStandards.erase(
        std::remove_if(complianceStandards.begin(), complianceStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        complianceStandards.end()
    );
}

std::vector<QualityStandard*> PlumbingSystem::getComplianceStandards() const {
    return complianceStandards;
}
