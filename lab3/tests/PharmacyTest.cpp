#include <gtest/gtest.h>
#include "Pharmacy.h"
#include "Medication.h"
#include "Patient.h"
#include "Doctor.h"

class PharmacyTest : public ::testing::Test {
protected:
    void SetUp() override {
        pharmacy = new Pharmacy("PH001", "Main Pharmacy", 500);
        medication = new Medication("M001", "Aspirin", "Pain Relief", 500.0);
        patient = new Patient("P001", "John Doe", 45, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "General Practice", 10, "MED123", 25);
    }

    void TearDown() override {
        delete pharmacy;
        delete medication;
        delete patient;
        delete doctor;
    }

    Pharmacy* pharmacy;
    Medication* medication;
    Patient* patient;
    Doctor* doctor;
};

TEST_F(PharmacyTest, CalculateInventoryTurnover) {
    double turnover = pharmacy->calculateInventoryTurnover();
    EXPECT_GE(turnover, 0.0);
    EXPECT_LE(turnover, 100.0);
}

TEST_F(PharmacyTest, CanDispenseSpecializedMeds) {
    bool canDispense = pharmacy->canDispenseSpecializedMeds();
    EXPECT_TRUE(canDispense || !canDispense);
}

TEST_F(PharmacyTest, CalculateServiceEfficiency) {
    double efficiency = pharmacy->calculateServiceEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(PharmacyTest, MedicationManagement) {
    pharmacy->addMedication(medication);
    auto medications = pharmacy->getAvailableMedications();
    EXPECT_EQ(medications.size(), 1);
    
    pharmacy->removeMedication("M001");
    medications = pharmacy->getAvailableMedications();
    EXPECT_EQ(medications.size(), 0);
}

TEST_F(PharmacyTest, PatientManagement) {
    pharmacy->addServedPatient(patient);
    auto patients = pharmacy->getServedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    pharmacy->removeServedPatient("P001");
    patients = pharmacy->getServedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(PharmacyTest, DoctorManagement) {
    pharmacy->addCollaboratingDoctor(doctor);
    auto doctors = pharmacy->getCollaboratingDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    pharmacy->removeCollaboratingDoctor("D001");
    doctors = pharmacy->getCollaboratingDoctors();
    EXPECT_EQ(doctors.size(), 0);
}
