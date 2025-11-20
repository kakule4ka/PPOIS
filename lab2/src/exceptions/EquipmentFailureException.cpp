#include "EquipmentFailureException.h"

EquipmentFailureException::EquipmentFailureException(const std::string& equipment)
    : std::runtime_error("Equipment failure: " + equipment),
      equipmentId(equipment) {}

std::string EquipmentFailureException::getEquipmentId() const {
    return equipmentId;
}
