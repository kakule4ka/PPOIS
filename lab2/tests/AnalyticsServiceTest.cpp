#include <gtest/gtest.h>
#include "AnalyticsService.h"

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

TEST(AnalyticsServiceTest, PredictProjectSuccessNo) {
    AnalyticsService service("BASIC001", 3, 0.65);
    bool success = service.predictProjectSuccess();
    EXPECT_FALSE(success);
}

TEST(AnalyticsServiceTest, CalculateBusinessInsightManySources) {
    AnalyticsService service("ADVANCED001", 12, 0.85);
    double insight = service.calculateBusinessInsight();
    EXPECT_EQ(insight, 85.0);
}

TEST(AnalyticsServiceTest, GetServiceId) {
    AnalyticsService service("ANALYTICS003", 5, 0.83);
    EXPECT_EQ(service.getId(), "ANALYTICS003");
}
