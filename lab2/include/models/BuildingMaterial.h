#ifndef BUILDINGMATERIAL_H
#define BUILDINGMATERIAL_H

#include <string>
#include <vector>

class ConstructionProject;
class Supplier;

class BuildingMaterial {
private:
    std::string materialId;
    std::string name;
    double quantity;
    double unitCost;
    ConstructionProject* usedInProject;
    Supplier* supplier;
    
public:
    BuildingMaterial(const std::string& id, const std::string& name, double quantity, double cost);
    
    double calculateTotalCost() const;
    bool isQuantitySufficient(double required) const;
    double calculateWasteEstimate() const;
    bool needsReordering() const;
    
    void setUsedInProject(ConstructionProject* project);
    ConstructionProject* getUsedInProject() const;
    
    void setSupplier(Supplier* supplier);
    Supplier* getSupplier() const;
    
    std::string getId() const { return materialId; }
    std::string getName() const { return name; }  // Добавлен getter
    double getQuantity() const { return quantity; }
    double getUnitCost() const { return unitCost; }  // Добавлен getter
};

#endif
