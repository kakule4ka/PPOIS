#include <gtest/gtest.h>
#include "Permit.h"

TEST(PermitTest, ValidateExpiryDateConstruction) {
    Permit permit("PER001", "Construction", "Local Authority");
    bool valid = permit.validateExpiryDate();
    EXPECT_TRUE(valid);
}

TEST(PermitTest, ValidateExpiryDateEnvironmental) {
    Permit permit("PER002", "Environmental", "State Agency");
    bool valid = permit.validateExpiryDate();
    EXPECT_TRUE(valid);
}

TEST(PermitTest, CalculateProcessingTimeLocal) {
    Permit permit("PER003", "Building", "Local Municipality");
    double time = permit.calculateProcessingTime();
    EXPECT_LT(time, 40.0);
}

TEST(PermitTest, CalculateProcessingTimeFederal) {
    Permit permit("PER004", "Environmental", "Federal Agency");
    double time = permit.calculateProcessingTime();
    EXPECT_GT(time, 50.0);
}

TEST(PermitTest, CalculateProcessingTimeZoning) {
    Permit permit("PER005", "Zoning", "City Council");
    double time = permit.calculateProcessingTime();
    EXPECT_GT(time, 40.0);
}

TEST(PermitTest, GetPermitId) {
    Permit permit("PER006", "Safety", "State Department");
    EXPECT_EQ(permit.getId(), "PER006");
}
