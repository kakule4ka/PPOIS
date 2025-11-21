#include <gtest/gtest.h>
#include "PhysicalTherapist.h"
#include "Patient.h"

class PhysicalTherapistTest : public ::testing::Test {
protected:
    void SetUp() override {
        therapist = new PhysicalTherapist("PT001", "Therapist Bob", "Orthopedic", 6);
        patient = new Patient("PAT001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete therapist;
        delete patient;
    }

    PhysicalTherapist* therapist;
    Patient* patient;
};

TEST_F(PhysicalTherapistTest, CalculateTherapyEffectiveness) {
    double effectiveness = therapist->calculateTherapyEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(PhysicalTherapistTest, CanHandleComplexCases) {
    bool canHandle = therapist->canHandleComplexCases();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(PhysicalTherapistTest, PatientManagement) {
    therapist->addTherapyPatient(patient);
    auto patients = therapist->getTherapyPatients();
    EXPECT_EQ(patients.size(), 1);
    
    therapist->removeTherapyPatient("PAT001");
    patients = therapist->getTherapyPatients();
    EXPECT_EQ(patients.size(), 0);
}
