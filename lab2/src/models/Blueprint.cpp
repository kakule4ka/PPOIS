#include "Blueprint.h"

Blueprint::Blueprint(const std::string& id, const std::string& projectId, int version, double scale)
    : blueprintId(id), projectId(projectId), version(version), scale(scale) {}

double Blueprint::calculateMaterialRequirements() const {
    double baseMaterials = 1000.0;
    double scaleFactor = scale * 2.0;
    
    if (version > 1) {
        baseMaterials *= 1.1;
    }
    
    if (projectId.find("RES") != std::string::npos) {
        baseMaterials *= 0.8;
    } else if (projectId.find("COM") != std::string::npos) {
        baseMaterials *= 1.2;
    }
    
    return baseMaterials * scaleFactor;
}

bool Blueprint::isCompatibleWithSite(double siteArea) const {
    double requiredArea = scale * 500.0;
    return siteArea >= requiredArea;
}
