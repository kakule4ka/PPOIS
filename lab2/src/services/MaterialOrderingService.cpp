#include "MaterialOrderingService.h"

MaterialOrderingService::MaterialOrderingService(const std::string& id, int orders, double accuracy)
    : serviceId(id), ordersProcessed(orders), deliveryAccuracy(accuracy) {}

double MaterialOrderingService::calculateOrderEfficiency() const {
    return deliveryAccuracy * 100.0;
}

bool MaterialOrderingService::optimizeOrderQuantity() const {
    return ordersProcessed > 5;
}
