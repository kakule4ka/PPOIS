#include <gtest/gtest.h>
#include "models/Employee.h"
#include "core/ConstructionProject.h"

TEST(EmployeeTest, CalculateProductivityManager) {
    Employee employee("E001", "John Doe", "Manager", 75000);
    double productivity = employee.calculateProductivity();
    EXPECT_GT(productivity, 0);
}

TEST(EmployeeTest, CalculateProductivityWorker) {
    Employee employee("E003", "Bob Wilson", "Construction Worker", 45000);
    double productivity = employee.calculateProductivity();
    EXPECT_GT(productivity, 0);
}

TEST(EmployeeTest, IsEligibleForPromotion) {
    Employee employee("E004", "Alice Brown", "Architect", 60000);
    bool eligible = employee.isEligibleForPromotion();
    EXPECT_TRUE(eligible);
}

TEST(EmployeeTest, CalculateWorkload) {
    Employee employee("E005", "Charlie", "Manager", 70000);
    ConstructionProject project1("P1", "Project 1", 1000000, 12);
    ConstructionProject project2("P2", "Project 2", 2000000, 18);
    
    employee.assignToProject(&project1);
    employee.assignToProject(&project2);
    
    double workload = employee.calculateWorkload();
    EXPECT_GT(workload, 0.0);
}

TEST(EmployeeTest, CanTakeMoreProjects) {
    Employee employee("E006", "Diana", "Architect", 65000);
    bool canTake = employee.canTakeMoreProjects();
    EXPECT_TRUE(canTake);
}

TEST(EmployeeTest, AssignAndGetProjects) {
    Employee employee("E007", "Eve", "Worker", 50000);
    ConstructionProject project1("P1", "Project 1", 1000000, 12);
    
    employee.assignToProject(&project1);
    auto projects = employee.getAssignedProjects();
    EXPECT_EQ(projects.size(), 1);
    EXPECT_EQ(projects[0]->getId(), "P1");
}
