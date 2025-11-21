#include <gtest/gtest.h>
#include "services/AnalyticsService.h"
#include "core/ConstructionProject.h"
#include "core/RiskAssessment.h"

TEST(AnalyticsServiceTest, CalculateBusinessInsightHigh) {
    AnalyticsService service("ANALYTICS001", 8, 0.92);
    double insight = service.calculateBusinessInsight();
    EXPECT_EQ(insight, 92.0);
}

TEST(AnalyticsServiceTest, CalculateBusinessInsightLow) {
    AnalyticsService service("ANALYTICS002", 2, 0.72);
    double insight = service.calculateBusinessInsight();
    EXPECT_EQ(insight, 72.0);
}

TEST(AnalyticsServiceTest, PredictProjectSuccessYes) {
    AnalyticsService service("ML001", 6, 0.87);
    bool success = service.predictProjectSuccess();
    EXPECT_TRUE(success);
}

TEST(AnalyticsServiceTest, CalculateDataReliability) {
    AnalyticsService service("ANALYTICS003", 5, 0.83);
    double reliability = service.calculateDataReliability();
    EXPECT_GT(reliability, 0.0);
}

TEST(AnalyticsServiceTest, NeedsDataRefresh) {
    AnalyticsService service("ANALYTICS004", 3, 0.70);
    bool needsRefresh = service.needsDataRefresh();
    EXPECT_TRUE(needsRefresh);
}

TEST(AnalyticsServiceTest, AddAndGetMonitoredProjects) {
    AnalyticsService service("ANALYTICS005", 4, 0.85);
    ConstructionProject project1("P1", "Project 1", 1000000, 12);
    ConstructionProject project2("P2", "Project 2", 2000000, 18);
    
    service.addMonitoredProject(&project1);
    service.addMonitoredProject(&project2);
    
    auto projects = service.getMonitoredProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(AnalyticsServiceTest, AddAndGetRiskData) {
    AnalyticsService service("ANALYTICS006", 6, 0.88);
    RiskAssessment assessment1("RA1", "P1", 0.5, "Financial");
    RiskAssessment assessment2("RA2", "P2", 0.3, "Schedule");
    
    service.addRiskData(&assessment1);
    service.addRiskData(&assessment2);
    
    auto riskData = service.getRiskData();
    EXPECT_EQ(riskData.size(), 2);
}
