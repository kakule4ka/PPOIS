#ifndef QUALITYCONTROLSERVICE_H
#define QUALITYCONTROLSERVICE_H

#include <string>

class QualityControlService {
private:
    std::string serviceId;
    int inspectionsCompleted;
    double defectRate;
    
public:
    QualityControlService(const std::string& id, int inspections, double rate);
    
    double calculateQualityIndex() const;
    bool detectQualityTrend() const;
    
    std::string getId() const { return serviceId; }
};

#endif
