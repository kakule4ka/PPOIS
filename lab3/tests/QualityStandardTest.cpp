#include <gtest/gtest.h>
#include "core/QualityStandard.h"
#include "core/ConstructionProject.h"
#include "models/BuildingMaterial.h"

TEST(QualityStandardTest, ValidateComplianceStructural) {
    QualityStandard standard("QST001", "Concrete Strength", "Structural", 30.0);
    bool compliant = standard.validateCompliance(29.5);
    EXPECT_TRUE(compliant);
}

TEST(QualityStandardTest, ValidateComplianceOutOfTolerance) {
    QualityStandard standard("QST003", "Surface Finish", "Finishing", 5.0);
    bool compliant = standard.validateCompliance(3.0);
    EXPECT_FALSE(compliant);
}

TEST(QualityStandardTest, CalculateQualityScorePerfect) {
    QualityStandard standard("QST004", "Dimensional Accuracy", "General", 100.0);
    double score = standard.calculateQualityScore(100.0);
    EXPECT_EQ(score, 100.0);
}

TEST(QualityStandardTest, CalculateStandardDeviation) {
    QualityStandard standard("QST005", "Test Standard", "General", 50.0);
    std::vector<double> measurements = {48.0, 50.0, 52.0, 49.0, 51.0};
    double deviation = standard.calculateStandardDeviation(measurements);
    EXPECT_GT(deviation, 0.0);
}

TEST(QualityStandardTest, IsIndustryStandard) {
    QualityStandard standard("QST006", "Industry Standard", "Structural", 25.0);
    bool industryStandard = standard.isIndustryStandard();
    EXPECT_FALSE(industryStandard);
}

TEST(QualityStandardTest, AddAndGetApplicableProjects) {
    QualityStandard standard("QST007", "Test Standard", "Electrical", 220.0);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    standard.addApplicableProject(&project1);
    standard.addApplicableProject(&project2);
    
    auto projects = standard.getApplicableProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(QualityStandardTest, AddAndGetTestedMaterials) {
    QualityStandard standard("QST008", "Material Standard", "Structural", 30.0);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Steel", 50, 80);
    
    standard.addTestedMaterial(&material1);
    standard.addTestedMaterial(&material2);
    
    auto materials = standard.getTestedMaterials();
    EXPECT_EQ(materials.size(), 2);
}
