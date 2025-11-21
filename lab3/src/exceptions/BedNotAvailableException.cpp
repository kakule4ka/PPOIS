#include "BedNotAvailableException.h"

BedNotAvailableException::BedNotAvailableException(const std::string& wardId, 
                                                  const std::string& bedType, int required)
    : std::runtime_error("Bed not available: Ward " + wardId + 
                        " - Type: " + bedType + 
                        ", Required: " + std::to_string(required)), 
      wardId(wardId), bedType(bedType), requiredBeds(required) {}

std::string BedNotAvailableException::getWardId() const {
    return wardId;
}

std::string BedNotAvailableException::getBedType() const {
    return bedType;
}

int BedNotAvailableException::getRequiredBeds() const {
    return requiredBeds;
}
