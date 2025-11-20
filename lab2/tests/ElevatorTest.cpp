#include <gtest/gtest.h>
#include "Elevator.h"

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

TEST(ElevatorTest, CalculateRoundTripTimeMidRise) {
    Elevator elevator("ELEV003", 12, 10, 2.0);
    double time = elevator.calculateRoundTripTime();
    EXPECT_EQ(time, 100.0);
}

TEST(ElevatorTest, ValidateCapacityRequirementsAdequate) {
    Elevator elevator("ELEV004", 12, 8, 2.0);
    bool adequate = elevator.validateCapacityRequirements(500);
    EXPECT_TRUE(adequate);
}

TEST(ElevatorTest, ValidateCapacityRequirementsInadequate) {
    Elevator elevator("ELEV005", 8, 15, 2.5);
    bool adequate = elevator.validateCapacityRequirements(1000);
    EXPECT_FALSE(adequate);
}

TEST(ElevatorTest, GetElevatorId) {
    Elevator elevator("ELEV006", 13, 6, 1.8);
    EXPECT_EQ(elevator.getId(), "ELEV006");
}
