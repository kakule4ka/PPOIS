#ifndef ELECTRICALSYSTEM_H
#define ELECTRICALSYSTEM_H

#include <string>
#include <vector>

class Building;
class QualityStandard;

class ElectricalSystem {
private:
    std::string systemId;
    double voltage;
    double powerCapacity;
    int circuits;
    Building* building;
    std::vector<QualityStandard*> complianceStandards;
    
public:
    ElectricalSystem(const std::string& id, double voltage, double capacity, int circuits);
    
    double calculatePowerConsumption(double usageHours) const;
    bool validateCircuitLoad() const;
    double calculateSystemEfficiency() const;
    bool isCodeCompliant() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addComplianceStandard(QualityStandard* standard);
    void removeComplianceStandard(const std::string& standardId);
    std::vector<QualityStandard*> getComplianceStandards() const;
    
    std::string getId() const { return systemId; }
};

#endif
