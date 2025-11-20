#include <gtest/gtest.h>
#include "Architect.h"

TEST(ArchitectTest, CalculateDesignComplexity) {
    Architect architect("A001", "Frank Black", 80000, 15, "High-rise");
    double complexity = architect.calculateDesignComplexity();
    EXPECT_GT(complexity, 0);
}

TEST(ArchitectTest, CalculateDesignComplexityIndustrial) {
    Architect architect("A002", "Grace Lee", 75000, 8, "Industrial");
    double complexity = architect.calculateDesignComplexity();
    EXPECT_GT(complexity, 0);
}

TEST(ArchitectTest, ValidateCodeComplianceISO) {
    Architect architect("A003", "Henry King", 82000, 12, "Commercial");
    bool compliant = architect.validateCodeCompliance("ISO-12345");
    EXPECT_TRUE(compliant);
}

TEST(ArchitectTest, ValidateCodeComplianceASTM) {
    Architect architect("A004", "Ivy Chen", 78000, 10, "Residential");
    bool compliant = architect.validateCodeCompliance("ASTM-67890");
    EXPECT_TRUE(compliant);
}

TEST(ArchitectTest, InvalidCodeCompliance) {
    Architect architect("A005", "Jack Brown", 85000, 20, "High-rise");
    bool compliant = architect.validateCodeCompliance("INVALID-CODE");
    EXPECT_FALSE(compliant);
}

TEST(ArchitectTest, GetArchitectId) {
    Architect architect("A006", "Karen White", 79000, 18, "Commercial");
    EXPECT_EQ(architect.getId(), "A006");
}
