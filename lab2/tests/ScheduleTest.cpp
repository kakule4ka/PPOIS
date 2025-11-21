#include <gtest/gtest.h>
#include "Schedule.h"
#include "ConstructionProject.h"
#include "Task.h"
#include "Milestone.h"

TEST(ScheduleTest, CalculateProgressPercentageZero) {
    Schedule schedule("SCH001", "PROJ001", 100);
    double progress = schedule.calculateProgressPercentage();
    EXPECT_EQ(progress, 0);
}

TEST(ScheduleTest, CalculateProgressPercentageHalf) {
    Schedule schedule("SCH002", "PROJ002", 200);
    schedule.setCompletedDays(100);
    double progress = schedule.calculateProgressPercentage();
    EXPECT_NEAR(progress, 50.0, 0.01);
}

TEST(ScheduleTest, IsAheadOfScheduleAtStart) {
    Schedule schedule("SCH003", "PROJ003", 150);
    bool ahead = schedule.isAheadOfSchedule();
    EXPECT_FALSE(ahead);
}

TEST(ScheduleTest, CalculateCriticalPathDuration) {
    Schedule schedule("SCH004", "PROJ004", 120);
    Task task1("T1", "Task 1", 40);
    Task task2("T2", "Task 2", 30);
    
    schedule.addTask(&task1);
    schedule.addTask(&task2);
    
    double duration = schedule.calculateCriticalPathDuration();
    EXPECT_GT(duration, 0.0);
}

TEST(ScheduleTest, HasScheduleConflicts) {
    Schedule schedule("SCH005", "PROJ005", 180);
    Task task1("T1", "critical task", 20);
    task1.setActualHours(30);
    
    schedule.addTask(&task1);
    
    bool hasConflicts = schedule.hasScheduleConflicts();
    EXPECT_TRUE(hasConflicts);
}

TEST(ScheduleTest, SetAndGetProject) {
    Schedule schedule("SCH006", "PROJ006", 90);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    schedule.setProject(&project);
    EXPECT_EQ(schedule.getProject()->getId(), "P1");
}

TEST(ScheduleTest, AddAndGetTasks) {
    Schedule schedule("SCH007", "PROJ007", 100);
    Task task1("T1", "Task 1", 40);
    Task task2("T2", "Task 2", 30);
    
    schedule.addTask(&task1);
    schedule.addTask(&task2);
    
    auto tasks = schedule.getTasks();
    EXPECT_EQ(tasks.size(), 2);
}

TEST(ScheduleTest, AddAndGetMilestones) {
    Schedule schedule("SCH008", "PROJ008", 120);
    Milestone milestone1("M1", "Foundation Complete", 30);
    Milestone milestone2("M2", "Structure Complete", 60);
    
    schedule.addMilestone(&milestone1);
    schedule.addMilestone(&milestone2);
    
    auto milestones = schedule.getMilestones();
    EXPECT_EQ(milestones.size(), 2);
}
