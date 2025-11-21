#ifndef INVENTORYSERVICE_H
#define INVENTORYSERVICE_H

#include <string>
#include <vector>

class BuildingMaterial;

class InventoryService {
private:
    std::string serviceId;
    int totalItems;
    double turnoverRate;
    std::vector<BuildingMaterial*> managedMaterials; // +1 ассоциация
    
public:
    InventoryService(const std::string& id, int items, double rate);
    
    double calculateStockOutRisk() const;
    bool optimizeInventoryLevels() const;
    
    // Ассоциация
    void addMaterial(BuildingMaterial* material);
    std::vector<BuildingMaterial*> getManagedMaterials() const;
    
    std::string getId() const { return serviceId; }
};

#endif
