#include <gtest/gtest.h>
#include "services/QualityControlService.h"
#include "core/QualityStandard.h"

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


TEST(QualityControlServiceTest, DetectQualityTrendPoor) {
    QualityControlService service("BASIC001", 40, 0.15);
    bool trend = service.detectQualityTrend();
    EXPECT_FALSE(trend);
}

TEST(QualityControlServiceTest, AddAndGetEnforcedStandards) {
    QualityControlService service("QC003", 150, 0.05);
    QualityStandard standard1("QS1", "Structural", "Structural", 30.0);
    QualityStandard standard2("QS2", "Electrical", "Electrical", 220.0);
    
    service.addStandard(&standard1);
    service.addStandard(&standard2);
    
    auto standards = service.getEnforcedStandards();
    EXPECT_EQ(standards.size(), 2);
}

TEST(QualityControlServiceTest, GetServiceId) {
    QualityControlService service("QC004", 150, 0.05);
    EXPECT_EQ(service.getId(), "QC004");
}
