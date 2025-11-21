#include "models/Blueprint.h"
#include "core/ConstructionProject.h"
#include "models/BuildingMaterial.h"
#include <algorithm>

Blueprint::Blueprint(const std::string& id, const std::string& projectId, int version, double scale)
    : blueprintId(id), projectId(projectId), version(version), scale(scale),
      project(nullptr) {}

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

double Blueprint::calculateDesignAccuracy() const {
    double baseAccuracy = 85.0;
    double versionBonus = version * 2.0;
    double scalePenalty = scale > 2.0 ? -5.0 : 0.0;
    
    double materialFactor = 0.0;
    for (const auto& material : requiredMaterials) {
        materialFactor += material->isQuantitySufficient(100) ? 1.0 : -0.5;
    }
    
    double projectFactor = project ? 3.0 : 0.0;
    
    double finalAccuracy = baseAccuracy + versionBonus + scalePenalty + materialFactor + projectFactor;
    return finalAccuracy > 100.0 ? 100.0 : finalAccuracy;
}

bool Blueprint::needsRevision() const {
    double accuracy = calculateDesignAccuracy();
    bool isLowAccuracy = accuracy < 80.0;
    bool hasMaterialIssues = false;
    
    for (const auto& material : requiredMaterials) {
        if (!material->isQuantitySufficient(50)) {
            hasMaterialIssues = true;
            break;
        }
    }
    
    bool isOutdated = version < 2;
    bool projectChanged = project && project->getDuration() > 18;
    
    return isLowAccuracy || hasMaterialIssues || isOutdated || projectChanged;
}

void Blueprint::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* Blueprint::getProject() const {
    return project;
}

void Blueprint::addRequiredMaterial(BuildingMaterial* material) {
    if (material) {
        requiredMaterials.push_back(material);
    }
}

void Blueprint::removeRequiredMaterial(const std::string& materialId) {
    requiredMaterials.erase(
        std::remove_if(requiredMaterials.begin(), requiredMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        requiredMaterials.end()
    );
}

std::vector<BuildingMaterial*> Blueprint::getRequiredMaterials() const {
    return requiredMaterials;
}
