#include <gtest/gtest.h>
#include "ElectricalSystem.h"

TEST(ElectricalSystemTest, CalculatePowerConsumption) {
    ElectricalSystem system("ELEC001", 220.0, 10000.0, 15);
    double consumption = system.calculatePowerConsumption(8.0);
    EXPECT_EQ(consumption, 80.0);
}

TEST(ElectricalSystemTest, CalculatePowerConsumptionHighUsage) {
    ElectricalSystem system("ELEC002", 220.0, 15000.0, 20);
    double consumption = system.calculatePowerConsumption(12.0);
    EXPECT_EQ(consumption, 180.0);
}

TEST(ElectricalSystemTest, ValidateCircuitLoadBalanced) {
    ElectricalSystem system("ELEC003", 220.0, 15000.0, 20);
    bool valid = system.validateCircuitLoad();
    EXPECT_TRUE(valid);
}

TEST(ElectricalSystemTest, ValidateCircuitLoadZeroCircuits) {
    ElectricalSystem system("ELEC004", 220.0, 10000.0, 0);
    bool valid = system.validateCircuitLoad();
    EXPECT_FALSE(valid);
}

TEST(ElectricalSystemTest, ValidateCircuitLoadZeroCapacity) {
    ElectricalSystem system("ELEC005", 220.0, 0.0, 10);
    bool valid = system.validateCircuitLoad();
    EXPECT_FALSE(valid);
}

TEST(ElectricalSystemTest, GetSystemId) {
    ElectricalSystem system("ELEC006", 220.0, 12000.0, 18);
    EXPECT_EQ(system.getId(), "ELEC006");
}
