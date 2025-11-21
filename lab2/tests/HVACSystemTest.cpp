#include <gtest/gtest.h>
#include "models/HVACSystem.h"
#include "models/Building.h"
#include "core/QualityStandard.h"

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

TEST(HVACSystemTest, CalculateSystemPerformance) {
    HVACSystem system("HVAC004", 25000.0, 22000.0, 0.82);
    double performance = system.calculateSystemPerformance();
    EXPECT_GT(performance, 0.0);
}

TEST(HVACSystemTest, IsEnergyEfficient) {
    HVACSystem system("HVAC005", 30000.0, 28000.0, 0.88);
    bool efficient = system.isEnergyEfficient();
    EXPECT_FALSE(efficient);
}

TEST(HVACSystemTest, SetAndGetBuilding) {
    HVACSystem system("HVAC006", 20000.0, 18000.0, 0.85);
    Building building("B1", "Test Building", 5, 2000);
    
    system.setBuilding(&building);
    EXPECT_EQ(system.getBuilding()->getId(), "B1");
}

TEST(HVACSystemTest, AddAndGetComplianceStandards) {
    HVACSystem system("HVAC007", 25000.0, 23000.0, 0.80);
    QualityStandard standard1("QS1", "Energy Efficiency", "HVAC", 80.0);
    QualityStandard standard2("QS2", "Cooling Performance", "HVAC", 75.0);
    
    system.addComplianceStandard(&standard1);
    system.addComplianceStandard(&standard2);
    
    auto standards = system.getComplianceStandards();
    EXPECT_EQ(standards.size(), 2);
}
