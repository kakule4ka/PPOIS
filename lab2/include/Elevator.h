#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>

class Elevator {
private:
    std::string elevatorId;
    int capacity;
    int floorsServed;
    double speed;
    
public:
    Elevator(const std::string& id, int capacity, int floors, double speed);
    
    double calculateRoundTripTime() const;
    bool validateCapacityRequirements(int buildingOccupancy) const;
    
    std::string getId() const { return elevatorId; }
};

#endif
