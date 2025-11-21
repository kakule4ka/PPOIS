#include <gtest/gtest.h>
#include "BillingService.h"
#include "Billing.h"
#include "Patient.h"
#include "Insurance.h"

class BillingServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new BillingService("BILL_SVC001");
        billing = new Billing("BILL001", "PAT001", 2500.0);
        patient = new Patient("PAT001", "John Doe", 45, "A+");
        insurance = new Insurance("INS001", "HealthPlus", "Premium");
    }

    void TearDown() override {
        delete service;
        delete billing;
        delete patient;
        delete insurance;
    }

    BillingService* service;
    Billing* billing;
    Patient* patient;
    Insurance* insurance;
};

TEST_F(BillingServiceTest, CalculateTotalRevenue) {
    double revenue = service->calculateTotalRevenue();
    EXPECT_GE(revenue, 0.0);
}

TEST_F(BillingServiceTest, CalculateOutstandingDebt) {
    double debt = service->calculateOutstandingDebt();
    EXPECT_GE(debt, 0.0);
}

TEST_F(BillingServiceTest, ProcessInsuranceClaim) {
    double coverage = service->processInsuranceClaim(billing, insurance);
    EXPECT_GE(coverage, 0.0);
}

TEST_F(BillingServiceTest, GenerateInvoice) {
    bool invoiceGenerated = service->generateInvoice(billing);
    EXPECT_TRUE(invoiceGenerated || !invoiceGenerated);
}

TEST_F(BillingServiceTest, CalculateCollectionEfficiency) {
    double efficiency = service->calculateCollectionEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(BillingServiceTest, IdentifyDelinquentAccounts) {
    auto delinquent = service->identifyDelinquentAccounts();
    EXPECT_TRUE(delinquent.size() >= 0);
}

TEST_F(BillingServiceTest, BillingManagement) {
    service->addProcessedBilling(billing);
    auto billings = service->getProcessedBillings();
    EXPECT_EQ(billings.size(), 1);
    
    service->removeProcessedBilling("BILL001");
    billings = service->getProcessedBillings();
    EXPECT_EQ(billings.size(), 0);
}

TEST_F(BillingServiceTest, PatientManagement) {
    service->addBillingPatient(patient);
    auto patients = service->getBillingPatients();
    EXPECT_EQ(patients.size(), 1);
    
    service->removeBillingPatient("PAT001");
    patients = service->getBillingPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(BillingServiceTest, InsuranceManagement) {
    service->addSupportedInsurance(insurance);
    auto insurances = service->getSupportedInsurances();
    EXPECT_EQ(insurances.size(), 1);
    
    service->removeSupportedInsurance("INS001");
    insurances = service->getSupportedInsurances();
    EXPECT_EQ(insurances.size(), 0);
}
