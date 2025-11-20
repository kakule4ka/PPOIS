#ifndef COSTESTIMATE_H
#define COSTESTIMATE_H

#include <string>

class CostEstimate {
private:
    std::string estimateId;
    std::string projectId;
    double materialCost;
    double laborCost;
    
public:
    CostEstimate(const std::string& id, const std::string& projectId, double material, double labor);
    
    double calculateTotalCost() const;
    double calculateVariance(double actualCost) const;
    
    std::string getId() const { return estimateId; }
};

#endif
