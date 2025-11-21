#include <gtest/gtest.h>
#include "models/ElectricalSystem.h"
#include "models/Building.h"
#include "core/QualityStandard.h"

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

TEST(ElectricalSystemTest, CalculateSystemEfficiency) {
    ElectricalSystem system("ELEC004", 220.0, 12000.0, 18);
    double efficiency = system.calculateSystemEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ElectricalSystemTest, IsCodeCompliant) {
    ElectricalSystem system("ELEC005", 220.0, 10000.0, 15);
    bool compliant = system.isCodeCompliant();
    EXPECT_FALSE(compliant);
}

TEST(ElectricalSystemTest, SetAndGetBuilding) {
    ElectricalSystem system("ELEC006", 220.0, 12000.0, 18);
    Building building("B1", "Test Building", 5, 2000);
    
    system.setBuilding(&building);
    EXPECT_EQ(system.getBuilding()->getId(), "B1");
}

TEST(ElectricalSystemTest, AddAndGetComplianceStandards) {
    ElectricalSystem system("ELEC007", 220.0, 15000.0, 20);
    QualityStandard standard1("QS1", "Voltage Stability", "Electrical", 220.0);
    QualityStandard standard2("QS2", "Power Quality", "Electrical", 50.0);
    
    system.addComplianceStandard(&standard1);
    system.addComplianceStandard(&standard2);
    
    auto standards = system.getComplianceStandards();
    EXPECT_EQ(standards.size(), 2);
}
