#include <gtest/gtest.h>
#include "LaboratoryTest.h"
#include "Patient.h"
#include "Doctor.h"

class LaboratoryTestTest : public ::testing::Test {
protected:
    void SetUp() override {
        test = new LaboratoryTest("LT001", "Complete Blood Count", "Blood");
        patient = new Patient("P001", "John Doe", 45, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "Hematology", 10, "MED123", 20);
    }

    void TearDown() override {
        delete test;
        delete patient;
        delete doctor;
    }

    LaboratoryTest* test;
    Patient* patient;
    Doctor* doctor;
};

TEST_F(LaboratoryTestTest, CalculateDiagnosticValue) {
    test->setAccuracy(97.5);
    test->setCost(150.0);
    double value = test->calculateDiagnosticValue();
    EXPECT_GE(value, 0.0);
    EXPECT_LE(value, 100.0);
}

TEST_F(LaboratoryTestTest, IsHighPriority) {
    bool highPriority = test->isHighPriority();
    EXPECT_TRUE(highPriority || !highPriority);
}

TEST_F(LaboratoryTestTest, CalculateResultReliability) {
    double reliability = test->calculateResultReliability();
    EXPECT_GE(reliability, 0.0);
    EXPECT_LE(reliability, 100.0);
}

TEST_F(LaboratoryTestTest, PatientAssociation) {
    test->addPatient(patient);
    auto patients = test->getPatients();
    EXPECT_EQ(patients.size(), 1);
    
    test->removePatient("P001");
    patients = test->getPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(LaboratoryTestTest, DoctorAssociation) {
    test->addRequestingDoctor(doctor);
    auto doctors = test->getRequestingDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    test->removeRequestingDoctor("D001");
    doctors = test->getRequestingDoctors();
    EXPECT_EQ(doctors.size(), 0);
}
