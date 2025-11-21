#ifndef ROOF_H
#define ROOF_H

#include <string>
#include <vector>

class Building;
class BuildingMaterial;

class Roof {
private:
    std::string roofId;
    std::string type;
    double area;
    double slope;
    Building* building;
    std::vector<BuildingMaterial*> roofingMaterials;
    
public:
    Roof(const std::string& id, const std::string& type, double area, double slope);
    
    double calculateWaterDrainage() const;
    bool validateWindResistance(double windSpeed) const;
    double calculateRoofDurability() const;
    bool requiresMaintenance() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addRoofingMaterial(BuildingMaterial* material);
    void removeRoofingMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getRoofingMaterials() const;
    
    std::string getId() const { return roofId; }
};

#endif
