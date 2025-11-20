#include <gtest/gtest.h>
#include "ConstructionSite.h"

TEST(ConstructionSiteTest, ValidateWorkerCapacityOptimal) {
    ConstructionSite site("S001", "Downtown", 5000, 50);
    bool valid = site.validateWorkerCapacity(40);
    EXPECT_TRUE(valid);
}

TEST(ConstructionSiteTest, ValidateWorkerCapacityMinimum) {
    ConstructionSite site("S002", "Suburb", 3000, 30);
    bool valid = site.validateWorkerCapacity(18);
    EXPECT_TRUE(valid);
}

TEST(ConstructionSiteTest, ExceedWorkerCapacity) {
    ConstructionSite site("S003", "Industrial Zone", 10000, 100);
    bool valid = site.validateWorkerCapacity(120);
    EXPECT_FALSE(valid);
}

TEST(ConstructionSiteTest, CalculatePreparationTimeSmall) {
    ConstructionSite site("S004", "Residential Area", 2000, 20);
    double time = site.calculatePreparationTime();
    EXPECT_NEAR(time, 150.0, 0.01);
}

TEST(ConstructionSiteTest, CalculatePreparationTimeLarge) {
    ConstructionSite site("S005", "Commercial District", 15000, 100);
    double time = site.calculatePreparationTime();
    EXPECT_NEAR(time, 1000.0, 0.01);
}

TEST(ConstructionSiteTest, GetSiteId) {
    ConstructionSite site("S006", "Waterfront", 8000, 80);
    EXPECT_EQ(site.getId(), "S006");
}
