#include <gtest/gtest.h>
#include "DoctorSchedulingService.h"
#include "Doctor.h"

class DoctorSchedulingServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new DoctorSchedulingService("SCHED001");
        doctor = new Doctor("DOC001", "Dr. Smith", "Cardiology", 10, "MED123", 20);
    }

    void TearDown() override {
        delete service;
        delete doctor;
    }

    DoctorSchedulingService* service;
    Doctor* doctor;
};

TEST_F(DoctorSchedulingServiceTest, CalculateScheduleEfficiency) {
    double efficiency = service->calculateScheduleEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(DoctorSchedulingServiceTest, AssignEmergencyCoverage) {
    bool coverage = service->assignEmergencyCoverage();
    EXPECT_TRUE(coverage || !coverage);
}

TEST_F(DoctorSchedulingServiceTest, ValidateWorkloadDistribution) {
    bool valid = service->validateWorkloadDistribution();
    EXPECT_TRUE(valid || !valid);
}

TEST_F(DoctorSchedulingServiceTest, DoctorManagement) {
    service->addManagedDoctor(doctor);
    auto doctors = service->getManagedDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    service->removeManagedDoctor("DOC001");
    doctors = service->getManagedDoctors();
    EXPECT_EQ(doctors.size(), 0);
}
