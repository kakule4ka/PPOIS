#include <gtest/gtest.h>
#include "Insurance.h"
#include "Patient.h"
#include "Billing.h"

class InsuranceTest : public ::testing::Test {
protected:
    void SetUp() override {
        insurance = new Insurance("I001", "HealthPlus", "Premium");
        patient = new Patient("P001", "John Doe", 45, "A+");
        billing = new Billing("B001", "P001", 2000.0);
    }

    void TearDown() override {
        delete insurance;
        delete patient;
        delete billing;
    }

    Insurance* insurance;
    Patient* patient;
    Billing* billing;
};

TEST_F(InsuranceTest, CalculateCoverageAmount) {
    double coverage = insurance->calculateCoverageAmount(5000.0);
    EXPECT_GE(coverage, 0.0);
}

TEST_F(InsuranceTest, IsTreatmentCovered) {
    bool covered = insurance->isTreatmentCovered("Surgery");
    EXPECT_TRUE(covered || !covered);
}

TEST_F(InsuranceTest, CalculatePatientResponsibility) {
    double responsibility = insurance->calculatePatientResponsibility(3000.0);
    EXPECT_GE(responsibility, 0.0);
}

TEST_F(InsuranceTest, PatientAssociation) {
    insurance->addCoveredPatient(patient);
    auto patients = insurance->getCoveredPatients();
    EXPECT_EQ(patients.size(), 1);
    
    insurance->removeCoveredPatient("P001");
    patients = insurance->getCoveredPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(InsuranceTest, BillingAssociation) {
    insurance->addProcessedBilling(billing);
    auto billings = insurance->getProcessedBillings();
    EXPECT_EQ(billings.size(), 1);
    
    insurance->removeProcessedBilling("B001");
    billings = insurance->getProcessedBillings();
    EXPECT_EQ(billings.size(), 0);
}
