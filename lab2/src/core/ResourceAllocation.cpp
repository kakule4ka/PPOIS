#include "ResourceAllocation.h"

ResourceAllocation::ResourceAllocation(const std::string& id, const std::string& resourceId, const std::string& projectId, double amount)
    : allocationId(id), resourceId(resourceId), projectId(projectId), allocatedAmount(amount) {}

double ResourceAllocation::calculateUtilizationRate() const {
    return allocatedAmount;
}

bool ResourceAllocation::isOverAllocated() const {
    return allocatedAmount > 100000;
}
