#include <gtest/gtest.h>
#include "core/SafetyProtocol.h"
#include "core/ConstructionProject.h"
#include "models/Employee.h"
#include "models/Equipment.h"

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

TEST(SafetyProtocolTest, CalculateComplianceRateHigh) {
    SafetyProtocol protocol("SAFE004", "Hazard Communication", 25, true);
    double rate = protocol.calculateComplianceRate(45, 50);
    EXPECT_GT(rate, 80.0);
}

TEST(SafetyProtocolTest, CalculateRiskReduction) {
    SafetyProtocol protocol("SAFE005", "Fire Safety", 15, false);
    double reduction = protocol.calculateRiskReduction();
    EXPECT_GT(reduction, 0.0);
}

TEST(SafetyProtocolTest, NeedsRetraining) {
    SafetyProtocol protocol("SAFE006", "Electrical Safety", 35, true);
    bool needsRetrain = protocol.needsRetraining();
    EXPECT_FALSE(needsRetrain);
}

TEST(SafetyProtocolTest, AddAndGetApplicableProjects) {
    SafetyProtocol protocol("SAFE007", "Test Protocol", 20, true);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    protocol.addApplicableProject(&project1);
    protocol.addApplicableProject(&project2);
    
    auto projects = protocol.getApplicableProjects();
    EXPECT_EQ(projects.size(), 2);
}

TEST(SafetyProtocolTest, AddAndGetTrainedEmployees) {
    SafetyProtocol protocol("SAFE008", "Training Protocol", 25, true);
    Employee employee1("E1", "John", "Worker", 50000);
    Employee employee2("E2", "Jane", "Manager", 70000);
    
    protocol.addTrainedEmployee(&employee1);
    protocol.addTrainedEmployee(&employee2);
    
    auto employees = protocol.getTrainedEmployees();
    EXPECT_EQ(employees.size(), 2);
}

TEST(SafetyProtocolTest, AddAndGetRelatedEquipment) {
    SafetyProtocol protocol("SAFE009", "Equipment Protocol", 30, true);
    Equipment equipment1("EQ1", "Crane", 5000);
    Equipment equipment2("EQ2", "Excavator", 8000);
    
    protocol.addRelatedEquipment(&equipment1);
    protocol.addRelatedEquipment(&equipment2);
    
    auto equipment = protocol.getRelatedEquipment();
    EXPECT_EQ(equipment.size(), 2);
}
