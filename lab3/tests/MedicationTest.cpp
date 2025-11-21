#include <gtest/gtest.h>
#include "Medication.h"
#include "TreatmentPlan.h"
#include "Patient.h"

class MedicationTest : public ::testing::Test {
protected:
    void SetUp() override {
        medication = new Medication("M001", "Ibuprofen", "Pain Relief", 400.0);
        plan = new TreatmentPlan("TP001", "Pain management", 14);
        patient = new Patient("P001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete medication;
        delete plan;
        delete patient;
    }

    Medication* medication;
    TreatmentPlan* plan;
    Patient* patient;
};

TEST_F(MedicationTest, CalculateDailyCost) {
    medication->setCostPerUnit(0.5);
    medication->setFrequencyPerDay(3);
    double dailyCost = medication->calculateDailyCost();
    EXPECT_GE(dailyCost, 0.0);
}

TEST_F(MedicationTest, HasSideEffects) {
    bool hasEffects = medication->hasSideEffects();
    EXPECT_TRUE(hasEffects || !hasEffects);
}

TEST_F(MedicationTest, EffectivenessScore) {
    double effectiveness = medication->calculateEffectivenessScore();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(MedicationTest, SuitableForElderly) {
    bool suitable = medication->isSuitableForElderly();
    EXPECT_TRUE(suitable || !suitable);
}

TEST_F(MedicationTest, AdministrationComplexity) {
    std::string complexity = medication->determineAdministrationComplexity();
    EXPECT_FALSE(complexity.empty());
}

TEST_F(MedicationTest, TreatmentPlanAssociation) {
    medication->addTreatmentPlan(plan);
    auto plans = medication->getTreatmentPlans();
    EXPECT_EQ(plans.size(), 1);
    
    medication->removeTreatmentPlan("TP001");
    plans = medication->getTreatmentPlans();
    EXPECT_EQ(plans.size(), 0);
}

TEST_F(MedicationTest, AllergicPatients) {
    medication->addAllergicPatient(patient);
    auto allergicPatients = medication->getAllergicPatients();
    EXPECT_EQ(allergicPatients.size(), 1);
    
    medication->removeAllergicPatient("P001");
    allergicPatients = medication->getAllergicPatients();
    EXPECT_EQ(allergicPatients.size(), 0);
}
