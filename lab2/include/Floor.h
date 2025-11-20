#ifndef FLOOR_H
#define FLOOR_H

#include <string>

class Floor {
private:
    std::string floorId;
    int level;
    std::string material;
    double area;
    
public:
    Floor(const std::string& id, int level, const std::string& material, double area);
    
    double calculateLoadCapacity() const;
    bool validateFloorPlanCompliance() const;
    
    std::string getId() const { return floorId; }
};

#endif
