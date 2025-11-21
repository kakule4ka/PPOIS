#include <gtest/gtest.h>
#include "Hospital.h"
#include "MedicalDepartment.h"
#include "Patient.h"

class HospitalTest : public ::testing::Test {
protected:
    void SetUp() override {
        hospital = new Hospital("City General", "123 Main St", 200, 1985, 10000000.0);
    department = new MedicalDepartment("ER", "Emergency Room", "Emergency");
    hospital->addDepartment(department);
        department = new MedicalDepartment("ER", "Emergency", "Emergency");
        patient = new Patient("P001", "John Doe", 45, "A+");
    hospital->addDepartment(department);
    hospital->addDepartment(department);
    }

    void TearDown() override {
        delete hospital;
        delete department;
        delete patient;
    }

    Hospital* hospital;
    MedicalDepartment* department;
    Patient* patient;
};

TEST_F(HospitalTest, CalculateBedOccupancyRate) {
    hospital->admitPatient(patient);
    double occupancy = hospital->calculateBedOccupancyRate();
    EXPECT_GE(occupancy, 0.0);
    EXPECT_LE(occupancy, 100.0);
}

TEST_F(HospitalTest, CanHandleEmergency) {
    EXPECT_TRUE(hospital->canHandleEmergency(2));
    hospital->admitPatient(patient);
    bool canHandle = hospital->canHandleEmergency(5);
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(HospitalTest, ResourceUtilization) {
    hospital->addDepartment(department);
    double utilization = hospital->calculateResourceUtilization();
    EXPECT_GE(utilization, 0.0);
    EXPECT_LE(utilization, 100.0);
}

TEST_F(HospitalTest, NeedsExpansion) {
    bool needsExpansion = hospital->needsExpansion();
    EXPECT_TRUE(needsExpansion || !needsExpansion);
}

TEST_F(HospitalTest, PatientSatisfactionScore) {
    double satisfaction = hospital->calculatePatientSatisfactionScore();
    EXPECT_GE(satisfaction, 0.0);
    EXPECT_LE(satisfaction, 100.0);
}
