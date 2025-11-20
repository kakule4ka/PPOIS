#include <gtest/gtest.h>
#include "ConstructionProject.h"

TEST(ConstructionProjectTest, CalculateMonthlyCost) {
    ConstructionProject project("P001", "Office Building", 1000000, 12);
    double monthlyCost = project.calculateMonthlyCost();
    EXPECT_NEAR(monthlyCost, 83333.33, 0.01);
}

TEST(ConstructionProjectTest, CalculateMonthlyCostShortDuration) {
    ConstructionProject project("P002", "Small House", 300000, 6);
    double monthlyCost = project.calculateMonthlyCost();
    EXPECT_NEAR(monthlyCost, 50000.0, 0.01);
}

TEST(ConstructionProjectTest, IsOnSchedule) {
    ConstructionProject project("P003", "Residential Complex", 500000, 10);
    bool onSchedule = project.isOnSchedule(5, 240000);
    EXPECT_TRUE(onSchedule);
}

TEST(ConstructionProjectTest, IsBehindSchedule) {
    ConstructionProject project("P004", "Shopping Mall", 800000, 8);
    bool onSchedule = project.isOnSchedule(4, 500000);
    EXPECT_FALSE(onSchedule);
}

TEST(ConstructionProjectTest, IsOnScheduleExact) {
    ConstructionProject project("P005", "Warehouse", 600000, 12);
    bool onSchedule = project.isOnSchedule(6, 300000);
    EXPECT_TRUE(onSchedule);
}

TEST(ConstructionProjectTest, GetProjectId) {
    ConstructionProject project("P006", "Apartment Building", 1200000, 18);
    EXPECT_EQ(project.getId(), "P006");
}
