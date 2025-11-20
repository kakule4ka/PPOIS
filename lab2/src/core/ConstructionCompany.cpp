#include "ConstructionCompany.h"

ConstructionCompany::ConstructionCompany(const std::string& name, const std::string& license, int year)
    : name(name), license(license), foundedYear(year) {}

double ConstructionCompany::calculateMaxProjectCapacity() const {
    return foundedYear < 2000 ? 10000000.0 : 5000000.0;
}

bool ConstructionCompany::verifyLicense() const {
    return license.length() >= 8 && license.find("CONST") != std::string::npos;
}
