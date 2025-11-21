#include "QualityControlService.h"
#include "QualityStandard.h"

QualityControlService::QualityControlService(const std::string& id, int inspections, double rate)
    : serviceId(id), inspectionsCompleted(inspections), defectRate(rate) {}

double QualityControlService::calculateQualityIndex() const {
    double baseIndex = 100.0 - (defectRate * 100.0);
    
    // Используем ассоциацию
    double standardBonus = 0.0;
    for (const auto& standard : enforcedStandards) {
        if (standard->isIndustryStandard()) {
            standardBonus += 2.0;
        }
    }
    
    return baseIndex + standardBonus;
}

bool QualityControlService::detectQualityTrend() const {
    double qualityIndex = calculateQualityIndex();
    bool hasStandards = !enforcedStandards.empty();
    
    return qualityIndex > 85.0 && hasStandards;
}

void QualityControlService::addStandard(QualityStandard* standard) {
    if (standard) {
        enforcedStandards.push_back(standard);
    }
}

std::vector<QualityStandard*> QualityControlService::getEnforcedStandards() const {
    return enforcedStandards;
}
