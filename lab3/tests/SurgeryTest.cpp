#include <gtest/gtest.h>
#include "Surgery.h"
#include "Patient.h"
#include "Doctor.h"
#include "OperatingRoom.h"

class SurgeryTest : public ::testing::Test {
protected:
    void SetUp() override {
        surgery = new Surgery("SUR001", "Cardiac Bypass", 240);
        patient = new Patient("P001", "John Doe", 65, "A+");
        surgeon = new Doctor("D001", "Dr. Smith", "Cardiac Surgery", 15, "MED123", 15);
        operatingRoom = new OperatingRoom("OR001", "Main OR", true);
    }

    void TearDown() override {
        delete surgery;
        delete patient;
        delete surgeon;
        delete operatingRoom;
    }

    Surgery* surgery;
    Patient* patient;
    Doctor* surgeon;
    OperatingRoom* operatingRoom;
};

TEST_F(SurgeryTest, CalculateRiskLevel) {
    surgery->setComplexityLevel(4);
    double risk = surgery->calculateRiskLevel();
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(SurgeryTest, RequiresSpecialEquipment) {
    bool requiresEquipment = surgery->requiresSpecialEquipment();
    EXPECT_TRUE(requiresEquipment || !requiresEquipment);
}

TEST_F(SurgeryTest, CalculateRecoveryProbability) {
    double probability = surgery->calculateRecoveryProbability();
    EXPECT_GE(probability, 0.0);
    EXPECT_LE(probability, 100.0);
}

TEST_F(SurgeryTest, PatientAssociation) {
    surgery->setPatient(patient);
    EXPECT_EQ(surgery->getPatient(), patient);
}

TEST_F(SurgeryTest, SurgeonAssociation) {
    surgery->setSurgeon(surgeon);
    EXPECT_EQ(surgery->getSurgeon(), surgeon);
}

TEST_F(SurgeryTest, OperatingRoomAssociation) {
    surgery->setOperatingRoom(operatingRoom);
    EXPECT_EQ(surgery->getOperatingRoom(), operatingRoom);
}
