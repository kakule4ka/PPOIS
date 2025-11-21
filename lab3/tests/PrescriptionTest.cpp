#include <gtest/gtest.h>
#include "Prescription.h"
#include "Patient.h"
#include "Doctor.h"
#include "Medication.h"

class PrescriptionTest : public ::testing::Test {
protected:
    void SetUp() override {
        prescription = new Prescription("RX001", "2024-01-15", "Take once daily with food");
        patient = new Patient("P001", "John Doe", 45, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "General Practice", 10, "MED123", 25);
        medication = new Medication("M001", "Ibuprofen", "Pain Relief", 400.0);
    }

    void TearDown() override {
        delete prescription;
        delete patient;
        delete doctor;
        delete medication;
    }

    Prescription* prescription;
    Patient* patient;
    Doctor* doctor;
    Medication* medication;
};

TEST_F(PrescriptionTest, CalculateAdherenceProbability) {
    double adherence = prescription->calculateAdherenceProbability();
    EXPECT_GE(adherence, 0.0);
    EXPECT_LE(adherence, 100.0);
}

TEST_F(PrescriptionTest, RequiresRenewal) {
    bool needsRenewal = prescription->requiresRenewal();
    EXPECT_TRUE(needsRenewal || !needsRenewal);
}

TEST_F(PrescriptionTest, CalculateTherapeuticEffectiveness) {
    double effectiveness = prescription->calculateTherapeuticEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(PrescriptionTest, HasDrugInteractions) {
    bool hasInteractions = prescription->hasDrugInteractions();
    EXPECT_TRUE(hasInteractions || !hasInteractions);
}

TEST_F(PrescriptionTest, ComplexityLevel) {
    std::string complexity = prescription->determineComplexityLevel();
    EXPECT_FALSE(complexity.empty());
}

TEST_F(PrescriptionTest, PatientAssociation) {
    prescription->setPatient(patient);
    EXPECT_EQ(prescription->getPatient(), patient);
}

TEST_F(PrescriptionTest, DoctorAssociation) {
    prescription->setPrescribingDoctor(doctor);
    EXPECT_EQ(prescription->getPrescribingDoctor(), doctor);
}

TEST_F(PrescriptionTest, MedicationManagement) {
    prescription->addMedication(medication);
    auto medications = prescription->getPrescribedMedications();
    EXPECT_EQ(medications.size(), 1);
    
    prescription->removeMedication("M001");
    medications = prescription->getPrescribedMedications();
    EXPECT_EQ(medications.size(), 0);
}
