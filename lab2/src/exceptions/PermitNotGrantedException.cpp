#include "PermitNotGrantedException.h"

PermitNotGrantedException::PermitNotGrantedException(const std::string& permit)
    : std::runtime_error("Permit not granted: " + permit),
      permitType(permit) {}

std::string PermitNotGrantedException::getPermitType() const {
    return permitType;
}
