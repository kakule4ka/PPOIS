#include <gtest/gtest.h>
#include "ConstructionWorker.h"
#include "Task.h"
#include "SafetyProtocol.h"

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

TEST(ConstructionWorkerTest, CalculateSafetyCompliance) {
    ConstructionWorker worker("W003", "Tom Wilson", 48000, "Plumber", 1800);
    double compliance = worker.calculateSafetyCompliance();
    EXPECT_GT(compliance, 0.0);
}

TEST(ConstructionWorkerTest, CanWorkOvertime) {
    ConstructionWorker worker("W004", "Alex Taylor", 40000, "General", 1200);
    bool canOvertime = worker.canWorkOvertime();
    EXPECT_TRUE(canOvertime);
}

TEST(ConstructionWorkerTest, AssignAndGetTasks) {
    ConstructionWorker worker("W005", "Chris Lee", 46000, "Welder", 1600);
    Task task("T1", "welding work", 40);
    
    worker.assignTask(&task);
    auto tasks = worker.getAssignedTasks();
    EXPECT_EQ(tasks.size(), 1);
}

TEST(ConstructionWorkerTest, SetAndGetSafetyTraining) {
    ConstructionWorker worker("W006", "David Brown", 44000, "Electrician", 1400);
    SafetyProtocol protocol("SP1", "Electrical Safety", 20, true);
    
    worker.setSafetyTraining(&protocol);
    EXPECT_EQ(worker.getSafetyTraining()->getId(), "SP1");
}
