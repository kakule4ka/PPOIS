#ifndef ELECTRICALSYSTEM_H
#define ELECTRICALSYSTEM_H

#include <string>

class ElectricalSystem {
private:
    std::string systemId;
    double voltage;
    double powerCapacity;
    int circuits;
    
public:
    ElectricalSystem(const std::string& id, double voltage, double capacity, int circuits);
    
    double calculatePowerConsumption(double usageHours) const;
    bool validateCircuitLoad() const;
    
    std::string getId() const { return systemId; }
};

#endif
