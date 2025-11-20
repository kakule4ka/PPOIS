#include "QualityStandardNotMetException.h"

QualityStandardNotMetException::QualityStandardNotMetException(const std::string& standard, double value)
    : std::runtime_error("Quality standard not met: " + standard + " - value: " + std::to_string(value)),
      standardName(standard), actualValue(value) {}

std::string QualityStandardNotMetException::getStandardName() const {
    return standardName;
}

double QualityStandardNotMetException::getActualValue() const {
    return actualValue;
}
