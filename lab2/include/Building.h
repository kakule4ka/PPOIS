#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
private:
    std::string id;
    std::string address;
    int floors;
    double area;
    
public:
    Building(const std::string& id, const std::string& address, int floors, double area);
    
    double calculateConstructionCost(double costPerSqm) const;
    bool meetsSafetyStandards() const;
    
    std::string getId() const { return id; }
};

#endif
