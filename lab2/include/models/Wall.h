#ifndef WALL_H
#define WALL_H

#include <string>
#include <vector>

class Building;
class BuildingMaterial;

class Wall {
private:
    std::string wallId;
    std::string material;
    double height;
    double length;
    Building* building;
    std::vector<BuildingMaterial*> constructionMaterials;
    
public:
    Wall(const std::string& id, const std::string& material, double height, double length);
    
    double calculateMaterialQuantity() const;
    bool meetsStructuralRequirements() const;
    double calculateWallStrength() const;
    bool isLoadBearing() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addConstructionMaterial(BuildingMaterial* material);
    void removeConstructionMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getConstructionMaterials() const;
    
    std::string getId() const { return wallId; }
};

#endif
