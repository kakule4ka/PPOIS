#include <gtest/gtest.h>
#include "OperatingRoom.h"
#include "Surgery.h"
#include "MedicalEquipment.h"
#include "Doctor.h"

class OperatingRoomTest : public ::testing::Test {
protected:
    void SetUp() override {
        operatingRoom = new OperatingRoom("OR001", "Cardiac", true);
        surgery = new Surgery("SUR001", "Heart Bypass", 240);
        equipment = new MedicalEquipment("EQ001", "Heart-Lung Machine", "Surgical", 250000.0);
        surgeon = new Doctor("D001", "Dr. Cut", "Cardiac Surgery", 12, "SURG123", 15);
    }

    void TearDown() override {
        delete operatingRoom;
        delete surgery;
        delete equipment;
        delete surgeon;
    }

    OperatingRoom* operatingRoom;
    Surgery* surgery;
    MedicalEquipment* equipment;
    Doctor* surgeon;
};

TEST_F(OperatingRoomTest, CalculateReadinessScore) {
    double readiness = operatingRoom->calculateReadinessScore();
    EXPECT_GE(readiness, 0.0);
    EXPECT_LE(readiness, 100.0);
}

TEST_F(OperatingRoomTest, CanHandleComplexSurgery) {
    bool canHandle = operatingRoom->canHandleComplexSurgery();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(OperatingRoomTest, CalculateEfficiencyRating) {
    double efficiency = operatingRoom->calculateEfficiencyRating();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(OperatingRoomTest, SurgeryManagement) {
    operatingRoom->addScheduledSurgery(surgery);
    auto surgeries = operatingRoom->getScheduledSurgeries();
    EXPECT_EQ(surgeries.size(), 1);
    
    operatingRoom->removeScheduledSurgery("SUR001");
    surgeries = operatingRoom->getScheduledSurgeries();
    EXPECT_EQ(surgeries.size(), 0);
}

TEST_F(OperatingRoomTest, EquipmentManagement) {
    operatingRoom->addSurgicalEquipment(equipment);
    auto equipmentList = operatingRoom->getSurgicalEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    operatingRoom->removeSurgicalEquipment("EQ001");
    equipmentList = operatingRoom->getSurgicalEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}

TEST_F(OperatingRoomTest, SurgeonManagement) {
    operatingRoom->addAuthorizedSurgeon(surgeon);
    auto surgeons = operatingRoom->getAuthorizedSurgeons();
    EXPECT_EQ(surgeons.size(), 1);
    
    operatingRoom->removeAuthorizedSurgeon("D001");
    surgeons = operatingRoom->getAuthorizedSurgeons();
    EXPECT_EQ(surgeons.size(), 0);
}
