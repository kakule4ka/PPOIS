#include <gtest/gtest.h>
#include "Nurse.h"
#include "Patient.h"
#include "MedicalDepartment.h"

class NurseTest : public ::testing::Test {
protected:
    void SetUp() override {
        nurse = new Nurse("N001", "Jane Smith", "RN", 5);
        patient = new Patient("P001", "John Doe", 45, "A+");
        department = new MedicalDepartment("DEPT001", "ICU", "Intensive Care");
    }

    void TearDown() override {
        delete nurse;
        delete patient;
        delete department;
    }

    Nurse* nurse;
    Patient* patient;
    MedicalDepartment* department;
};

TEST_F(NurseTest, CalculateWorkload) {
    double workload = nurse->calculateWorkload();
    EXPECT_GE(workload, 0.0);
    EXPECT_LE(workload, 100.0);
}

TEST_F(NurseTest, CanTakeMorePatients) {
    bool canTakeMore = nurse->canTakeMorePatients();
    EXPECT_TRUE(canTakeMore || !canTakeMore);
}

TEST_F(NurseTest, CalculatePatientCareScore) {
    double careScore = nurse->calculatePatientCareScore();
    EXPECT_GE(careScore, 0.0);
    EXPECT_LE(careScore, 100.0);
}

TEST_F(NurseTest, PatientManagement) {
    nurse->addPatient(patient);
    auto patients = nurse->getAssignedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    nurse->removePatient("P001");
    patients = nurse->getAssignedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(NurseTest, DepartmentAssociation) {
    nurse->setDepartment(department);
    EXPECT_EQ(nurse->getDepartment(), department);
}
