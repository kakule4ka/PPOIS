#include "CostEstimate.h"

CostEstimate::CostEstimate(const std::string& id, const std::string& projectId, double material, double labor)
    : estimateId(id), projectId(projectId), materialCost(material), laborCost(labor) {}

double CostEstimate::calculateTotalCost() const {
    return materialCost + laborCost;
}

double CostEstimate::calculateVariance(double actualCost) const {
    return actualCost - calculateTotalCost();
}
