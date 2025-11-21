#include "Permit.h"
#include "ConstructionProject.h"
#include "QualityStandard.h"
#include <algorithm>

Permit::Permit(const std::string& id, const std::string& type, const std::string& authority)
    : permitId(id), type(type), issuingAuthority(authority), isActive(true),
      associatedProject(nullptr) {}

bool Permit::validateExpiryDate() const {
    int validityPeriod = 0;
    
    if (type == "Construction") {
        validityPeriod = 365;
    } else if (type == "Environmental") {
        validityPeriod = 180;
    } else if (type == "Safety") {
        validityPeriod = 90;
    } else {
        validityPeriod = 365;
    }
    
    bool isLongTerm = validityPeriod > 180;
    bool isFromMajorAuthority = issuingAuthority.find("State") != std::string::npos || 
                               issuingAuthority.find("Federal") != std::string::npos;
    
    return isActive && (isLongTerm || isFromMajorAuthority);
}

double Permit::calculateProcessingTime() const {
    double baseTime = 30.0;
    
    double authorityMultiplier = 1.0;
    if (issuingAuthority.find("Local") != std::string::npos) {
        authorityMultiplier = 0.8;
    } else if (issuingAuthority.find("State") != std::string::npos) {
        authorityMultiplier = 1.5;
    } else if (issuingAuthority.find("Federal") != std::string::npos) {
        authorityMultiplier = 2.0;
    }
    
    double typeMultiplier = 1.0;
    if (type == "Environmental") {
        typeMultiplier = 1.8;
    } else if (type == "Zoning") {
        typeMultiplier = 1.5;
    } else if (type == "Building") {
        typeMultiplier = 1.2;
    }
    
    return baseTime * authorityMultiplier * typeMultiplier;
}

double Permit::calculateComplianceScore() const {
    double baseScore = 80.0;
    
    double standardCompliance = 0.0;
    for (const auto& standard : requiredStandards) {
        standardCompliance += 5.0;
    }
    
    double projectFactor = associatedProject ? 10.0 : 0.0;
    double authorityFactor = issuingAuthority.find("State") != std::string::npos ? 5.0 : 0.0;
    double typeFactor = type == "Environmental" ? 3.0 : 0.0;
    
    double totalScore = baseScore + standardCompliance + projectFactor + authorityFactor + typeFactor;
    return totalScore > 100.0 ? 100.0 : totalScore;
}

bool Permit::needsRenewal() const {
    bool isExpired = !validateExpiryDate();
    bool hasNewStandards = false;
    
    for (const auto& standard : requiredStandards) {
        if (!standard->isIndustryStandard()) {
            hasNewStandards = true;
            break;
        }
    }
    
    bool projectChanged = associatedProject && associatedProject->getDuration() > 24;
    bool lowCompliance = calculateComplianceScore() < 70.0;
    
    return isExpired || hasNewStandards || projectChanged || lowCompliance;
}

void Permit::setAssociatedProject(ConstructionProject* project) {
    this->associatedProject = project;
}

ConstructionProject* Permit::getAssociatedProject() const {
    return associatedProject;
}

void Permit::addRequiredStandard(QualityStandard* standard) {
    if (standard) {
        requiredStandards.push_back(standard);
    }
}

void Permit::removeRequiredStandard(const std::string& standardId) {
    requiredStandards.erase(
        std::remove_if(requiredStandards.begin(), requiredStandards.end(),
            [&standardId](QualityStandard* standard) {
                return standard->getId() == standardId;
            }),
        requiredStandards.end()
    );
}

std::vector<QualityStandard*> Permit::getRequiredStandards() const {
    return requiredStandards;
}
