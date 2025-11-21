#include "exceptions/MaterialShortageException.h"

MaterialShortageException::MaterialShortageException(const std::string& material, double shortage)
    : std::runtime_error("Material shortage: " + material + " - shortage: " + std::to_string(shortage)),
      materialName(material), shortageAmount(shortage) {}

std::string MaterialShortageException::getMaterialName() const {
    return materialName;
}

double MaterialShortageException::getShortageAmount() const {
    return shortageAmount;
}
