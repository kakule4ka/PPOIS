#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>

class Building;
class QualityStandard;

class Window {
private:
    std::string windowId;
    std::string material;
    double width;
    double height;
    Building* building;
    std::vector<QualityStandard*> energyStandards;
    
public:
    Window(const std::string& id, const std::string& material, double width, double height);
    
    double calculateHeatLoss() const;
    bool meetsVentilationRequirements() const;
    double calculateWindowEfficiency() const;
    bool isEnergyEfficient() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addEnergyStandard(QualityStandard* standard);
    void removeEnergyStandard(const std::string& standardId);
    std::vector<QualityStandard*> getEnergyStandards() const;
    
    std::string getId() const { return windowId; }
};

#endif
