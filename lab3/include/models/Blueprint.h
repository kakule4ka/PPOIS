#ifndef BLUEPRINT_H
#define BLUEPRINT_H

#include <string>
#include <vector>

class ConstructionProject;
class BuildingMaterial;

class Blueprint {
private:
    std::string blueprintId;
    std::string projectId;
    int version;
    double scale;
    ConstructionProject* project;
    std::vector<BuildingMaterial*> requiredMaterials;
    
public:
    Blueprint(const std::string& id, const std::string& projectId, int version, double scale);
    
    double calculateMaterialRequirements() const;
    bool isCompatibleWithSite(double siteArea) const;
    double calculateDesignAccuracy() const;
    bool needsRevision() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addRequiredMaterial(BuildingMaterial* material);
    void removeRequiredMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getRequiredMaterials() const;
    
    std::string getId() const { return blueprintId; }
};

#endif
