#include "PrescriptionInvalidException.h"

PrescriptionInvalidException::PrescriptionInvalidException(const std::string& prescriptionId, 
                                                          const std::string& medicationName, 
                                                          const std::string& validationError)
    : std::runtime_error("Prescription invalid: ID " + prescriptionId + 
                        " - Medication: " + medicationName + 
                        " - Error: " + validationError), 
      prescriptionId(prescriptionId), medicationName(medicationName), validationError(validationError) {}

std::string PrescriptionInvalidException::getPrescriptionId() const {
    return prescriptionId;
}

std::string PrescriptionInvalidException::getMedicationName() const {
    return medicationName;
}

std::string PrescriptionInvalidException::getValidationError() const {
    return validationError;
}
