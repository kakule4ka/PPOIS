#include "InventoryService.h"

InventoryService::InventoryService(const std::string& id, int items, double rate)
    : serviceId(id), totalItems(items), turnoverRate(rate) {}

double InventoryService::calculateStockOutRisk() const {
    double baseRisk = 10.0;
    
    double inventorySizeFactor = 1.0;
    if (totalItems > 1000) {
        inventorySizeFactor = 1.3;
    } else if (totalItems > 500) {
        inventorySizeFactor = 1.1;
    } else if (totalItems < 100) {
        inventorySizeFactor = 0.8;
    }
    
    double turnoverFactor = 1.0;
    if (turnoverRate > 8.0) {
        turnoverFactor = 0.7;
    } else if (turnoverRate > 5.0) {
        turnoverFactor = 0.8;
    } else if (turnoverRate > 3.0) {
        turnoverFactor = 0.9;
    } else if (turnoverRate < 1.0) {
        turnoverFactor = 1.5;
    }
    
    double managementFactor = 1.0;
    if (serviceId.find("AUTOMATED") != std::string::npos) {
        managementFactor = 0.8;
    }
    
    double seasonalityFactor = 1.2;
    
    double totalRisk = baseRisk * inventorySizeFactor * turnoverFactor * managementFactor * seasonalityFactor;
    
    return totalRisk > 100.0 ? 100.0 : totalRisk;
}

bool InventoryService::optimizeInventoryLevels() const {
    double idealTurnoverRate = 6.0;
    double turnoverDeviation = std::abs(turnoverRate - idealTurnoverRate);
    bool hasGoodTurnover = turnoverDeviation <= 2.0;
    
    double itemsPerCategory = totalItems / 10.0;
    bool hasBalancedCategories = itemsPerCategory >= 5.0 && itemsPerCategory <= 200.0;
    
    double stockOutRisk = calculateStockOutRisk();
    bool hasLowRisk = stockOutRisk <= 15.0;
    
    bool usesTechnology = serviceId.find("DIGITAL") != std::string::npos;
    bool hasProcesses = serviceId.find("PROCESS") != std::string::npos;
    
    return hasGoodTurnover && hasBalancedCategories && hasLowRisk && (usesTechnology || hasProcesses);
}
