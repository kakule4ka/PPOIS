#include <gtest/gtest.h>
#include "models/Blueprint.h"
#include "core/ConstructionProject.h"
#include "models/BuildingMaterial.h"

TEST(BlueprintTest, CalculateMaterialRequirementsResidential) {
    Blueprint blueprint("BP001", "RES001", 1, 1.0);
    double materials = blueprint.calculateMaterialRequirements();
    EXPECT_NEAR(materials, 1600.0, 0.01);
}

TEST(BlueprintTest, IsCompatibleWithLargeSite) {
    Blueprint blueprint("BP004", "PROJ002", 1, 1.0);
    bool compatible = blueprint.isCompatibleWithSite(10000);
    EXPECT_TRUE(compatible);
}

TEST(BlueprintTest, CalculateDesignAccuracy) {
    Blueprint blueprint("BP005", "PROJ003", 2, 1.5);
    double accuracy = blueprint.calculateDesignAccuracy();
    EXPECT_GT(accuracy, 0.0);
}

TEST(BlueprintTest, NeedsRevision) {
    Blueprint blueprint("BP006", "PROJ004", 1, 1.0);
    bool needsRev = blueprint.needsRevision();
    EXPECT_TRUE(needsRev);
}

TEST(BlueprintTest, SetAndGetProject) {
    Blueprint blueprint("BP007", "PROJ005", 1, 1.0);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    blueprint.setProject(&project);
    EXPECT_EQ(blueprint.getProject()->getId(), "P1");
}

TEST(BlueprintTest, AddAndGetRequiredMaterials) {
    Blueprint blueprint("BP008", "PROJ006", 1, 1.0);
    BuildingMaterial material1("MAT1", "Concrete", 100, 50);
    BuildingMaterial material2("MAT2", "Steel", 50, 80);
    
    blueprint.addRequiredMaterial(&material1);
    blueprint.addRequiredMaterial(&material2);
    
    auto materials = blueprint.getRequiredMaterials();
    EXPECT_EQ(materials.size(), 2);
}
