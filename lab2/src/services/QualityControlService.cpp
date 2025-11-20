#include "QualityControlService.h"

QualityControlService::QualityControlService(const std::string& id, int inspections, double rate)
    : serviceId(id), inspectionsCompleted(inspections), defectRate(rate) {}

double QualityControlService::calculateQualityIndex() const {
    return (1.0 - defectRate) * 100.0;
}

bool QualityControlService::detectQualityTrend() const {
    return defectRate < 0.1;
}
