#include "QualityStandard.h"

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
