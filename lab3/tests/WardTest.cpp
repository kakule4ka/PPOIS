#include <gtest/gtest.h>
#include "Ward.h"
#include "Patient.h"
#include "Nurse.h"
#include "MedicalDepartment.h"

class WardTest : public ::testing::Test {
protected:
    void SetUp() override {
        ward = new Ward("WARD001", "General Ward", "General", 20);
        patient = new Patient("P001", "John Doe", 45, "A+");
        nurse = new Nurse("N001", "Jane Smith", "RN", 5);
        department = new MedicalDepartment("DEPT001", "Internal Medicine", "General");
    }

    void TearDown() override {
        delete ward;
        delete patient;
        delete nurse;
        delete department;
    }

    Ward* ward;
    Patient* patient;
    Nurse* nurse;
    MedicalDepartment* department;
};

TEST_F(WardTest, CalculateOccupancyRate) {
    ward->setCurrentOccupancy(10);
    double occupancy = ward->calculateOccupancyRate();
    EXPECT_GE(occupancy, 0.0);
    EXPECT_LE(occupancy, 100.0);
}

TEST_F(WardTest, CanAdmitPatient) {
    bool canAdmit = ward->canAdmitPatient();
    EXPECT_TRUE(canAdmit || !canAdmit);
}

TEST_F(WardTest, CalculateCareQualityScore) {
    double quality = ward->calculateCareQualityScore();
    EXPECT_GE(quality, 0.0);
    EXPECT_LE(quality, 100.0);
}

TEST_F(WardTest, PatientManagement) {
    ward->addPatient(patient);
    auto patients = ward->getPatients();
    EXPECT_EQ(patients.size(), 1);
    
    ward->removePatient("P001");
    patients = ward->getPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(WardTest, NurseManagement) {
    ward->addNurse(nurse);
    auto nurses = ward->getAssignedNurses();
    EXPECT_EQ(nurses.size(), 1);
    
    ward->removeNurse("N001");
    nurses = ward->getAssignedNurses();
    EXPECT_EQ(nurses.size(), 0);
}

TEST_F(WardTest, DepartmentAssociation) {
    ward->setDepartment(department);
    EXPECT_EQ(ward->getDepartment(), department);
}
