#include "services/MaterialOrderingService.h"
#include "models/Supplier.h"

MaterialOrderingService::MaterialOrderingService(const std::string& id, int orders, double accuracy)
    : serviceId(id), ordersProcessed(orders), deliveryAccuracy(accuracy) {}

double MaterialOrderingService::calculateOrderEfficiency() const {
    return deliveryAccuracy * 100.0;
}

bool MaterialOrderingService::optimizeOrderQuantity() const {
    bool hasReliableSuppliers = false;
    for (const auto& supplier : approvedSuppliers) {
        if (supplier->isPreferredSupplier()) {
            hasReliableSuppliers = true;
            break;
        }
    }
    
    return hasReliableSuppliers && ordersProcessed > 10;
}

void MaterialOrderingService::addSupplier(Supplier* supplier) {
    if (supplier) {
        approvedSuppliers.push_back(supplier);
    }
}

std::vector<Supplier*> MaterialOrderingService::getApprovedSuppliers() const {
    return approvedSuppliers;
}
