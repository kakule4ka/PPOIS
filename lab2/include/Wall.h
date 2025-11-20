#ifndef WALL_H
#define WALL_H

#include <string>

class Wall {
private:
    std::string wallId;
    std::string material;
    double height;
    double length;
    
public:
    Wall(const std::string& id, const std::string& material, double height, double length);
    
    double calculateMaterialQuantity() const;
    bool meetsStructuralRequirements() const;
    
    std::string getId() const { return wallId; }
};

#endif
