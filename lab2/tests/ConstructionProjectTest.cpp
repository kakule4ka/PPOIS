#include <gtest/gtest.h>
#include "ConstructionProject.h"
#include "ProjectManager.h"
#include "Employee.h"
#include "Budget.h"

TEST(ConstructionProjectTest, CalculateMonthlyCost) {
    ConstructionProject project("P001", "Office Building", 1000000, 12);
    double monthlyCost = project.calculateMonthlyCost();
    EXPECT_NEAR(monthlyCost, 83333.33, 0.01);
}

TEST(ConstructionProjectTest, IsOnSchedule) {
    ConstructionProject project("P003", "Residential Complex", 500000, 10);
    bool onSchedule = project.isOnSchedule(5, 240000);
    EXPECT_TRUE(onSchedule);
}

TEST(ConstructionProjectTest, CalculateTeamProductivity) {
    ConstructionProject project("P004", "Test Project", 1000000, 12);
    Employee emp1("E1", "John", "Worker", 50000);
    Employee emp2("E2", "Jane", "Manager", 70000);
    ProjectManager pm("PM1", "Bob", 80000, 2, 1500000);
    
    project.addTeamMember(&emp1);
    project.addTeamMember(&emp2);
    project.setProjectManager(&pm);
    
    double productivity = project.calculateTeamProductivity();
    EXPECT_GT(productivity, 0.0);
}

TEST(ConstructionProjectTest, IsBudgetRealistic) {
    ConstructionProject project("P005", "Realistic Project", 500000, 10);
    Employee emp1("E1", "John", "Worker", 50000);
    project.addTeamMember(&emp1);
    
    bool realistic = project.isBudgetRealistic();
    EXPECT_TRUE(realistic);
}

TEST(ConstructionProjectTest, SetAndGetProjectManager) {
    ConstructionProject project("P006", "Test Project", 1000000, 12);
    ProjectManager pm("PM1", "Bob", 80000, 2, 1500000);
    
    project.setProjectManager(&pm);
    EXPECT_EQ(project.getProjectManager()->getId(), "PM1");
}

TEST(ConstructionProjectTest, AddAndGetTeamMembers) {
    ConstructionProject project("P007", "Team Project", 1500000, 18);
    Employee emp1("E1", "Alice", "Architect", 70000);
    Employee emp2("E2", "Bob", "Engineer", 60000);
    
    project.addTeamMember(&emp1);
    project.addTeamMember(&emp2);
    
    auto team = project.getTeamMembers();
    EXPECT_EQ(team.size(), 2);
}

TEST(ConstructionProjectTest, SetAndGetBudget) {
    ConstructionProject project("P008", "Budget Project", 2000000, 24);
    Budget budget("B1", 2000000);
    
    project.setBudget(&budget);
    EXPECT_EQ(project.getBudget()->getId(), "B1");
}
