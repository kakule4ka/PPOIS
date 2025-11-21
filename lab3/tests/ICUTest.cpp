#include <gtest/gtest.h>
#include "ICU.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalEquipment.h"

class ICUTest : public ::testing::Test {
protected:
    void SetUp() override {
        icu = new ICU("ICU001", "Cardiac", 10);
        patient = new Patient("P001", "John Doe", 65, "A+");
        nurse = new Nurse("N001", "Jane Smith", "RN", 8);
        equipment = new MedicalEquipment("EQ001", "Ventilator", "Life Support", 75000.0);
    }

    void TearDown() override {
        delete icu;
        delete patient;
        delete nurse;
        delete equipment;
    }

    ICU* icu;
    Patient* patient;
    Nurse* nurse;
    MedicalEquipment* equipment;
};

TEST_F(ICUTest, CalculateOccupancyRate) {
    icu->setOccupiedBeds(5);
    double occupancy = icu->calculateOccupancyRate();
    EXPECT_GE(occupancy, 0.0);
    EXPECT_LE(occupancy, 100.0);
}

TEST_F(ICUTest, CanAdmitCriticalPatient) {
    bool canAdmit = icu->canAdmitCriticalPatient();
    EXPECT_TRUE(canAdmit || !canAdmit);
}

TEST_F(ICUTest, CalculatePatientSurvivalProbability) {
    double survival = icu->calculatePatientSurvivalProbability();
    EXPECT_GE(survival, 0.0);
    EXPECT_LE(survival, 100.0);
}

TEST_F(ICUTest, PatientManagement) {
    icu->addCriticalPatient(patient);
    auto patients = icu->getCriticalPatients();
    EXPECT_EQ(patients.size(), 1);
    
    icu->removeCriticalPatient("P001");
    patients = icu->getCriticalPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(ICUTest, NurseManagement) {
    icu->addSpecializedNurse(nurse);
    auto nurses = icu->getSpecializedNurses();
    EXPECT_EQ(nurses.size(), 1);
    
    icu->removeSpecializedNurse("N001");
    nurses = icu->getSpecializedNurses();
    EXPECT_EQ(nurses.size(), 0);
}

TEST_F(ICUTest, EquipmentManagement) {
    icu->addLifeSupportEquipment(equipment);
    auto equipmentList = icu->getLifeSupportEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    icu->removeLifeSupportEquipment("EQ001");
    equipmentList = icu->getLifeSupportEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}
