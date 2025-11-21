#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>

class Building;
class BuildingMaterial;

class Floor {
private:
    std::string floorId;
    int level;
    std::string material;
    double area;
    Building* building;
    std::vector<BuildingMaterial*> flooringMaterials;
    
public:
    Floor(const std::string& id, int level, const std::string& material, double area);
    
    double calculateLoadCapacity() const;
    bool validateFloorPlanCompliance() const;
    double calculateFloorStability() const;
    bool needsReinforcement() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addFlooringMaterial(BuildingMaterial* material);
    void removeFlooringMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getFlooringMaterials() const;
    
    std::string getId() const { return floorId; }
};

#endif
