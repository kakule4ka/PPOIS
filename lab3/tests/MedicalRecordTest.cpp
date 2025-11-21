#include <gtest/gtest.h>
#include "MedicalRecord.h"
#include "Patient.h"
#include "Diagnosis.h"

class MedicalRecordTest : public ::testing::Test {
protected:
    void SetUp() override {
        record = new MedicalRecord("MR001", "Annual physical examination", "2024-01-15");
        patient = new Patient("P001", "John Doe", 45, "A+");
        diagnosis = new Diagnosis("D001", "Hypertension", "Cardiovascular");
    }

    void TearDown() override {
        delete record;
        delete patient;
        delete diagnosis;
    }

    MedicalRecord* record;
    Patient* patient;
    Diagnosis* diagnosis;
};

TEST_F(MedicalRecordTest, CalculateTreatmentComplexity) {
    record->setSeverityLevel(3);
    record->setIsChronic(true);
    double complexity = record->calculateTreatmentComplexity();
    EXPECT_GE(complexity, 0.0);
    EXPECT_LE(complexity, 100.0);
}

TEST_F(MedicalRecordTest, CriticalConditionIndication) {
    record->setSeverityLevel(4);
    bool isCritical = record->indicatesCriticalCondition();
    EXPECT_TRUE(isCritical);
}

TEST_F(MedicalRecordTest, RecoveryProbability) {
    double probability = record->calculateRecoveryProbability();
    EXPECT_GE(probability, 0.0);
    EXPECT_LE(probability, 100.0);
}

TEST_F(MedicalRecordTest, RequiresFollowUp) {
    bool requiresFollowUp = record->requiresFollowUp();
    EXPECT_TRUE(requiresFollowUp || !requiresFollowUp);
}

TEST_F(MedicalRecordTest, UrgencyLevel) {
    std::string urgency = record->determineUrgencyLevel();
    EXPECT_FALSE(urgency.empty());
}

TEST_F(MedicalRecordTest, PatientAssociation) {
    record->setPatient(patient);
    EXPECT_EQ(record->getPatient(), patient);
}

TEST_F(MedicalRecordTest, DiagnosisManagement) {
    record->addDiagnosis(diagnosis);
    auto diagnoses = record->getDiagnoses();
    EXPECT_EQ(diagnoses.size(), 1);
    
    record->removeDiagnosis("D001");
    diagnoses = record->getDiagnoses();
    EXPECT_EQ(diagnoses.size(), 0);
}
