#ifndef QUALITYSTANDARD_H
#define QUALITYSTANDARD_H

#include <string>
#include <vector>

class ConstructionProject;
class BuildingMaterial;

class QualityStandard {
private:
    std::string standardId;
    std::string name;
    std::string category;
    double threshold;
    std::vector<ConstructionProject*> applicableProjects;
    std::vector<BuildingMaterial*> testedMaterials;
    
public:
    QualityStandard(const std::string& id, const std::string& name, const std::string& category, double threshold);
    
    bool validateCompliance(double measuredValue) const;
    double calculateQualityScore(double actualValue) const;
    double calculateStandardDeviation(const std::vector<double>& measurements) const;
    bool isIndustryStandard() const;
    
    void addApplicableProject(ConstructionProject* project);
    void removeApplicableProject(const std::string& projectId);
    std::vector<ConstructionProject*> getApplicableProjects() const;
    
    void addTestedMaterial(BuildingMaterial* material);
    void removeTestedMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getTestedMaterials() const;
    
    std::string getId() const { return standardId; }
    double getThreshold() const { return threshold; }
};

#endif
