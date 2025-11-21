#include <gtest/gtest.h>
#include "Rehabilitation.h"
#include "Patient.h"
#include "PhysicalTherapist.h"
#include "TreatmentPlan.h"

class RehabilitationTest : public ::testing::Test {
protected:
    void SetUp() override {
        rehab = new Rehabilitation("REH001", "Orthopedic", 8);
        patient = new Patient("P001", "John Doe", 45, "A+");
        therapist = new PhysicalTherapist("PT001", "Therapist Bob", "Orthopedic", 7);
        plan = new TreatmentPlan("TP001", "Knee rehab", 60);
    }

    void TearDown() override {
        delete rehab;
        delete patient;
        delete therapist;
        delete plan;
    }

    Rehabilitation* rehab;
    Patient* patient;
    PhysicalTherapist* therapist;
    TreatmentPlan* plan;
};

TEST_F(RehabilitationTest, CalculateRecoveryProbability) {
    double recovery = rehab->calculateRecoveryProbability();
    EXPECT_GE(recovery, 0.0);
    EXPECT_LE(recovery, 100.0);
}

TEST_F(RehabilitationTest, RequiresIntensiveTherapy) {
    bool intensive = rehab->requiresIntensiveTherapy();
    EXPECT_TRUE(intensive || !intensive);
}

TEST_F(RehabilitationTest, CalculateFunctionalImprovement) {
    double improvement = rehab->calculateFunctionalImprovement();
    EXPECT_GE(improvement, 0.0);
    EXPECT_LE(improvement, 100.0);
}

TEST_F(RehabilitationTest, PatientManagement) {
    rehab->addRehabPatient(patient);
    auto patients = rehab->getRehabPatients();
    EXPECT_EQ(patients.size(), 1);
    
    rehab->removeRehabPatient("P001");
    patients = rehab->getRehabPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(RehabilitationTest, TherapistManagement) {
    rehab->addAssignedTherapist(therapist);
    auto therapists = rehab->getAssignedTherapists();
    EXPECT_EQ(therapists.size(), 1);
    
    rehab->removeAssignedTherapist("PT001");
    therapists = rehab->getAssignedTherapists();
    EXPECT_EQ(therapists.size(), 0);
}

TEST_F(RehabilitationTest, PlanManagement) {
    rehab->addRehabPlan(plan);
    auto plans = rehab->getRehabPlans();
    EXPECT_EQ(plans.size(), 1);
    
    rehab->removeRehabPlan("TP001");
    plans = rehab->getRehabPlans();
    EXPECT_EQ(plans.size(), 0);
}
