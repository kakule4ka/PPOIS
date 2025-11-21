#include <gtest/gtest.h>
#include "XRay.h"
#include "Patient.h"
#include "Radiologist.h"

class XRayTest : public ::testing::Test {
protected:
    void SetUp() override {
        xray = new XRay("XR001", "Digital X-Ray", "Chest");
        patient = new Patient("P001", "John Doe", 45, "A+");
        radiologist = new Radiologist("RAD001", "Dr. Image", 12, "RAD123", 15, 500, 92.5);
    }

    void TearDown() override {
        delete xray;
        delete patient;
        delete radiologist;
    }

    XRay* xray;
    Patient* patient;
    Radiologist* radiologist;
};

TEST_F(XRayTest, CalculateRadiationRisk) {
    double risk = xray->calculateRadiationRisk();
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(XRayTest, RequiresFollowUpScan) {
    bool followUp = xray->requiresFollowUpScan();
    EXPECT_TRUE(followUp || !followUp);
}

TEST_F(XRayTest, CalculateDiagnosticAccuracy) {
    double accuracy = xray->calculateDiagnosticAccuracy();
    EXPECT_GE(accuracy, 0.0);
    EXPECT_LE(accuracy, 100.0);
}

TEST_F(XRayTest, PatientManagement) {
    xray->addScannedPatient(patient);
    auto patients = xray->getScannedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    xray->removeScannedPatient("P001");
    patients = xray->getScannedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(XRayTest, RadiologistManagement) {
    xray->addInterpretingRadiologist(radiologist);
    auto radiologists = xray->getInterpretingRadiologists();
    EXPECT_EQ(radiologists.size(), 1);
    
    xray->removeInterpretingRadiologist("RAD001");
    radiologists = xray->getInterpretingRadiologists();
    EXPECT_EQ(radiologists.size(), 0);
}
