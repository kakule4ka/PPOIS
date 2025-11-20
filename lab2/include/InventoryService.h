#ifndef INVENTORYSERVICE_H
#define INVENTORYSERVICE_H

#include <string>

class InventoryService {
private:
    std::string serviceId;
    int totalItems;
    double turnoverRate;
    
public:
    InventoryService(const std::string& id, int items, double rate);
    
    double calculateStockOutRisk() const;
    bool optimizeInventoryLevels() const;
    
    std::string getId() const { return serviceId; }
};

#endif
