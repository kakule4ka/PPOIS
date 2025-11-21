#include <gtest/gtest.h>
#include "models/Architect.h"
#include "models/Blueprint.h"
#include "core/ConstructionProject.h"
#include "core/QualityStandard.h"

TEST(ArchitectTest, CalculateDesignComplexity) {
    Architect architect("A001", "Frank Black", 80000, 15, "High-rise");
    double complexity = architect.calculateDesignComplexity();
    EXPECT_GT(complexity, 0);
}

TEST(ArchitectTest, ValidateCodeComplianceISO) {
    Architect architect("A003", "Henry King", 82000, 12, "Commercial");
    QualityStandard standard("STD001", "ISO Standard", "General", 100.0);
    architect.setDesignStandard(&standard);
    bool compliant = architect.validateCodeCompliance("ISO-12345");
    EXPECT_TRUE(compliant);
}

TEST(ArchitectTest, CalculateDesignEfficiency) {
    Architect architect("A004", "Ivy Chen", 78000, 10, "Residential");
    double efficiency = architect.calculateDesignEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ArchitectTest, CanTakeNewProject) {
    Architect architect("A005", "Jack Brown", 85000, 20, "High-rise");
    bool canTake = architect.canTakeNewProject();
    EXPECT_TRUE(canTake);
}

TEST(ArchitectTest, AddAndGetBlueprints) {
    Architect architect("A006", "Karen White", 79000, 18, "Commercial");
    Blueprint blueprint1("BP1", "P1", 1, 1.0);
    Blueprint blueprint2("BP2", "P2", 1, 1.5);
    
    architect.addBlueprint(&blueprint1);
    architect.addBlueprint(&blueprint2);
    
    auto blueprints = architect.getCreatedBlueprints();
    EXPECT_EQ(blueprints.size(), 2);
}

TEST(ArchitectTest, SetAndGetCurrentProject) {
    Architect architect("A007", "Mike Green", 82000, 8, "Industrial");
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    architect.setCurrentProject(&project);
    EXPECT_EQ(architect.getCurrentProject()->getId(), "P1");
}

TEST(ArchitectTest, SetAndGetDesignStandard) {
    Architect architect("A008", "Lisa Blue", 78000, 12, "Residential");
    QualityStandard standard("QS1", "Structural", "Structural", 30.0);
    
    architect.setDesignStandard(&standard);
    EXPECT_EQ(architect.getDesignStandard()->getId(), "QS1");
}
