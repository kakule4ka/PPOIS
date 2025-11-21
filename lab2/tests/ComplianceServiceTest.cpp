#include <gtest/gtest.h>
#include "ComplianceService.h"
#include "ConstructionProject.h"
#include "QualityStandard.h"

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

TEST(ComplianceServiceTest, MonitorRegulatoryChangesYes) {
    ComplianceService service("MONITORING001", 60, 0.92);
    bool monitoring = service.monitorRegulatoryChanges();
    EXPECT_TRUE(monitoring);
}

TEST(ComplianceServiceTest, CalculateServiceEfficiency) {
    ComplianceService service("COMPLY002", 45, 0.88);
    double efficiency = service.calculateServiceEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(ComplianceServiceTest, RequiresAudit) {
    ComplianceService service("BASIC001", 12, 0.75);
    bool needsAudit = service.requiresAudit();
    EXPECT_TRUE(needsAudit);
}

TEST(ComplianceServiceTest, AddAndGetMonitoredProjects) {
    ComplianceService service("COMPLY003", 40, 0.90);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addMonitoredProject(&project1);
    service.addMonitoredProject(&project2);
    
    auto projects = service.getMonitoredProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(ComplianceServiceTest, AddAndGetApplicableStandards) {
    ComplianceService service("COMPLY004", 50, 0.85);
    QualityStandard standard1("QS1", "Structural", "Structural", 30.0);
    QualityStandard standard2("QS2", "Electrical", "Electrical", 220.0);
    
    service.addApplicableStandard(&standard1);
    service.addApplicableStandard(&standard2);
    
    auto standards = service.getApplicableStandards();
    EXPECT_EQ(standards.size(), 2);
}
