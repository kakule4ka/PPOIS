#include "Architect.h"

Architect::Architect(const std::string& id, const std::string& name, double salary, int designs, const std::string& specialty)
    : Employee(id, name, "Architect", salary), completedDesigns(designs), specialty(specialty) {}

double Architect::calculateDesignComplexity() const {
    double complexity = completedDesigns * 0.1;
    if (specialty == "High-rise") complexity *= 2.0;
    if (specialty == "Industrial") complexity *= 1.5;
    return complexity;
}

bool Architect::validateCodeCompliance(const std::string& code) const {
    return code.find("ISO") != std::string::npos || code.find("ASTM") != std::string::npos;
}
