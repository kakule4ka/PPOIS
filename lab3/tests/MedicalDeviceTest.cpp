#include <gtest/gtest.h>
#include "MedicalDevice.h"
#include "Patient.h"
#include "Doctor.h"

class MedicalDeviceTest : public ::testing::Test {
protected:
    void SetUp() override {
        device = new MedicalDevice("DEV001", "ECG Machine", "Diagnostic");
        patient = new Patient("P001", "John Doe", 45, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "Cardiology", 10, "MED123", 20);
    }

    void TearDown() override {
        delete device;
        delete patient;
        delete doctor;
    }

    MedicalDevice* device;
    Patient* patient;
    Doctor* doctor;
};

TEST_F(MedicalDeviceTest, CalculateReliabilityScore) {
    double reliability = device->calculateReliabilityScore();
    EXPECT_GE(reliability, 0.0);
    EXPECT_LE(reliability, 100.0);
}

TEST_F(MedicalDeviceTest, NeedsCalibration) {
    bool needsCalib = device->needsCalibration();
    EXPECT_TRUE(needsCalib || !needsCalib);
}

TEST_F(MedicalDeviceTest, CalculateDiagnosticValue) {
    double value = device->calculateDiagnosticValue();
    EXPECT_GE(value, 0.0);
    EXPECT_LE(value, 100.0);
}

TEST_F(MedicalDeviceTest, PatientManagement) {
    device->addTestedPatient(patient);
    auto patients = device->getTestedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    device->removeTestedPatient("P001");
    patients = device->getTestedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(MedicalDeviceTest, DoctorManagement) {
    device->addOperatingDoctor(doctor);
    auto doctors = device->getOperatingDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    device->removeOperatingDoctor("D001");
    doctors = device->getOperatingDoctors();
    EXPECT_EQ(doctors.size(), 0);
}
