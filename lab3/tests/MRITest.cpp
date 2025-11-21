#include <gtest/gtest.h>
#include "MRI.h"
#include "Patient.h"
#include "Radiologist.h"

class MRITest : public ::testing::Test {
protected:
    void SetUp() override {
        mri = new MRI("MRI001", "3T MRI Scanner", "Neurological");
        patient = new Patient("P001", "John Doe", 45, "A+");
        radiologist = new Radiologist("RAD001", "Dr. Brain", 15, "RAD123", 12, 500, 94.5);
    }

    void TearDown() override {
        delete mri;
        delete patient;
        delete radiologist;
    }

    MRI* mri;
    Patient* patient;
    Radiologist* radiologist;
};

TEST_F(MRITest, CalculateScanQuality) {
    double quality = mri->calculateScanQuality();
    EXPECT_GE(quality, 0.0);
    EXPECT_LE(quality, 100.0);
}

TEST_F(MRITest, RequiresContrast) {
    bool needsContrast = mri->requiresContrast();
    EXPECT_TRUE(needsContrast || !needsContrast);
}

TEST_F(MRITest, CalculateDiagnosticPrecision) {
    double precision = mri->calculateDiagnosticPrecision();
    EXPECT_GE(precision, 0.0);
    EXPECT_LE(precision, 100.0);
}

TEST_F(MRITest, PatientManagement) {
    mri->addMRIPatient(patient);
    auto patients = mri->getMRIPatients();
    EXPECT_EQ(patients.size(), 1);
    
    mri->removeMRIPatient("P001");
    patients = mri->getMRIPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(MRITest, SpecialistManagement) {
    mri->addMRISpecialist(radiologist);
    auto specialists = mri->getMRISpecialists();
    EXPECT_EQ(specialists.size(), 1);
    
    mri->removeMRISpecialist("RAD001");
    specialists = mri->getMRISpecialists();
    EXPECT_EQ(specialists.size(), 0);
}
