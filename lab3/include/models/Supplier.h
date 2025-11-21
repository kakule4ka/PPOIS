#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>

class BuildingMaterial;
class ConstructionProject;

class Supplier {
private:
    std::string id;
    std::string name;
    std::string material;
    double reliability;
    std::vector<BuildingMaterial*> suppliedMaterials;
    std::vector<ConstructionProject*> servedProjects;
    
public:
    Supplier(const std::string& id, const std::string& name, const std::string& material, double reliability);
    
    double calculateDeliveryRisk() const;
    bool canHandleUrgentOrder() const;
    double calculateSupplierRating() const;
    bool isPreferredSupplier() const;
    
    void addSuppliedMaterial(BuildingMaterial* material);
    void removeSuppliedMaterial(const std::string& materialId);
    std::vector<BuildingMaterial*> getSuppliedMaterials() const;
    
    void addServedProject(ConstructionProject* project);
    void removeServedProject(const std::string& projectId);
    std::vector<ConstructionProject*> getServedProjects() const;
    
    std::string getId() const { return id; }
    double getReliability() const { return reliability; }
};

#endif
