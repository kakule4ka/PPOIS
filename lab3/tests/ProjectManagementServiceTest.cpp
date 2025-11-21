#include <gtest/gtest.h>
#include "services/ProjectManagementService.h"

TEST(ProjectManagementServiceTest, CalculateResourceEfficiencySenior) {
    ProjectManagementService service("SENIOR001", 4, 0.85);
    double efficiency = service.calculateResourceEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(ProjectManagementServiceTest, CalculateResourceEfficiencyJunior) {
    ProjectManagementService service("JUNIOR001", 2, 0.75);
    double efficiency = service.calculateResourceEfficiency();
    EXPECT_GT(efficiency, 0);
}

TEST(ProjectManagementServiceTest, CanTakeNewProjectAvailable) {
    ProjectManagementService service("CERTIFIED001", 3, 0.88);
    bool canTake = service.canTakeNewProject();
    EXPECT_TRUE(canTake);
}

TEST(ProjectManagementServiceTest, CanTakeNewProjectOverloaded) {
    ProjectManagementService service("MANAGER001", 10, 0.82);
    bool canTake = service.canTakeNewProject();
    EXPECT_FALSE(canTake);
}

TEST(ProjectManagementServiceTest, CanTakeNewProjectLowPerformance) {
    ProjectManagementService service("TEAM001", 4, 0.70);
    bool canTake = service.canTakeNewProject();
    EXPECT_FALSE(canTake);
}

TEST(ProjectManagementServiceTest, GetServiceId) {
    ProjectManagementService service("SERVICE001", 5, 0.86);
    EXPECT_EQ(service.getId(), "SERVICE001");
}
