#include <gtest/gtest.h>
#include "ReportingService.h"

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

TEST(ReportingServiceTest, CalculateReportValueRealtime) {
    ReportingService service("REALTIME001", 75, 0.89);
    double value = service.calculateReportValue();
    EXPECT_GT(value, 0);
}

TEST(ReportingServiceTest, AutomateReportGenerationGood) {
    ReportingService service("AUTOMATED001", 100, 0.90);
    bool automated = service.automateReportGeneration();
    EXPECT_TRUE(automated);
}

TEST(ReportingServiceTest, AutomateReportGenerationPoor) {
    ReportingService service("MANUAL001", 15, 0.82);
    bool automated = service.automateReportGeneration();
    EXPECT_FALSE(automated);
}

TEST(ReportingServiceTest, GetServiceId) {
    ReportingService service("REPORT003", 50, 0.87);
    EXPECT_EQ(service.getId(), "REPORT003");
}
