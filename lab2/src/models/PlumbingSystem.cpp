#include "PlumbingSystem.h"

PlumbingSystem::PlumbingSystem(const std::string& id, const std::string& material, double pressure, int fixtures)
    : systemId(id), pipeMaterial(material), waterPressure(pressure), fixtures(fixtures) {}

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
