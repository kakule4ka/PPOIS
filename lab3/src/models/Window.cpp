#include "models/Window.h"
#include "models/Building.h"
#include "core/QualityStandard.h"
#include <algorithm>

Window::Window(const std::string& id, const std::string& material, double width, double height)
    : windowId(id), material(material), width(width), height(height),
      building(nullptr) {}

double Window::calculateHeatLoss() const {
    double area = width * height;
    double baseHeatLoss = area * 5.0;
    
    double materialFactor = 1.0;
    if (material == "DoubleGlazed") {
        materialFactor = 0.6;
    } else if (material == "TripleGlazed") {
        materialFactor = 0.4;
    } else if (material == "SingleGlazed") {
        materialFactor = 1.2;
    } else if (material == "LowE") {
        materialFactor = 0.5;
    }
    
    double sizeFactor = 1.0;
    if (area > 4.0) {
        sizeFactor = 1.1;
    } else if (area < 1.0) {
        sizeFactor = 0.9;
    }
    
    double orientationFactor = 1.1;
    double seasonalFactor = 1.3;
    
    return baseHeatLoss * materialFactor * sizeFactor * orientationFactor * seasonalFactor;
}

bool Window::meetsVentilationRequirements() const {
    double area = width * height;
    return area >= 0.5 && material != "Fixed";
}

double Window::calculateWindowEfficiency() const {
    double baseEfficiency = 70.0;
    
    double materialEfficiency = 0.0;
    if (material == "TripleGlazed") materialEfficiency = 25.0;
    else if (material == "DoubleGlazed") materialEfficiency = 20.0;
    else if (material == "LowE") materialEfficiency = 18.0;
    else if (material == "SingleGlazed") materialEfficiency = 10.0;
    
    double sizeEfficiency = (width * height <= 3.0) ? 5.0 : -3.0;
    double ventilationEfficiency = meetsVentilationRequirements() ? 8.0 : 0.0;
    double buildingFactor = building ? 4.0 : 0.0;
    
    double standardBonus = 0.0;
    for (const auto& standard : energyStandards) {
        if (standard->validateCompliance(calculateHeatLoss())) {
            standardBonus += 3.0;
        }
    }
    
    double totalEfficiency = baseEfficiency + materialEfficiency + sizeEfficiency + 
                            ventilationEfficiency + buildingFactor + standardBonus;
    
    return totalEfficiency > 100.0 ? 100.0 : totalEfficiency;
}

bool Window::isEnergyEfficient() const {
    double efficiency = calculateWindowEfficiency();
    bool hasGoodEfficiency = efficiency > 80.0;
    bool hasLowHeatLoss = calculateHeatLoss() < 50.0;
    bool hasBuilding = building != nullptr;
    bool hasEnergyStandards = !energyStandards.empty();
    bool hasProperMaterial = material == "DoubleGlazed" || material == "TripleGlazed" || material == "LowE";
    
    return hasGoodEfficiency && hasLowHeatLoss && hasBuilding && 
           hasEnergyStandards && hasProperMaterial;
}

void Window::setBuilding(Building* building) {
    this->building = building;
}

Building* Window::getBuilding() const {
    return building;
}

void Window::addEnergyStandard(QualityStandard* standard) {
    if (standard) {
        energyStandards.push_back(standard);
    }
}

void Window::removeEnergyStandard(const std::string& standardId) {
    energyStandards.erase(
        std::remove_if(energyStandards.begin(), energyStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        energyStandards.end()
    );
}

std::vector<QualityStandard*> Window::getEnergyStandards() const {
    return energyStandards;
}
