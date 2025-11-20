#include <gtest/gtest.h>
#include "QualityStandard.h"

TEST(QualityStandardTest, ValidateComplianceStructural) {
    QualityStandard standard("QST001", "Concrete Strength", "Structural", 30.0);
    bool compliant = standard.validateCompliance(29.5);
    EXPECT_TRUE(compliant);
}

TEST(QualityStandardTest, ValidateComplianceElectrical) {
    QualityStandard standard("QST002", "Voltage Stability", "Electrical", 220.0);
    bool compliant = standard.validateCompliance(215.0);
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

TEST(QualityStandardTest, CalculateQualityScoreBelowStandard) {
    QualityStandard standard("QST005", "Load Capacity", "Structural", 50.0);
    double score = standard.calculateQualityScore(40.0);
    EXPECT_LT(score, 70.0);
}

TEST(QualityStandardTest, GetStandardId) {
    QualityStandard standard("QST006", "Waterproofing", "General", 95.0);
    EXPECT_EQ(standard.getId(), "QST006");
}
