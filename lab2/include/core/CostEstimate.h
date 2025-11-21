#ifndef COSTESTIMATE_H
#define COSTESTIMATE_H

#include <string>
#include <vector>

class ConstructionProject;
class BuildingMaterial;
class Equipment;

class CostEstimate {
private:
    std::string estimateId;
    std::string projectId;
    double materialCost;
    double laborCost;
    ConstructionProject* project;
    std::vector<BuildingMaterial*> materials;
    std::vector<Equipment*> equipmentList; // Переименовано для избежания конфликта
    
public:
    CostEstimate(const std::string& id, const std::string& projectId, double material, double labor);
    
    double calculateTotalCost() const;
    double calculateVariance(double actualCost) const;
    double calculateAccuracy() const;
    bool isEstimateRealistic() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addMaterial(BuildingMaterial* material);
    void removeMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getMaterials() const;
    
    void addEquipment(Equipment* equipment);
    void removeEquipment(const std::string& equipmentId);
    std::vector<Equipment*> getEquipment() const;
    
    std::string getId() const { return estimateId; }
};

#endif
