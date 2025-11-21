#include <gtest/gtest.h>
#include "ReportingService.h"
#include "ConstructionProject.h"

TEST(ReportingServiceTest, CalculateReportValueHighAccuracy) {
    ReportingService service("REPORT001", 60, 0.95);
    double value = service.calculateReportValue();
    EXPECT_GT(value, 90.0);
}

TEST(ReportingServiceTest, CalculateReportValueLowAccuracy) {
    ReportingService service("REPORT002", 45, 0.78);
    double value = service.calculateReportValue();
    EXPECT_LT(value, 85.0);
}


TEST(ReportingServiceTest, AutomateReportGenerationPoor) {
    ReportingService service("MANUAL001", 15, 0.82);
    bool automated = service.automateReportGeneration();
    EXPECT_FALSE(automated);
}

TEST(ReportingServiceTest, AddAndGetReportedProjects) {
    ReportingService service("REPORT003", 50, 0.87);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addProject(&project1);
    service.addProject(&project2);
    
    auto projects = service.getReportedProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(ReportingServiceTest, GetServiceId) {
    ReportingService service("REPORT004", 50, 0.87);
    EXPECT_EQ(service.getId(), "REPORT004");
}
