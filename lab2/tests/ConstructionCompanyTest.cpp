#include <gtest/gtest.h>
#include "core/ConstructionCompany.h"
#include "core/ConstructionProject.h"
#include "models/Employee.h"

TEST(ConstructionCompanyTest, CalculateMaxProjectCapacityOldCompany) {
    ConstructionCompany company("Old Corp", "CONST12345", 1995);
    double capacity = company.calculateMaxProjectCapacity();
    EXPECT_EQ(capacity, 10000000.0);
}

TEST(ConstructionCompanyTest, CalculateMaxProjectCapacityNewCompany) {
    ConstructionCompany company("New Corp", "CONST67890", 2020);
    double capacity = company.calculateMaxProjectCapacity();
    EXPECT_EQ(capacity, 5000000.0);
}

TEST(ConstructionCompanyTest, VerifyLicenseValid) {
    ConstructionCompany company("Test Corp", "CONST12345", 2020);
    bool isValid = company.verifyLicense();
    EXPECT_TRUE(isValid);
}

TEST(ConstructionCompanyTest, CalculateTotalWorkforceCapacity) {
    ConstructionCompany company("Test Corp", "CONST12345", 2005);
    Employee emp1("E1", "John", "Worker", 50000);
    Employee emp2("E2", "Jane", "Manager", 70000);
    
    company.addEmployee(&emp1);
    company.addEmployee(&emp2);
    
    double capacity = company.calculateTotalWorkforceCapacity();
    EXPECT_GT(capacity, 20000.0);
}


TEST(ConstructionCompanyTest, CannotHandleProjectExceedingCapacity) {
    ConstructionCompany company("Test Corp", "CONST12345", 2020);
    bool canHandle = company.canHandleProject(6000000, 12);
    EXPECT_FALSE(canHandle);
}

TEST(ConstructionCompanyTest, AddAndGetProjects) {
    ConstructionCompany company("Test Corp", "CONST12345", 2020);
    ConstructionProject project1("P1", "Project 1", 1000000, 12);
    ConstructionProject project2("P2", "Project 2", 2000000, 18);
    
    company.addProject(&project1);
    company.addProject(&project2);
    
    auto projects = company.getProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(ConstructionCompanyTest, AddAndGetEmployees) {
    ConstructionCompany company("Test Corp", "CONST12345", 2020);
    Employee emp1("E1", "John", "Worker", 50000);
    Employee emp2("E2", "Jane", "Manager", 70000);
    
    company.addEmployee(&emp1);
    company.addEmployee(&emp2);
    
    auto employees = company.getEmployees();
    EXPECT_EQ(employees.size(), 2);
}
