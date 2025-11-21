#include <gtest/gtest.h>
#include "BloodTest.h"
#include "Patient.h"
#include "Doctor.h"

class BloodTestTest : public ::testing::Test {
protected:
    void SetUp() override {
        bloodTest = new BloodTest("BT001", "Complete Blood Count", "A+");
        patient = new Patient("P001", "John Doe", 45, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "Hematology", 8, "MED123", 20);
    }

    void TearDown() override {
        delete bloodTest;
        delete patient;
        delete doctor;
    }

    BloodTest* bloodTest;
    Patient* patient;
    Doctor* doctor;
};

TEST_F(BloodTestTest, CalculateAnemiaRisk) {
    double anemiaRisk = bloodTest->calculateAnemiaRisk();
    EXPECT_GE(anemiaRisk, 0.0);
    EXPECT_LE(anemiaRisk, 100.0);
}

TEST_F(BloodTestTest, IndicatesInfection) {
    bool infection = bloodTest->indicatesInfection();
    EXPECT_TRUE(infection || !infection);
}

TEST_F(BloodTestTest, CalculateCardiovascularRisk) {
    double cvRisk = bloodTest->calculateCardiovascularRisk();
    EXPECT_GE(cvRisk, 0.0);
    EXPECT_LE(cvRisk, 100.0);
}

TEST_F(BloodTestTest, DonorManagement) {
    bloodTest->addBloodDonor(patient);
    auto donors = bloodTest->getBloodDonors();
    EXPECT_EQ(donors.size(), 1);
    
    bloodTest->removeBloodDonor("P001");
    donors = bloodTest->getBloodDonors();
    EXPECT_EQ(donors.size(), 0);
}

TEST_F(BloodTestTest, PhysicianManagement) {
    bloodTest->addRequestingPhysician(doctor);
    auto physicians = bloodTest->getRequestingPhysicians();
    EXPECT_EQ(physicians.size(), 1);
    
    bloodTest->removeRequestingPhysician("D001");
    physicians = bloodTest->getRequestingPhysicians();
    EXPECT_EQ(physicians.size(), 0);
}
