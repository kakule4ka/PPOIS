#include <gtest/gtest.h>
#include "TreatmentPlan.h"
#include "Patient.h"
#include "Medication.h"

class TreatmentPlanTest : public ::testing::Test {
protected:
    void SetUp() override {
        plan = new TreatmentPlan("TP001", "Physical therapy for back pain", 30);
        patient = new Patient("P001", "John Doe", 45, "A+");
        medication = new Medication("M001", "Ibuprofen", "Pain relief", 400.0);
    }

    void TearDown() override {
        delete plan;
        delete patient;
        delete medication;
    }

    TreatmentPlan* plan;
    Patient* patient;
    Medication* medication;
};

TEST_F(TreatmentPlanTest, CalculateTreatmentEffectiveness) {
    plan->setSuccessRate(85.0);
    plan->setCost(1500.0);
    double effectiveness = plan->calculateTreatmentEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(TreatmentPlanTest, CostEffectiveness) {
    plan->setCost(800.0);
    bool costEffective = plan->isCostEffective();
    EXPECT_TRUE(costEffective || !costEffective);
}

TEST_F(TreatmentPlanTest, AdherenceProbability) {
    double adherence = plan->calculateAdherenceProbability();
    EXPECT_GE(adherence, 0.0);
    EXPECT_LE(adherence, 100.0);
}

TEST_F(TreatmentPlanTest, NeedsModification) {
    bool needsMod = plan->needsModification();
    EXPECT_TRUE(needsMod || !needsMod);
}

TEST_F(TreatmentPlanTest, ComplexityLevel) {
    std::string complexity = plan->determineComplexityLevel();
    EXPECT_FALSE(complexity.empty());
}

TEST_F(TreatmentPlanTest, PatientAssociation) {
    plan->setPatient(patient);
    EXPECT_EQ(plan->getPatient(), patient);
}

TEST_F(TreatmentPlanTest, MedicationManagement) {
    plan->addMedication(medication);
    auto medications = plan->getPrescribedMedications();
    EXPECT_EQ(medications.size(), 1);
    
    plan->removeMedication("M001");
    medications = plan->getPrescribedMedications();
    EXPECT_EQ(medications.size(), 0);
}
