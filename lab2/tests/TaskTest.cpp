#include <gtest/gtest.h>
#include "Task.h"

TEST(TaskTest, CalculateEfficiencyOnTime) {
    Task task("TASK001", "Foundation work", 40);
    task.setActualHours(40);
    double efficiency = task.calculateEfficiency();
    EXPECT_NEAR(efficiency, 1.0, 0.01);
}

TEST(TaskTest, CalculateEfficiencyEarly) {
    Task task("TASK002", "Electrical installation", 60);
    task.setActualHours(50);
    double efficiency = task.calculateEfficiency();
    EXPECT_GT(efficiency, 1.0);
}

TEST(TaskTest, IsOverdueNotStarted) {
    Task task("TASK003", "Plumbing work", 30);
    bool overdue = task.isOverdue();
    EXPECT_FALSE(overdue);
}

TEST(TaskTest, CalculateEfficiencyComplexTask) {
    Task task("TASK004", "complex structural work", 80);
    task.setActualHours(90);
    double efficiency = task.calculateEfficiency();
    EXPECT_LT(efficiency, 1.0);
}

TEST(TaskTest, CalculateEfficiencyCriticalTask) {
    Task task("TASK005", "critical safety inspection", 20);
    task.setActualHours(25);
    bool overdue = task.isOverdue();
    EXPECT_TRUE(overdue);
}

TEST(TaskTest, GetTaskId) {
    Task task("TASK006", "Final inspection", 10);
    EXPECT_EQ(task.getId(), "TASK006");
}
