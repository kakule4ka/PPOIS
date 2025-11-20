#ifndef RESOURCEALLOCATION_H
#define RESOURCEALLOCATION_H

#include <string>

class ResourceAllocation {
private:
    std::string allocationId;
    std::string resourceId;
    std::string projectId;
    double allocatedAmount;
    
public:
    ResourceAllocation(const std::string& id, const std::string& resourceId, const std::string& projectId, double amount);
    
    double calculateUtilizationRate() const;
    bool isOverAllocated() const;
    
    std::string getId() const { return allocationId; }
};

#endif
