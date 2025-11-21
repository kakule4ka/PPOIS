#include <gtest/gtest.h>
#include "core/Permit.h"
#include "core/ConstructionProject.h"
#include "core/QualityStandard.h"

TEST(PermitTest, ValidateExpiryDateConstruction) {
    Permit permit("PER001", "Construction", "Local Authority");
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

TEST(PermitTest, CalculateComplianceScore) {
    Permit permit("PER005", "Zoning", "City Council");
    double score = permit.calculateComplianceScore();
    EXPECT_GT(score, 0.0);
}

TEST(PermitTest, NeedsRenewal) {
    Permit permit("PER006", "Safety", "State Department");
    bool needsRenew = permit.needsRenewal();
    EXPECT_FALSE(needsRenew);
}

TEST(PermitTest, SetAndGetAssociatedProject) {
    Permit permit("PER007", "Building", "Local Authority");
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    permit.setAssociatedProject(&project);
    EXPECT_EQ(permit.getAssociatedProject()->getId(), "P1");
}

TEST(PermitTest, AddAndGetRequiredStandards) {
    Permit permit("PER008", "Environmental", "State Agency");
    QualityStandard standard1("QS1", "Water Quality", "Environmental", 50.0);
    QualityStandard standard2("QS2", "Air Quality", "Environmental", 30.0);
    
    permit.addRequiredStandard(&standard1);
    permit.addRequiredStandard(&standard2);
    
    auto standards = permit.getRequiredStandards();
    EXPECT_EQ(standards.size(), 2);
}
