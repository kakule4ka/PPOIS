#ifndef BLUEPRINT_H
#define BLUEPRINT_H

#include <string>

class Blueprint {
private:
    std::string blueprintId;
    std::string projectId;
    int version;
    double scale;
    
public:
    Blueprint(const std::string& id, const std::string& projectId, int version, double scale);
    
    double calculateMaterialRequirements() const;
    bool isCompatibleWithSite(double siteArea) const;
    
    std::string getId() const { return blueprintId; }
};

#endif
