#ifndef BUILDINGMATERIAL_H
#define BUILDINGMATERIAL_H

#include <string>

class BuildingMaterial {
private:
    std::string materialId;
    std::string name;
    double quantity;
    double unitCost;
    
public:
    BuildingMaterial(const std::string& id, const std::string& name, double quantity, double cost);
    
    double calculateTotalCost() const;
    bool isQuantitySufficient(double required) const;
    
    std::string getId() const { return materialId; }
};

#endif
