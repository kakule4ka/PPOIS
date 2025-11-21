#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <vector>

class Building;
class SafetyProtocol;

class Elevator {
private:
    std::string elevatorId;
    int capacity;
    int floorsServed;
    double speed;
    Building* building;
    std::vector<SafetyProtocol*> safetyProtocols;
    
public:
    Elevator(const std::string& id, int capacity, int floors, double speed);
    
    double calculateRoundTripTime() const;
    bool validateCapacityRequirements(int buildingOccupancy) const;
    double calculateElevatorEfficiency() const;
    bool meetsSafetyStandards() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addSafetyProtocol(SafetyProtocol* protocol);
    void removeSafetyProtocol(const std::string& protocolId);
    std::vector<SafetyProtocol*> getSafetyProtocols() const;
    
    std::string getId() const { return elevatorId; }
};

#endif
