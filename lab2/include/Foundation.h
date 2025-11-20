#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <string>

class Foundation {
private:
    std::string foundationId;
    std::string type;
    double depth;
    double loadCapacity;
    
public:
    Foundation(const std::string& id, const std::string& type, double depth, double capacity);
    
    double calculateConstructionTime() const;
    bool validateSoilCompatibility(const std::string& soilType) const;
    
    std::string getId() const { return foundationId; }
};

#endif
