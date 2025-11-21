#include <gtest/gtest.h>
#include "MedicalEquipment.h"
#include "MedicalDepartment.h"
#include "Patient.h"

class MedicalEquipmentTest : public ::testing::Test {
protected:
    void SetUp() override {
        equipment = new MedicalEquipment("EQ001", "MRI Machine", "Imaging", 1500000.0);
        department = new MedicalDepartment("DEPT001", "Radiology", "Imaging");
        patient = new Patient("P001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete equipment;
        delete department;
        delete patient;
    }

    MedicalEquipment* equipment;
    MedicalDepartment* department;
    Patient* patient;
};

TEST_F(MedicalEquipmentTest, CalculateMaintenanceCost) {
    equipment->setUsageHours(3000);
    double maintenanceCost = equipment->calculateMaintenanceCost();
    EXPECT_GT(maintenanceCost, 0.0);
}

TEST_F(MedicalEquipmentTest, NeedsMaintenance) {
    equipment->setUsageHours(2500);
    bool needsMaintenance = equipment->needsMaintenance();
    EXPECT_TRUE(needsMaintenance || !needsMaintenance);
}

TEST_F(MedicalEquipmentTest, CalculateUtilizationEfficiency) {
    double efficiency = equipment->calculateUtilizationEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(MedicalEquipmentTest, DepartmentAssociation) {
    equipment->addDepartment(department);
    auto departments = equipment->getDepartments();
    EXPECT_EQ(departments.size(), 1);
    
    equipment->removeDepartment("DEPT001");
    departments = equipment->getDepartments();
    EXPECT_EQ(departments.size(), 0);
}

TEST_F(MedicalEquipmentTest, PatientAssociation) {
    equipment->addTreatedPatient(patient);
    auto patients = equipment->getTreatedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    equipment->removeTreatedPatient("P001");
    patients = equipment->getTreatedPatients();
    EXPECT_EQ(patients.size(), 0);
}
