#ifndef QUALITYCONTROLSERVICE_H
#define QUALITYCONTROLSERVICE_H

#include <string>
#include <vector>

class QualityStandard;

class QualityControlService {
private:
    std::string serviceId;
    int inspectionsCompleted;
    double defectRate;
    std::vector<QualityStandard*> enforcedStandards; // +1 ассоциация
    
public:
    QualityControlService(const std::string& id, int inspections, double rate);
    
    double calculateQualityIndex() const;
    bool detectQualityTrend() const;
    
    // Ассоциация
    void addStandard(QualityStandard* standard);
    std::vector<QualityStandard*> getEnforcedStandards() const;
    
    std::string getId() const { return serviceId; }
};

#endif
