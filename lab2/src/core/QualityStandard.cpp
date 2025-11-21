#include "QualityStandard.h"
#include "ConstructionProject.h"
#include "BuildingMaterial.h"
#include <algorithm>
#include <cmath>

QualityStandard::QualityStandard(const std::string& id, const std::string& name, const std::string& category, double threshold)
    : standardId(id), name(name), category(category), threshold(threshold) {}

bool QualityStandard::validateCompliance(double measuredValue) const {
    double tolerance = 0.0;
    
    if (category == "Structural") {
        tolerance = threshold * 0.05;
    } else if (category == "Electrical") {
        tolerance = threshold * 0.1;
    } else if (category == "Finishing") {
        tolerance = threshold * 0.15;
    } else {
        tolerance = threshold * 0.08;
    }
    
    double upperLimit = threshold + tolerance;
    double lowerLimit = threshold - tolerance;
    
    bool isWithinTolerance = measuredValue >= lowerLimit && measuredValue <= upperLimit;
    bool meetsMinimum = measuredValue >= threshold * 0.8;
    
    return isWithinTolerance && meetsMinimum;
}

double QualityStandard::calculateQualityScore(double actualValue) const {
    double deviation = std::abs(actualValue - threshold);
    double tolerance = threshold * 0.1;
    
    double baseScore = 100.0;
    double penalty = (deviation / tolerance) * 25.0;
    
    double adjustedScore = baseScore - penalty;
    
    if (category == "Structural" && actualValue < threshold) {
        adjustedScore *= 0.7;
    }
    
    if (adjustedScore < 0) {
        adjustedScore = 0;
    }
    
    return adjustedScore;
}

double QualityStandard::calculateStandardDeviation(const std::vector<double>& measurements) const {
    if (measurements.empty()) return 0.0;
    
    double sum = 0.0;
    for (double value : measurements) {
        sum += value;
    }
    double mean = sum / measurements.size();
    
    double variance = 0.0;
    for (double value : measurements) {
        variance += std::pow(value - mean, 2);
    }
    variance /= measurements.size();
    
    return std::sqrt(variance);
}

bool QualityStandard::isIndustryStandard() const {
    bool isCommonCategory = category == "Structural" || category == "Electrical" || category == "Safety";
    bool hasWideApplication = applicableProjects.size() >= 3;
    bool hasMaterialTesting = !testedMaterials.empty();
    bool hasReasonableThreshold = threshold > 0 && threshold < 1000;
    
    return isCommonCategory && hasWideApplication && hasMaterialTesting && hasReasonableThreshold;
}

void QualityStandard::addApplicableProject(ConstructionProject* project) {
    if (project) {
        applicableProjects.push_back(project);
    }
}

void QualityStandard::removeApplicableProject(const std::string& projectId) {
    applicableProjects.erase(
        std::remove_if(applicableProjects.begin(), applicableProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        applicableProjects.end()
    );
}

std::vector<ConstructionProject*> QualityStandard::getApplicableProjects() const {
    return applicableProjects;
}

void QualityStandard::addTestedMaterial(BuildingMaterial* material) {
    if (material) {
        testedMaterials.push_back(material);
    }
}

void QualityStandard::removeTestedMaterial(const std::string& materialId) {
    testedMaterials.erase(
        std::remove_if(testedMaterials.begin(), testedMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        testedMaterials.end()
    );
}

std::vector<BuildingMaterial*> QualityStandard::getTestedMaterials() const {
    return testedMaterials;
}
