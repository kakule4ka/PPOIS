#include <gtest/gtest.h>
#include "ConstructionWorker.h"

TEST(ConstructionWorkerTest, CalculateWorkEfficiency) {
    ConstructionWorker worker("W001", "Mike Johnson", 45000, "Carpenter", 2000);
    double efficiency = worker.calculateWorkEfficiency();
    EXPECT_GE(efficiency, 0);
}

TEST(ConstructionWorkerTest, IsQualifiedForTaskSameTrade) {
    ConstructionWorker worker("W002", "Sarah Davis", 42000, "Electrician", 1500);
    bool qualified = worker.isQualifiedForTask("Electrician");
    EXPECT_TRUE(qualified);
}

TEST(ConstructionWorkerTest, IsQualifiedForTaskDifferentTrade) {
    ConstructionWorker worker("W003", "Tom Wilson", 48000, "Plumber", 1800);
    bool qualified = worker.isQualifiedForTask("Electrical");
    EXPECT_FALSE(qualified);
}

TEST(ConstructionWorkerTest, IsQualifiedForTaskGeneralWorker) {
    ConstructionWorker worker("W004", "Alex Taylor", 40000, "General", 1200);
    bool qualified = worker.isQualifiedForTask("Any task");
    EXPECT_TRUE(qualified);
}

TEST(ConstructionWorkerTest, GetWorkerId) {
    ConstructionWorker worker("W005", "Chris Lee", 46000, "Welder", 1600);
    EXPECT_EQ(worker.getId(), "W005");
}
