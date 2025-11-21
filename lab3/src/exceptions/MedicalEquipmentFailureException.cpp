#include "MedicalEquipmentFailureException.h"

MedicalEquipmentFailureException::MedicalEquipmentFailureException(const std::string& equipmentId, 
                                                                  const std::string& failureType)
    : std::runtime_error("Medical equipment failure: " + equipmentId + 
                        " - Failure type: " + failureType), 
      equipmentId(equipmentId), failureType(failureType) {}

std::string MedicalEquipmentFailureException::getEquipmentId() const {
    return equipmentId;
}

std::string MedicalEquipmentFailureException::getFailureType() const {
    return failureType;
}
