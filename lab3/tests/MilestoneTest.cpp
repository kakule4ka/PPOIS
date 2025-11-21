#include <gtest/gtest.h>
#include "core/Milestone.h"
#include "core/ConstructionProject.h"
#include "core/Task.h"

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

TEST(MilestoneTest, IsCriticalPathStructural) {
    Milestone milestone("MIL004", "Foundation Work", 20);
    bool critical = milestone.isCriticalPath();
    EXPECT_TRUE(critical);
}

TEST(MilestoneTest, CalculateCompletionProbability) {
    Milestone milestone("MIL005", "Roof Complete", 25);
    double probability = milestone.calculateCompletionProbability();
    EXPECT_GT(probability, 0.0);
}

TEST(MilestoneTest, HasDependenciesCompleted) {
    Milestone milestone("MIL006", "Project Completion", 100);
    bool dependenciesCompleted = milestone.hasDependenciesCompleted();
    EXPECT_TRUE(dependenciesCompleted);
}

TEST(MilestoneTest, SetAndGetProject) {
    Milestone milestone("MIL007", "Test Milestone", 50);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    milestone.setProject(&project);
    EXPECT_EQ(milestone.getProject()->getId(), "P1");
}

TEST(MilestoneTest, AddAndGetDependentTasks) {
    Milestone milestone("MIL008", "Dependent Milestone", 60);
    Task task1("T1", "Task 1", 40);
    Task task2("T2", "Task 2", 30);
    
    milestone.addDependentTask(&task1);
    milestone.addDependentTask(&task2);
    
    auto tasks = milestone.getDependentTasks();
    EXPECT_EQ(tasks.size(), 2);
}
