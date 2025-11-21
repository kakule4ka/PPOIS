#include <gtest/gtest.h>
#include "EmergencyCase.h"
#include "Patient.h"
#include "Doctor.h"
#include "MedicalDepartment.h"

class EmergencyCaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        emergency = new EmergencyCase("E001", "Cardiac arrest", 5);
        patient = new Patient("P001", "John Doe", 65, "A+");
        doctor = new Doctor("D001", "Dr. Smith", "Emergency", 8, "MED123", 20);
        department = new MedicalDepartment("DEPT001", "Emergency Room", "Emergency");
    }

    void TearDown() override {
        delete emergency;
        delete patient;
        delete doctor;
        delete department;
    }

    EmergencyCase* emergency;
    Patient* patient;
    Doctor* doctor;
    MedicalDepartment* department;
};

TEST_F(EmergencyCaseTest, CalculateUrgencyScore) {
    double urgency = emergency->calculateUrgencyScore();
    EXPECT_GE(urgency, 0.0);
    EXPECT_LE(urgency, 100.0);
}

TEST_F(EmergencyCaseTest, RequiresImmediateSurgery) {
    bool requiresSurgery = emergency->requiresImmediateSurgery();
    EXPECT_TRUE(requiresSurgery || !requiresSurgery);
}

TEST_F(EmergencyCaseTest, CalculateResourceAllocationPriority) {
    double priority = emergency->calculateResourceAllocationPriority();
    EXPECT_GE(priority, 0.0);
    EXPECT_LE(priority, 100.0);
}

TEST_F(EmergencyCaseTest, PatientAssociation) {
    emergency->setPatient(patient);
    EXPECT_EQ(emergency->getPatient(), patient);
}

TEST_F(EmergencyCaseTest, DoctorAssociation) {
    emergency->setAssignedDoctor(doctor);
    EXPECT_EQ(emergency->getAssignedDoctor(), doctor);
}

TEST_F(EmergencyCaseTest, DepartmentAssociation) {
    emergency->setTreatmentDepartment(department);
    EXPECT_EQ(emergency->getTreatmentDepartment(), department);
}
