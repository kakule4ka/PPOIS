#ifndef PLUMBINGSYSTEM_H
#define PLUMBINGSYSTEM_H

#include <string>

class PlumbingSystem {
private:
    std::string systemId;
    std::string pipeMaterial;
    double waterPressure;
    int fixtures;
    
public:
    PlumbingSystem(const std::string& id, const std::string& material, double pressure, int fixtures);
    
    double calculateWaterFlow() const;
    bool validatePressureRequirements() const;
    
    std::string getId() const { return systemId; }
};

#endif
