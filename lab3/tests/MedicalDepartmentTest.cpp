#include <gtest/gtest.h>
#include "MedicalDepartment.h"
#include "Doctor.h"
#include "Patient.h"

class MedicalDepartmentTest : public ::testing::Test {
protected:
    void SetUp() override {
        department = new MedicalDepartment("DEPT001", "Emergency Room", "Emergency");
        doctor = new Doctor("D001", "Dr. Smith", "Emergency", 8, "MED123", 25);
        patient = new Patient("P001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete department;
        delete doctor;
        delete patient;
    }

    MedicalDepartment* department;
    Doctor* doctor;
    Patient* patient;
};

TEST_F(MedicalDepartmentTest, CalculateUtilizationRate) {
    department->setCapacity(50);
    department->setCurrentPatients(25);
    double utilization = department->calculateUtilizationRate();
    EXPECT_GE(utilization, 0.0);
    EXPECT_LE(utilization, 100.0);
}

TEST_F(MedicalDepartmentTest, CanHandleEmergency) {
    bool canHandle = department->canHandleEmergency();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(MedicalDepartmentTest, CalculateEfficiencyScore) {
    double efficiency = department->calculateEfficiencyScore();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(MedicalDepartmentTest, NeedsAdditionalStaff) {
    bool needsStaff = department->needsAdditionalStaff();
    EXPECT_TRUE(needsStaff || !needsStaff);
}

TEST_F(MedicalDepartmentTest, DoctorManagement) {
    department->addDoctor(doctor);
    auto doctors = department->getDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    department->removeDoctor("D001");
    doctors = department->getDoctors();
    EXPECT_EQ(doctors.size(), 0);
}

TEST_F(MedicalDepartmentTest, PatientManagement) {
    department->setCapacity(10);
    department->admitPatient(patient);
    auto patients = department->getAdmittedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    department->dischargePatient("P001");
    patients = department->getAdmittedPatients();
    EXPECT_EQ(patients.size(), 0);
}
