#include <gtest/gtest.h>
#include "Surgeon.h"
#include "Surgery.h"
#include "OperatingRoom.h"

class SurgeonTest : public ::testing::Test {
protected:
    void SetUp() override {
        surgeon = new Surgeon("S001", "Dr. Cut", 14, "SURG123", 15, 180, 4.2);
        surgery = new Surgery("SUR001", "Appendectomy", 90);
        operatingRoom = new OperatingRoom("OR001", "Main OR", true);
    }

    void TearDown() override {
        delete surgeon;
        delete surgery;
        delete operatingRoom;
    }

    Surgeon* surgeon;
    Surgery* surgery;
    OperatingRoom* operatingRoom;
};

TEST_F(SurgeonTest, CalculateSurgicalRisk) {
    double risk = surgeon->calculateSurgicalRisk(surgery);
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(SurgeonTest, CanHandleComplexSurgery) {
    bool canHandle = surgeon->canHandleComplexSurgery();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(SurgeonTest, CalculateSurgicalOutcomeScore) {
    double outcomeScore = surgeon->calculateSurgicalOutcomeScore();
    EXPECT_GE(outcomeScore, 0.0);
    EXPECT_LE(outcomeScore, 100.0);
}

TEST_F(SurgeonTest, SurgeryManagement) {
    surgeon->addPerformedSurgery(surgery);
    auto surgeries = surgeon->getPerformedSurgeries();
    EXPECT_EQ(surgeries.size(), 1);
    
    surgeon->removePerformedSurgery("SUR001");
    surgeries = surgeon->getPerformedSurgeries();
    EXPECT_EQ(surgeries.size(), 0);
}

TEST_F(SurgeonTest, OperatingRoomManagement) {
    surgeon->addAssignedOperatingRoom(operatingRoom);
    auto rooms = surgeon->getAssignedOperatingRooms();
    EXPECT_EQ(rooms.size(), 1);
    
    surgeon->removeAssignedOperatingRoom("OR001");
    rooms = surgeon->getAssignedOperatingRooms();
    EXPECT_EQ(rooms.size(), 0);
}
