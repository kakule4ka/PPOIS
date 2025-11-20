#include <gtest/gtest.h>
#include "Blueprint.h"

TEST(BlueprintTest, CalculateMaterialRequirementsResidential) {
    Blueprint blueprint("BP001", "RES001", 1, 1.0);
    double materials = blueprint.calculateMaterialRequirements();
    EXPECT_NEAR(materials, 1600.0, 0.01);
}

TEST(BlueprintTest, CalculateMaterialRequirementsCommercial) {
    Blueprint blueprint("BP002", "COM001", 2, 1.5);
    double materials = blueprint.calculateMaterialRequirements();
    EXPECT_NEAR(materials, 3960.0, 0.01);
}

TEST(BlueprintTest, CalculateMaterialRequirementsVersion1) {
    Blueprint blueprint("BP003", "PROJ001", 1, 2.0);
    double materials = blueprint.calculateMaterialRequirements();
    EXPECT_NEAR(materials, 4000.0, 0.01);
}

TEST(BlueprintTest, IsCompatibleWithLargeSite) {
    Blueprint blueprint("BP004", "PROJ002", 1, 1.0);
    bool compatible = blueprint.isCompatibleWithSite(10000);
    EXPECT_TRUE(compatible);
}

TEST(BlueprintTest, IsNotCompatibleWithSmallSite) {
    Blueprint blueprint("BP005", "PROJ003", 1, 2.0);
    bool compatible = blueprint.isCompatibleWithSite(500);
    EXPECT_FALSE(compatible);
}

TEST(BlueprintTest, GetBlueprintId) {
    Blueprint blueprint("BP006", "PROJ004", 1, 1.0);
    EXPECT_EQ(blueprint.getId(), "BP006");
}
