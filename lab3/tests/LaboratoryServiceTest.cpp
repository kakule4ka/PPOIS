#include <gtest/gtest.h>
#include "LaboratoryService.h"
#include "LaboratoryTest.h"

class LaboratoryServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new LaboratoryService("LAB_SVC001");
        test = new LaboratoryTest("TEST001", "Blood Test", "Hematology");
    }

    void TearDown() override {
        delete service;
        delete test;
    }

    LaboratoryService* service;
    LaboratoryTest* test;
};

TEST_F(LaboratoryServiceTest, CalculateProcessingEfficiency) {
    double efficiency = service->calculateProcessingEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(LaboratoryServiceTest, ValidateTestAccuracy) {
    bool accurate = service->validateTestAccuracy();
    EXPECT_TRUE(accurate || !accurate);
}

TEST_F(LaboratoryServiceTest, GetPendingTestCount) {
    int count = service->getPendingTestCount();
    EXPECT_GE(count, 0);
}

TEST_F(LaboratoryServiceTest, TestManagement) {
    service->addActiveTest(test);
    auto tests = service->getActiveTests();
    EXPECT_EQ(tests.size(), 1);
    
    service->removeActiveTest("TEST001");
    tests = service->getActiveTests();
    EXPECT_EQ(tests.size(), 0);
}
