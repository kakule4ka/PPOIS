#include <gtest/gtest.h>
#include "QualityControlService.h"

TEST(QualityControlServiceTest, CalculateQualityIndexHigh) {
    QualityControlService service("QC001", 85, 0.03);
    double index = service.calculateQualityIndex();
    EXPECT_EQ(index, 97.0);
}

TEST(QualityControlServiceTest, CalculateQualityIndexLow) {
    QualityControlService service("QC002", 120, 0.12);
    double index = service.calculateQualityIndex();
    EXPECT_EQ(index, 88.0);
}

TEST(QualityControlServiceTest, DetectQualityTrendGood) {
    QualityControlService service("ADVANCED001", 200, 0.02);
    bool trend = service.detectQualityTrend();
    EXPECT_TRUE(trend);
}

TEST(QualityControlServiceTest, DetectQualityTrendPoor) {
    QualityControlService service("BASIC001", 40, 0.15);
    bool trend = service.detectQualityTrend();
    EXPECT_FALSE(trend);
}

TEST(QualityControlServiceTest, CalculateQualityIndexManyInspections) {
    QualityControlService service("QC003", 300, 0.04);
    double index = service.calculateQualityIndex();
    EXPECT_EQ(index, 96.0);
}

TEST(QualityControlServiceTest, GetServiceId) {
    QualityControlService service("QC004", 150, 0.05);
    EXPECT_EQ(service.getId(), "QC004");
}
