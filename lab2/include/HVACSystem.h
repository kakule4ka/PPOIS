#ifndef HVACSYSTEM_H
#define HVACSYSTEM_H

#include <string>

class HVACSystem {
private:
    std::string systemId;
    double coolingCapacity;
    double heatingCapacity;
    double efficiency;
    
public:
    HVACSystem(const std::string& id, double cooling, double heating, double efficiency);
    
    double calculateEnergyConsumption() const;
    bool validateRoomComfort(double roomSize) const;
    
    std::string getId() const { return systemId; }
};

#endif
