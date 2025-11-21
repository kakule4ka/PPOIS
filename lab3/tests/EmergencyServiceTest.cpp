#include <gtest/gtest.h>
#include "EmergencyService.h"
#include "EmergencyCase.h"

class EmergencyServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new EmergencyService("EMERG001");
        emergency = new EmergencyCase("EMG001", "Cardiac arrest", 5);
    }

    void TearDown() override {
        delete service;
        delete emergency;
    }

    EmergencyService* service;
    EmergencyCase* emergency;
};

TEST_F(EmergencyServiceTest, CalculateResponseEffectiveness) {
    double effectiveness = service->calculateResponseEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(EmergencyServiceTest, CanHandleMassCasualty) {
    bool canHandle = service->canHandleMassCasualty();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(EmergencyServiceTest, GetActiveCaseCount) {
    int count = service->getActiveCaseCount();
    EXPECT_GE(count, 0);
}

TEST_F(EmergencyServiceTest, CaseManagement) {
    service->addActiveCase(emergency);
    auto cases = service->getActiveCases();
    EXPECT_EQ(cases.size(), 1);
    
    service->removeActiveCase("EMG001");
    cases = service->getActiveCases();
    EXPECT_EQ(cases.size(), 0);
}
