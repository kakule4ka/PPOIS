#include <gtest/gtest.h>
#include "ConstructionCompany.h"

TEST(ConstructionCompanyTest, CalculateMaxProjectCapacityOldCompany) {
    ConstructionCompany company("Old Corp", "CONST12345", 1995);
    double capacity = company.calculateMaxProjectCapacity();
    EXPECT_EQ(capacity, 10000000.0);
}

TEST(ConstructionCompanyTest, CalculateMaxProjectCapacityNewCompany) {
    ConstructionCompany company("New Corp", "CONST67890", 2020);
    double capacity = company.calculateMaxProjectCapacity();
    EXPECT_EQ(capacity, 5000000.0);
}

TEST(ConstructionCompanyTest, VerifyLicenseValid) {
    ConstructionCompany company("Test Corp", "CONST12345", 2020);
    bool isValid = company.verifyLicense();
    EXPECT_TRUE(isValid);
}

TEST(ConstructionCompanyTest, LicenseValidationFailsShort) {
    ConstructionCompany company("Test Corp", "CONST", 2020);
    bool isValid = company.verifyLicense();
    EXPECT_FALSE(isValid);
}

TEST(ConstructionCompanyTest, LicenseValidationFailsNoConst) {
    ConstructionCompany company("Test Corp", "INVALID123", 2020);
    bool isValid = company.verifyLicense();
    EXPECT_FALSE(isValid);
}

TEST(ConstructionCompanyTest, GetCompanyName) {
    ConstructionCompany company("Big Builders", "CONST99999", 2010);
    EXPECT_EQ(company.getName(), "Big Builders");
}
