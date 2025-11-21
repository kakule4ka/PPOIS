#include "exceptions/SafetyViolationException.h"

SafetyViolationException::SafetyViolationException(const std::string& violation)
    : std::runtime_error("Safety violation: " + violation),
      violationType(violation) {}

std::string SafetyViolationException::getViolationType() const {
    return violationType;
}
