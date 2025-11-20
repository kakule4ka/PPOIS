#ifndef QUALITYSTANDARD_H
#define QUALITYSTANDARD_H

#include <string>

class QualityStandard {
private:
    std::string standardId;
    std::string name;
    std::string category;
    double threshold;
    
public:
    QualityStandard(const std::string& id, const std::string& name, const std::string& category, double threshold);
    
    bool validateCompliance(double measuredValue) const;
    double calculateQualityScore(double actualValue) const;
    
    std::string getId() const { return standardId; }
};

#endif
