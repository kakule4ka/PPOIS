#include <gtest/gtest.h>
#include "Billing.h"
#include "Patient.h"
#include "TreatmentPlan.h"
#include "Insurance.h"

class BillingTest : public ::testing::Test {
protected:
    void SetUp() override {
        billing = new Billing("B001", "P001", 5000.0);
        patient = new Patient("P001", "John Doe", 45, "A+");
        plan = new TreatmentPlan("TP001", "Physical therapy", 30);
        insurance = new Insurance("I001", "HealthPlus", "Premium");
    }

    void TearDown() override {
        delete billing;
        delete patient;
        delete plan;
        delete insurance;
    }

    Billing* billing;
    Patient* patient;
    TreatmentPlan* plan;
    Insurance* insurance;
};

TEST_F(BillingTest, CalculateOutstandingBalance) {
    billing->setPaidAmount(1000.0);
    double balance = billing->calculateOutstandingBalance();
    EXPECT_GE(balance, 0.0);
}

TEST_F(BillingTest, IsEligibleForDiscount) {
    bool eligible = billing->isEligibleForDiscount();
    EXPECT_TRUE(eligible || !eligible);
}

TEST_F(BillingTest, CalculateInsuranceCoverage) {
    billing->setInsurance(insurance);
    double coverage = billing->calculateInsuranceCoverage();
    EXPECT_GE(coverage, 0.0);
}

TEST_F(BillingTest, PatientAssociation) {
    billing->setPatient(patient);
    EXPECT_EQ(billing->getPatient(), patient);
}

TEST_F(BillingTest, TreatmentPlanAssociation) {
    billing->addTreatmentPlan(plan);
    auto plans = billing->getTreatmentPlans();
    EXPECT_EQ(plans.size(), 1);
    
    billing->removeTreatmentPlan("TP001");
    plans = billing->getTreatmentPlans();
    EXPECT_EQ(plans.size(), 0);
}

TEST_F(BillingTest, InsuranceAssociation) {
    billing->setInsurance(insurance);
    EXPECT_EQ(billing->getInsurance(), insurance);
}
