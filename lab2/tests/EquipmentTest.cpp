#include <gtest/gtest.h>
#include "Equipment.h"

TEST(EquipmentTest, CalculateDepreciation) {
    Equipment equipment("EQ001", "Excavator", 5000);
    double depreciation = equipment.calculateDepreciation();
    EXPECT_EQ(depreciation, 500);
}

TEST(EquipmentTest, CalculateDepreciationHighCost) {
    Equipment equipment("EQ002", "Crane", 15000);
    double depreciation = equipment.calculateDepreciation();
    EXPECT_EQ(depreciation, 1500);
}

TEST(EquipmentTest, NeedsMaintenanceHighUsage) {
    Equipment equipment("EQ003", "Bulldozer", 8000);
    equipment.setHoursUsed(1500);
    bool needsMaintenance = equipment.needsMaintenance();
    EXPECT_TRUE(needsMaintenance);
}

TEST(EquipmentTest, NeedsMaintenanceLowUsage) {
    Equipment equipment("EQ004", "Generator", 500);
    equipment.setHoursUsed(500);
    bool needsMaintenance = equipment.needsMaintenance();
    EXPECT_FALSE(needsMaintenance);
}

TEST(EquipmentTest, GetEquipmentId) {
    Equipment equipment("EQ005", "Compactor", 3500);
    EXPECT_EQ(equipment.getId(), "EQ005");
}
