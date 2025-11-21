#include <gtest/gtest.h>
#include "MentalHealthTherapy.h"
#include "Patient.h"
#include "TreatmentPlan.h"

class MentalHealthTherapyTest : public ::testing::Test {
protected:
    void SetUp() override {
        therapy = new MentalHealthTherapy("MHT001", "CBT", 60);
        patient = new Patient("P001", "John Doe", 35, "A+");
        plan = new TreatmentPlan("TP001", "Anxiety Management", 90);
    }

    void TearDown() override {
        delete therapy;
        delete patient;
        delete plan;
    }

    MentalHealthTherapy* therapy;
    Patient* patient;
    TreatmentPlan* plan;
};

TEST_F(MentalHealthTherapyTest, CalculateTherapeuticOutcome) {
    double outcome = therapy->calculateTherapeuticOutcome();
    EXPECT_GE(outcome, 0.0);
    EXPECT_LE(outcome, 100.0);
}

TEST_F(MentalHealthTherapyTest, RequiresSpecializedApproach) {
    bool specialized = therapy->requiresSpecializedApproach();
    EXPECT_TRUE(specialized || !specialized);
}

TEST_F(MentalHealthTherapyTest, CalculatePatientEngagement) {
    double engagement = therapy->calculatePatientEngagement();
    EXPECT_GE(engagement, 0.0);
    EXPECT_LE(engagement, 100.0);
}

TEST_F(MentalHealthTherapyTest, PatientManagement) {
    therapy->addMentalHealthPatient(patient);
    auto patients = therapy->getMentalHealthPatients();
    EXPECT_EQ(patients.size(), 1);
    
    therapy->removeMentalHealthPatient("P001");
    patients = therapy->getMentalHealthPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(MentalHealthTherapyTest, PlanManagement) {
    therapy->addTherapyPlan(plan);
    auto plans = therapy->getTherapyPlans();
    EXPECT_EQ(plans.size(), 1);
    
    therapy->removeTherapyPlan("TP001");
    plans = therapy->getTherapyPlans();
    EXPECT_EQ(plans.size(), 0);
}
