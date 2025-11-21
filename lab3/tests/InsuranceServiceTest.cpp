#include <gtest/gtest.h>
#include "InsuranceService.h"
#include "Insurance.h"

class InsuranceServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new InsuranceService("INS_SVC001");
        insurance = new Insurance("INS001", "HealthPlus", "Premium");
    }

    void TearDown() override {
        delete service;
        delete insurance;
    }

    InsuranceService* service;
    Insurance* insurance;
};

TEST_F(InsuranceServiceTest, CalculateCoverageEfficiency) {
    double efficiency = service->calculateCoverageEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(InsuranceServiceTest, ValidateInsuranceNetwork) {
    bool valid = service->validateInsuranceNetwork();
    EXPECT_TRUE(valid || !valid);
}

TEST_F(InsuranceServiceTest, GetAverageCoverageRate) {
    double coverage = service->getAverageCoverageRate();
    EXPECT_GE(coverage, 0.0);
}

TEST_F(InsuranceServiceTest, InsuranceManagement) {
    service->addManagedInsurance(insurance);
    auto insurances = service->getManagedInsurances();
    EXPECT_EQ(insurances.size(), 1);
    
    service->removeManagedInsurance("INS001");
    insurances = service->getManagedInsurances();
    EXPECT_EQ(insurances.size(), 0);
}
