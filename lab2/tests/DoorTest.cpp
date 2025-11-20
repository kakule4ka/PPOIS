#include <gtest/gtest.h>
#include "Door.h"

TEST(DoorTest, CalculateSecurityLevelSecurityDoor) {
    Door door("DOOR001", "Security", "Steel", 0.9);
    double security = door.calculateSecurityLevel();
    EXPECT_GT(security, 200.0);
}

TEST(DoorTest, CalculateSecurityLevelStandardDoor) {
    Door door("DOOR002", "Standard", "SolidWood", 0.8);
    double security = door.calculateSecurityLevel();
    EXPECT_GT(security, 50.0);
}

TEST(DoorTest, CalculateSecurityLevelGlassDoor) {
    Door door("DOOR003", "Glass", "Aluminum", 1.0);
    double security = door.calculateSecurityLevel();
    EXPECT_LT(security, 100.0);
}

TEST(DoorTest, ValidateAccessibilityNormal) {
    Door door("DOOR004", "Standard", "Hollow", 0.85);
    bool accessible = door.validateAccessibility();
    EXPECT_TRUE(accessible);
}

TEST(DoorTest, ValidateAccessibilityNarrow) {
    Door door("DOOR005", "Security", "Steel", 0.75);
    bool accessible = door.validateAccessibility();
    EXPECT_FALSE(accessible);
}

TEST(DoorTest, GetDoorId) {
    Door door("DOOR006", "Fire", "SolidWood", 0.95);
    EXPECT_EQ(door.getId(), "DOOR006");
}
