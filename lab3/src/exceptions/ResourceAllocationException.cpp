#include "exceptions/ResourceAllocationException.h"

ResourceAllocationException::ResourceAllocationException(const std::string& resource)
    : std::runtime_error("Resource allocation exception: " + resource),
      resourceType(resource) {}

std::string ResourceAllocationException::getResourceType() const {
    return resourceType;
}
