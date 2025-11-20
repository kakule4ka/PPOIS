#include "Supplier.h"

Supplier::Supplier(const std::string& id, const std::string& name, const std::string& material, double reliability)
    : id(id), name(name), material(material), reliability(reliability) {}

double Supplier::calculateDeliveryRisk() const {
    return (1.0 - reliability) * 100.0;
}

bool Supplier::canHandleUrgentOrder() const {
    return reliability > 0.8 && material != "Concrete";
}
