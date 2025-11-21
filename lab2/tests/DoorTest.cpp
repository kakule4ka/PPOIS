#include <gtest/gtest.h>
#include "Door.h"
#include "Building.h"
#include "SafetyProtocol.h"

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

TEST(DoorTest, CalculateDoorPerformance) {
    Door door("DOOR006", "Fire", "SolidWood", 0.95);
    double performance = door.calculateDoorPerformance();
    EXPECT_GT(performance, 0.0);
}

TEST(DoorTest, MeetsBuildingCode) {
    Door door("DOOR007", "Standard", "SolidWood", 0.9);
    bool meetsCode = door.meetsBuildingCode();
    EXPECT_FALSE(meetsCode);
}

TEST(DoorTest, SetAndGetBuilding) {
    Door door("DOOR008", "Security", "Steel", 0.9);
    Building building("B1", "Test Building", 5, 2000);
    
    door.setBuilding(&building);
    EXPECT_EQ(door.getBuilding()->getId(), "B1");
}

TEST(DoorTest, AddAndGetSafetyFeatures) {
    Door door("DOOR009", "Fire", "SolidWood", 0.95);
    SafetyProtocol protocol1("SP1", "Fire Rating", 40, true);
    SafetyProtocol protocol2("SP2", "Emergency Exit", 25, true);
    
    door.addSafetyFeature(&protocol1);
    door.addSafetyFeature(&protocol2);
    
    auto features = door.getSafetyFeatures();
    EXPECT_EQ(features.size(), 2);
}
