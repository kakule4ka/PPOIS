#include <gtest/gtest.h>
#include "HVACSystem.h"

TEST(HVACSystemTest, CalculateEnergyConsumption) {
    HVACSystem system("HVAC001", 20000.0, 18000.0, 0.85);
    double consumption = system.calculateEnergyConsumption();
    EXPECT_NEAR(consumption, 19000.0, 0.01);
}

TEST(HVACSystemTest, CalculateEnergyConsumptionHighCapacity) {
    HVACSystem system("HVAC002", 50000.0, 45000.0, 0.78);
    double consumption = system.calculateEnergyConsumption();
    EXPECT_NEAR(consumption, 47500.0, 0.01);
}

TEST(HVACSystemTest, ValidateRoomComfortLargeRoom) {
    HVACSystem system("HVAC003", 20000.0, 18000.0, 0.85);
    bool comfortable = system.validateRoomComfort(15000.0);
    EXPECT_TRUE(comfortable);
}

TEST(HVACSystemTest, ValidateRoomComfortSmallRoom) {
    HVACSystem system("HVAC004", 5000.0, 4000.0, 0.82);
    bool comfortable = system.validateRoomComfort(4000.0);
    EXPECT_TRUE(comfortable);
}

TEST(HVACSystemTest, ValidateRoomComfortInsufficient) {
    HVACSystem system("HVAC005", 8000.0, 7000.0, 0.88);
    bool comfortable = system.validateRoomComfort(10000.0);
    EXPECT_FALSE(comfortable);
}

TEST(HVACSystemTest, GetSystemId) {
    HVACSystem system("HVAC006", 45000.0, 35000.0, 0.82);
    EXPECT_EQ(system.getId(), "HVAC006");
}
