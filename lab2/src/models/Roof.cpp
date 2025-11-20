#include "Roof.h"

Roof::Roof(const std::string& id, const std::string& type, double area, double slope)
    : roofId(id), type(type), area(area), slope(slope) {}

double Roof::calculateWaterDrainage() const {
    double baseDrainage = area * 10.0;
    
    if (type == "Flat") {
        return baseDrainage * 0.5;
    } else if (type == "Gable") {
        return baseDrainage * 1.5;
    } else if (type == "Hip") {
        return baseDrainage * 1.2;
    }
    
    return baseDrainage;
}

bool Roof::validateWindResistance(double windSpeed) const {
    double windResistance = 0.0;
    
    if (type == "Flat") {
        windResistance = 120.0;
    } else if (type == "Gable") {
        windResistance = 150.0;
    } else if (type == "Hip") {
        windResistance = 180.0;
    } else {
        windResistance = 100.0;
    }
    
    double slopeFactor = 1.0 + (slope / 100.0);
    windResistance *= slopeFactor;
    
    double areaFactor = 1.0;
    if (area > 200.0) {
        areaFactor = 0.9;
    } else if (area < 50.0) {
        areaFactor = 1.1;
    }
    
    windResistance *= areaFactor;
    
    return windSpeed <= windResistance;
}
