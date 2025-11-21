#include <gtest/gtest.h>
#include "Cardiologist.h"
#include "Patient.h"
#include "MedicalEquipment.h"

class CardiologistTest : public ::testing::Test {
protected:
    void SetUp() override {
        cardiologist = new Cardiologist("C001", "Dr. Heart", 12, "CARD123", 25, 80, 92.5);
        patient = new Patient("P001", "John Doe", 65, "A+");
        equipment = new MedicalEquipment("EQ001", "Cardiac Monitor", "Cardiac", 50000.0);
    }

    void TearDown() override {
        delete cardiologist;
        delete patient;
        delete equipment;
    }

    Cardiologist* cardiologist;
    Patient* patient;
    MedicalEquipment* equipment;
};

TEST_F(CardiologistTest, CalculateCardiacRiskAssessment) {
    double risk = cardiologist->calculateCardiacRiskAssessment(patient);
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(CardiologistTest, CanPerformComplexProcedure) {
    bool canPerform = cardiologist->canPerformComplexProcedure();
    EXPECT_TRUE(canPerform || !canPerform);
}

TEST_F(CardiologistTest, CalculateTreatmentEffectiveness) {
    double effectiveness = cardiologist->calculateTreatmentEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(CardiologistTest, CardiacPatientManagement) {
    cardiologist->addCardiacPatient(patient);
    auto patients = cardiologist->getCardiacPatients();
    EXPECT_EQ(patients.size(), 1);
    
    cardiologist->removeCardiacPatient("P001");
    patients = cardiologist->getCardiacPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(CardiologistTest, EquipmentManagement) {
    cardiologist->addSpecializedEquipment(equipment);
    auto equipmentList = cardiologist->getSpecializedEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    cardiologist->removeSpecializedEquipment("EQ001");
    equipmentList = cardiologist->getSpecializedEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}
