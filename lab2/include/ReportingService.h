#ifndef REPORTINGSERVICE_H
#define REPORTINGSERVICE_H

#include <string>

class ReportingService {
private:
    std::string serviceId;
    int reportsGenerated;
    double accuracyRate;
    
public:
    ReportingService(const std::string& id, int reports, double accuracy);
    
    double calculateReportValue() const;
    bool automateReportGeneration() const;
    
    std::string getId() const { return serviceId; }
};

#endif
