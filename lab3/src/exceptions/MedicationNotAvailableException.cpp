#include "MedicationNotAvailableException.h"

MedicationNotAvailableException::MedicationNotAvailableException(const std::string& medicationName, 
                                                               double required, double available)
    : std::runtime_error("Medication not available: " + medicationName + 
                        " - Required: " + std::to_string(required) + 
                        ", Available: " + std::to_string(available)), 
      medicationName(medicationName), requiredQuantity(required), availableQuantity(available) {}

std::string MedicationNotAvailableException::getMedicationName() const {
    return medicationName;
}

double MedicationNotAvailableException::getRequiredQuantity() const {
    return requiredQuantity;
}

double MedicationNotAvailableException::getAvailableQuantity() const {
    return availableQuantity;
}
