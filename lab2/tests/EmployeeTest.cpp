#include <gtest/gtest.h>
#include "Employee.h"

TEST(EmployeeTest, CalculateProductivityManager) {
    Employee employee("E001", "John Doe", "Manager", 75000);
    double productivity = employee.calculateProductivity();
    EXPECT_GT(productivity, 0);
}

TEST(EmployeeTest, CalculateProductivityArchitect) {
    Employee employee("E002", "Jane Smith", "Architect", 60000);
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

TEST(EmployeeTest, NotEligibleForPromotionHighSalary) {
    Employee employee("E005", "Charlie Green", "Manager", 90000);
    bool eligible = employee.isEligibleForPromotion();
    EXPECT_FALSE(eligible);
}

TEST(EmployeeTest, GetEmployeeId) {
    Employee employee("E006", "Diana White", "Architect", 70000);
    EXPECT_EQ(employee.getId(), "E006");
}
