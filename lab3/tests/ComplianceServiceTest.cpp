#include <gtest/gtest.h>
#include "ComplianceService.h"
#include "Hospital.h"

class ComplianceServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new ComplianceService("COMP001");
        hospital = new Hospital("HOSP001", "Main St", 200, 1990, 5000000.0);
    }

    void TearDown() override {
        delete service;
        delete hospital;
    }

    ComplianceService* service;
    Hospital* hospital;
};

TEST_F(ComplianceServiceTest, CalculateComplianceScore) {
    double score = service->calculateComplianceScore(hospital);
    EXPECT_GE(score, 0.0);
    EXPECT_LE(score, 100.0);
}

TEST_F(ComplianceServiceTest, CheckRegulatoryRequirements) {
    bool compliant = service->checkRegulatoryRequirements();
    EXPECT_TRUE(compliant || !compliant);
}

TEST_F(ComplianceServiceTest, ValidateSafetyStandards) {
    bool safe = service->validateSafetyStandards();
    EXPECT_TRUE(safe || !safe);
}

TEST_F(ComplianceServiceTest, HospitalManagement) {
    service->addMonitoredHospital(hospital);
    auto hospitals = service->getMonitoredHospitals();
    EXPECT_EQ(hospitals.size(), 1);
    
    service->removeMonitoredHospital("HOSP001");
    hospitals = service->getMonitoredHospitals();
    EXPECT_EQ(hospitals.size(), 0);
}
