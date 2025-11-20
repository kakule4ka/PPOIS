#include <gtest/gtest.h>
#include "SafetyProtocol.h"

TEST(SafetyProtocolTest, ValidateWorkerComplianceMandatory) {
    SafetyProtocol protocol("SAFE001", "Fall Protection", 40, true);
    bool compliant = protocol.validateWorkerCompliance(40);
    EXPECT_TRUE(compliant);
}

TEST(SafetyProtocolTest, ValidateWorkerComplianceNonMandatory) {
    SafetyProtocol protocol("SAFE002", "Equipment Safety", 20, false);
    bool compliant = protocol.validateWorkerCompliance(15);
    EXPECT_TRUE(compliant);
}

TEST(SafetyProtocolTest, ValidateWorkerComplianceInsufficient) {
    SafetyProtocol protocol("SAFE003", "Emergency Procedures", 30, true);
    bool compliant = protocol.validateWorkerCompliance(20);
    EXPECT_FALSE(compliant);
}

TEST(SafetyProtocolTest, CalculateComplianceRateHigh) {
    SafetyProtocol protocol("SAFE004", "Hazard Communication", 25, true);
    double rate = protocol.calculateComplianceRate(45, 50);
    EXPECT_GT(rate, 80.0);
}

TEST(SafetyProtocolTest, CalculateComplianceRateLow) {
    SafetyProtocol protocol("SAFE005", "Fire Safety", 15, false);
    double rate = protocol.calculateComplianceRate(10, 30);
    EXPECT_LT(rate, 50.0);
}

TEST(SafetyProtocolTest, GetProtocolId) {
    SafetyProtocol protocol("SAFE006", "Electrical Safety", 35, true);
    EXPECT_EQ(protocol.getId(), "SAFE006");
}
