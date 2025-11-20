#include "Permit.h"

Permit::Permit(const std::string& id, const std::string& type, const std::string& authority)
    : permitId(id), type(type), issuingAuthority(authority), isActive(true) {}

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
