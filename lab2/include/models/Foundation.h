#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <string>
#include <vector>

class Building;
class QualityStandard;

class Foundation {
private:
    std::string foundationId;
    std::string type;
    double depth;
    double loadCapacity;
    Building* building;
    std::vector<QualityStandard*> complianceStandards;
    
public:
    Foundation(const std::string& id, const std::string& type, double depth, double capacity);
    
    double calculateConstructionTime() const;
    bool validateSoilCompatibility(const std::string& soilType) const;
    double calculateStabilityFactor() const;
    bool meetsStructuralRequirements() const;
    
    void setBuilding(Building* building);
    Building* getBuilding() const;
    
    void addComplianceStandard(QualityStandard* standard);
    void removeComplianceStandard(const std::string& standardId);
    std::vector<QualityStandard*> getComplianceStandards() const;
    
    std::string getId() const { return foundationId; }
};

#endif
