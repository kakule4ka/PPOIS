#include "PatientNotFoundException.h"

PatientNotFoundException::PatientNotFoundException(const std::string& patientId)
    : std::runtime_error("Patient not found: " + patientId), patientId(patientId) {}

std::string PatientNotFoundException::getPatientId() const {
    return patientId;
}
