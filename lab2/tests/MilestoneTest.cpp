#include <gtest/gtest.h>
#include "Milestone.h"

TEST(MilestoneTest, CalculateDaysUntilDeadlineFuture) {
    Milestone milestone("MIL001", "Foundation Complete", 30);
    int days = milestone.calculateDaysUntilDeadline(15);
    EXPECT_EQ(days, 15);
}

TEST(MilestoneTest, CalculateDaysUntilDeadlinePast) {
    Milestone milestone("MIL002", "Structure Complete", 45);
    int days = milestone.calculateDaysUntilDeadline(50);
    EXPECT_EQ(days, -5);
}

TEST(MilestoneTest, CalculateDaysUntilDeadlineToday) {
    Milestone milestone("MIL003", "Roof Complete", 25);
    int days = milestone.calculateDaysUntilDeadline(25);
    EXPECT_EQ(days, 0);
}

TEST(MilestoneTest, IsCriticalPathStructural) {
    Milestone milestone("MIL004", "Foundation Work", 20);
    bool critical = milestone.isCriticalPath();
    EXPECT_TRUE(critical);
}

TEST(MilestoneTest, IsCriticalPathNonStructural) {
    Milestone milestone("MIL005", "Painting Complete", 80);
    bool critical = milestone.isCriticalPath();
    EXPECT_FALSE(critical);
}

TEST(MilestoneTest, GetMilestoneId) {
    Milestone milestone("MIL006", "Project Completion", 100);
    EXPECT_EQ(milestone.getId(), "MIL006");
}
