#ifndef HVACSYSTEM_H
#define HVACSYSTEM_H

#include <string>
#include <vector>

class Building;
class QualityStandard;

class HVACSystem {
private:
    std::string systemId;
    double coolingCapacity;
    double heatingCapacity;
    double efficiency;
    Building* building;
    std::vector<QualityStandard*> complianceStandards;
    
public:
    HVACSystem(const std::string& id, double cooling, double heating, double efficiency);
    
    double calculateEnergyConsumption() const;
    bool validateRoomComfort(double roomSize) const;
    double calculateSystemPerformance() const;
    bool isEnergyEfficient() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addComplianceStandard(QualityStandard* standard);
    void removeComplianceStandard(const std::string& standardId);
    std::vector<QualityStandard*> getComplianceStandards() const;
    
    std::string getId() const { return systemId; }
};

#endif
