#include "InvalidBlueprintException.h"

InvalidBlueprintException::InvalidBlueprintException(const std::string& blueprint)
    : std::runtime_error("Invalid blueprint: " + blueprint),
      blueprintId(blueprint) {}

std::string InvalidBlueprintException::getBlueprintId() const {
    return blueprintId;
}
