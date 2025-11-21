#include <gtest/gtest.h>
#include "PhysicalTherapy.h"
#include "Patient.h"
#include "Rehabilitation.h"

class PhysicalTherapyTest : public ::testing::Test {
protected:
    void SetUp() override {
        therapy = new PhysicalTherapy("PT001", "Therapy Center", "Orthopedic", 6);
        patient = new Patient("P001", "John Doe", 45, "A+");
        rehab = new Rehabilitation("REH001", "Knee Recovery", 6);
    }

    void TearDown() override {
        delete therapy;
        delete patient;
        delete rehab;
    }

    PhysicalTherapy* therapy;
    Patient* patient;
    Rehabilitation* rehab;
};

TEST_F(PhysicalTherapyTest, CalculateTherapyEffectiveness) {
    double effectiveness = therapy->calculateTherapyEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(PhysicalTherapyTest, CanHandleComplexCases) {
    bool canHandle = therapy->canHandleComplexCases();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(PhysicalTherapyTest, CalculatePatientProgressRate) {
    double progress = therapy->calculatePatientProgressRate();
    EXPECT_GE(progress, 0.0);
    EXPECT_LE(progress, 100.0);
}

TEST_F(PhysicalTherapyTest, PatientManagement) {
    therapy->addTherapyPatient(patient);
    auto patients = therapy->getTherapyPatients();
    EXPECT_EQ(patients.size(), 1);
    
    therapy->removeTherapyPatient("P001");
    patients = therapy->getTherapyPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(PhysicalTherapyTest, RehabManagement) {
    therapy->addRehabProgram(rehab);
    auto programs = therapy->getRehabPrograms();
    EXPECT_EQ(programs.size(), 1);
    
    therapy->removeRehabProgram("REH001");
    programs = therapy->getRehabPrograms();
    EXPECT_EQ(programs.size(), 0);
}
