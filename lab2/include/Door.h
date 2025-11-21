#ifndef DOOR_H
#define DOOR_H

#include <string>
#include <vector>

class Building;
class SafetyProtocol;

class Door {
private:
    std::string doorId;
    std::string type;
    std::string material;
    double width;
    Building* building;
    std::vector<SafetyProtocol*> safetyFeatures;
    
public:
    Door(const std::string& id, const std::string& type, const std::string& material, double width);
    
    double calculateSecurityLevel() const;
    bool validateAccessibility() const;
    double calculateDoorPerformance() const;
    bool meetsBuildingCode() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addSafetyFeature(SafetyProtocol* protocol);
    void removeSafetyFeature(const std::string& protocolId);
    std::vector<SafetyProtocol*> getSafetyFeatures() const;
    
    std::string getId() const { return doorId; }
};

#endif
