#include "DoctorNotAvailableException.h"

DoctorNotAvailableException::DoctorNotAvailableException(const std::string& doctorId, const std::string& reason)
    : std::runtime_error("Doctor not available: " + doctorId + " - Reason: " + reason), 
      doctorId(doctorId), reason(reason) {}

std::string DoctorNotAvailableException::getDoctorId() const {
    return doctorId;
}

std::string DoctorNotAvailableException::getReason() const {
    return reason;
}
