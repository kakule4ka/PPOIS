#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

class ConstructionProject;
class Foundation;
class ElectricalSystem;

class Building {
private:
    std::string id;
    std::string address;
    int floors;
    double area;
    ConstructionProject* project;
    Foundation* foundation;
    ElectricalSystem* electricalSystem;
    
public:
    Building(const std::string& id, const std::string& address, int floors, double area);
    
    double calculateConstructionCost(double costPerSqm) const;
    bool meetsSafetyStandards() const;
    double calculateBuildingEfficiency() const;
    bool isConstructionFeasible() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void setFoundation(Foundation* foundation);
    Foundation* getFoundation() const;
    
    void setElectricalSystem(ElectricalSystem* system);
    ElectricalSystem* getElectricalSystem() const;
    
    std::string getId() const { return id; }
};

#endif
