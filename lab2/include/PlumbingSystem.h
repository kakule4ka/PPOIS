#ifndef PLUMBINGSYSTEM_H
#define PLUMBINGSYSTEM_H

#include <string>
#include <vector>

class Building;
class QualityStandard;

class PlumbingSystem {
private:
    std::string systemId;
    std::string pipeMaterial;
    double waterPressure;
    int fixtures;
    Building* building;
    std::vector<QualityStandard*> complianceStandards;
    
public:
    PlumbingSystem(const std::string& id, const std::string& material, double pressure, int fixtures);
    
    double calculateWaterFlow() const;
    bool validatePressureRequirements() const;
    double calculateSystemReliability() const;
    bool meetsPlumbingCode() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addComplianceStandard(QualityStandard* standard);
    void removeComplianceStandard(const std::string& standardId);
    std::vector<QualityStandard*> getComplianceStandards() const;
    
    std::string getId() const { return systemId; }
};

#endif
