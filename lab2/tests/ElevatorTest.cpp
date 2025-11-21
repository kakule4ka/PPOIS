#include <gtest/gtest.h>
#include "models/Elevator.h"
#include "models/Building.h"
#include "core/SafetyProtocol.h"

TEST(ElevatorTest, CalculateRoundTripTimeLowRise) {
    Elevator elevator("ELEV001", 10, 5, 1.5);
    double time = elevator.calculateRoundTripTime();
    EXPECT_EQ(time, 50.0);
}

TEST(ElevatorTest, CalculateRoundTripTimeHighRise) {
    Elevator elevator("ELEV002", 15, 20, 3.0);
    double time = elevator.calculateRoundTripTime();
    EXPECT_EQ(time, 200.0);
}

TEST(ElevatorTest, ValidateCapacityRequirementsAdequate) {
    Elevator elevator("ELEV004", 12, 8, 2.0);
    bool adequate = elevator.validateCapacityRequirements(500);
    EXPECT_TRUE(adequate);
}

TEST(ElevatorTest, CalculateElevatorEfficiency) {
    Elevator elevator("ELEV005", 13, 10, 2.5);
    double efficiency = elevator.calculateElevatorEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ElevatorTest, MeetsSafetyStandards) {
    Elevator elevator("ELEV006", 15, 25, 3.0);
    bool meetsStandards = elevator.meetsSafetyStandards();
    EXPECT_FALSE(meetsStandards);
}

TEST(ElevatorTest, SetAndGetBuilding) {
    Elevator elevator("ELEV007", 12, 8, 2.0);
    Building building("B1", "Test Building", 10, 5000);
    
    elevator.setBuilding(&building);
    EXPECT_EQ(elevator.getBuilding()->getId(), "B1");
}

TEST(ElevatorTest, AddAndGetSafetyProtocols) {
    Elevator elevator("ELEV008", 10, 6, 1.8);
    SafetyProtocol protocol1("SP1", "Emergency Brakes", 30, true);
    SafetyProtocol protocol2("SP2", "Overload Protection", 25, true);
    
    elevator.addSafetyProtocol(&protocol1);
    elevator.addSafetyProtocol(&protocol2);
    
    auto protocols = elevator.getSafetyProtocols();
    EXPECT_EQ(protocols.size(), 2);
}
