#include <gtest/gtest.h>
#include "ComplianceService.h"

TEST(ComplianceServiceTest, CalculateComplianceRiskLow) {
    ComplianceService service("COMPLY001", 35, 0.95);
    double risk = service.calculateComplianceRisk();
    EXPECT_LT(risk, 10.0);
}

TEST(ComplianceServiceTest, CalculateComplianceRiskHigh) {
    ComplianceService service("HIGH_RISK001", 80, 0.68);
    double risk = service.calculateComplianceRisk();
    EXPECT_GT(risk, 30.0);
}

TEST(ComplianceServiceTest, CalculateComplianceRiskManyRegulations) {
    ComplianceService service("COMPLEX001", 100, 0.79);
    double risk = service.calculateComplianceRisk();
    EXPECT_GE(risk, 0);
}

TEST(ComplianceServiceTest, MonitorRegulatoryChangesYes) {
    ComplianceService service("MONITORING001", 60, 0.92);
    bool monitoring = service.monitorRegulatoryChanges();
    EXPECT_TRUE(monitoring);
}

TEST(ComplianceServiceTest, MonitorRegulatoryChangesNo) {
    ComplianceService service("BASIC001", 12, 0.85);
    bool monitoring = service.monitorRegulatoryChanges();
    EXPECT_FALSE(monitoring);
}

TEST(ComplianceServiceTest, GetServiceId) {
    ComplianceService service("COMPLY002", 45, 0.88);
    EXPECT_EQ(service.getId(), "COMPLY002");
}
