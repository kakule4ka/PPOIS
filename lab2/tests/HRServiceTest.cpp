#include <gtest/gtest.h>
#include "HRService.h"

TEST(HRServiceTest, CalculateWorkforceProductivitySenior) {
    HRService service("SENIOR001", 45, 0.82);
    double productivity = service.calculateWorkforceProductivity();
    EXPECT_EQ(productivity, 82.0);
}

TEST(HRServiceTest, CalculateWorkforceProductivityJunior) {
    HRService service("JUNIOR001", 25, 0.75);
    double productivity = service.calculateWorkforceProductivity();
    EXPECT_EQ(productivity, 75.0);
}

TEST(HRServiceTest, CalculateWorkforceProductivityLargeTeam) {
    HRService service("LARGE001", 150, 0.68);
    double productivity = service.calculateWorkforceProductivity();
    EXPECT_EQ(productivity, 68.0);
}

TEST(HRServiceTest, PlanRecruitmentAvailable) {
    HRService service("FAST001", 60, 0.78);
    bool canRecruit = service.planRecruitment(15);
    EXPECT_TRUE(canRecruit);
}

TEST(HRServiceTest, PlanRecruitmentOverloaded) {
    HRService service("STANDARD001", 120, 0.72);
    bool canRecruit = service.planRecruitment(30);
    EXPECT_FALSE(canRecruit);
}

TEST(HRServiceTest, GetServiceId) {
    HRService service("HR001", 80, 0.79);
    EXPECT_EQ(service.getId(), "HR001");
}
