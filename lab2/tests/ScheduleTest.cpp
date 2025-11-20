#include <gtest/gtest.h>
#include "Schedule.h"

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

TEST(ScheduleTest, CalculateProgressWithFastTrack) {
    Schedule schedule("SCH004", "FAST001", 120);
    schedule.setCompletedDays(60);
    double progress = schedule.calculateProgressPercentage();
    EXPECT_GT(progress, 50.0);
}

TEST(ScheduleTest, CalculateProgressWithComplexProject) {
    Schedule schedule("SCH005", "COMPLEX001", 180);
    schedule.setCompletedDays(90);
    double progress = schedule.calculateProgressPercentage();
    EXPECT_LT(progress, 50.0);
}

TEST(ScheduleTest, GetScheduleId) {
    Schedule schedule("SCH006", "PROJ004", 90);
    EXPECT_EQ(schedule.getId(), "SCH006");
}
