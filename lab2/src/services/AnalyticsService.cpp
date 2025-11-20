#include "AnalyticsService.h"

AnalyticsService::AnalyticsService(const std::string& id, int sources, double accuracy)
    : serviceId(id), dataSources(sources), predictionAccuracy(accuracy) {}

double AnalyticsService::calculateBusinessInsight() const {
    return predictionAccuracy * 100.0;
}

bool AnalyticsService::predictProjectSuccess() const {
    return predictionAccuracy > 0.7;
}
