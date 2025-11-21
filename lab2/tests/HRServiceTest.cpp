#include <gtest/gtest.h>
#include "HRService.h"
#include "Employee.h"
#include "ConstructionProject.h"

TEST(HRServiceTest, CalculateWorkforceProductivitySenior) {
    HRService service("SENIOR001", 45, 0.82);
    double productivity = service.calculateWorkforceProductivity();
    EXPECT_EQ(productivity, 82.0);
}

TEST(HRServiceTest, CalculateWorkforceProductivityJunior) {
    HRService service("JUNIOR001", 25, 0.75);
    double productivity = service.calculateWorkforceProductivity();
    EXPECT_EQ(productivity, 75.0);
}

TEST(HRServiceTest, PlanRecruitmentAvailable) {
    HRService service("FAST001", 60, 0.78);
    bool canRecruit = service.planRecruitment(15);
    EXPECT_TRUE(canRecruit);
}

TEST(HRServiceTest, CalculateHRServiceEffectiveness) {
    HRService service("HR001", 80, 0.79);
    double effectiveness = service.calculateHRServiceEffectiveness();
    EXPECT_GT(effectiveness, 0.0);
}

TEST(HRServiceTest, NeedsWorkforcePlanning) {
    HRService service("STANDARD001", 120, 0.72);
    bool needsPlanning = service.needsWorkforcePlanning();
    EXPECT_TRUE(needsPlanning);
}

TEST(HRServiceTest, AddAndGetEmployees) {
    HRService service("HR002", 50, 0.85);
    Employee employee1("E1", "John", "Manager", 75000);
    Employee employee2("E2", "Jane", "Architect", 60000);
    
    service.addEmployee(&employee1);
    service.addEmployee(&employee2);
    
    auto employees = service.getEmployees();
    EXPECT_EQ(employees.size(), 2);
}

TEST(HRServiceTest, AddAndGetStaffedProjects) {
    HRService service("HR003", 65, 0.80);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addStaffedProject(&project1);
    service.addStaffedProject(&project2);
    
    auto projects = service.getStaffedProjects();
    EXPECT_EQ(projects.size(), 2);
}
