#include "Window.h"

Window::Window(const std::string& id, const std::string& material, double width, double height)
    : windowId(id), material(material), width(width), height(height) {}

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
