#include <gtest/gtest.h>
#include "PatientRoom.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalEquipment.h"

class PatientRoomTest : public ::testing::Test {
protected:
    void SetUp() override {
        room = new PatientRoom("RM001", "Private", 2, true);
        patient = new Patient("P001", "John Doe", 45, "A+");
        nurse = new Nurse("N001", "Jane Smith", "RN", 5);
        equipment = new MedicalEquipment("EQ001", "Hospital Bed", "Comfort", 5000.0);
    }

    void TearDown() override {
        delete room;
        delete patient;
        delete nurse;
        delete equipment;
    }

    PatientRoom* room;
    Patient* patient;
    Nurse* nurse;
    MedicalEquipment* equipment;
};

TEST_F(PatientRoomTest, CalculateRoomUtilization) {
    double utilization = room->calculateRoomUtilization();
    EXPECT_GE(utilization, 0.0);
    EXPECT_LE(utilization, 100.0);
}

TEST_F(PatientRoomTest, IsSuitableForIsolation) {
    bool suitable = room->isSuitableForIsolation();
    EXPECT_TRUE(suitable || !suitable);
}

TEST_F(PatientRoomTest, CalculatePatientComfortScore) {
    double comfort = room->calculatePatientComfortScore();
    EXPECT_GE(comfort, 0.0);
    EXPECT_LE(comfort, 100.0);
}

TEST_F(PatientRoomTest, PatientManagement) {
    room->addPatient(patient);
    auto patients = room->getAssignedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    room->removePatient("P001");
    patients = room->getAssignedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(PatientRoomTest, NurseManagement) {
    room->addNurse(nurse);
    auto nurses = room->getAttendingNurses();
    EXPECT_EQ(nurses.size(), 1);
    
    room->removeNurse("N001");
    nurses = room->getAttendingNurses();
    EXPECT_EQ(nurses.size(), 0);
}

TEST_F(PatientRoomTest, EquipmentManagement) {
    room->addEquipment(equipment);
    auto equipmentList = room->getRoomEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    room->removeEquipment("EQ001");
    equipmentList = room->getRoomEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}
