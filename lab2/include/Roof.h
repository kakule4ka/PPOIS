#ifndef ROOF_H
#define ROOF_H

#include <string>

class Roof {
private:
    std::string roofId;
    std::string type;
    double area;
    double slope;
    
public:
    Roof(const std::string& id, const std::string& type, double area, double slope);
    
    double calculateWaterDrainage() const;
    bool validateWindResistance(double windSpeed) const;
    
    std::string getId() const { return roofId; }
};

#endif
