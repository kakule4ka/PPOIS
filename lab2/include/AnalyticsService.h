#ifndef ANALYTICSSERVICE_H
#define ANALYTICSSERVICE_H

#include <string>

class AnalyticsService {
private:
    std::string serviceId;
    int dataSources;
    double predictionAccuracy;
    
public:
    AnalyticsService(const std::string& id, int sources, double accuracy);
    
    double calculateBusinessInsight() const;
    bool predictProjectSuccess() const;
    
    std::string getId() const { return serviceId; }
};

#endif
