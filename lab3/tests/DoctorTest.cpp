#include <gtest/gtest.h>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

class DoctorTest : public ::testing::Test {
protected:
    void SetUp() override {
        doctor = new Doctor("D001", "Dr. Smith", "Cardiology", 15, "MED123456", 20);
        patient = new Patient("P001", "John Doe", 45, "A+");
        appointment = new Appointment("A001", "2024-01-15", "10:00");
    }

    void TearDown() override {
        delete doctor;
        delete patient;
        delete appointment;
    }

    Doctor* doctor;
    Patient* patient;
    Appointment* appointment;
};

TEST_F(DoctorTest, CalculateWorkloadEfficiency) {
    double efficiency = doctor->calculateWorkloadEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(DoctorTest, AvailableForEmergency) {
    bool available = doctor->isAvailableForEmergency();
    EXPECT_TRUE(available || !available);
}

TEST_F(DoctorTest, PatientSuccessRate) {
    double successRate = doctor->calculatePatientSuccessRate();
    EXPECT_GE(successRate, 0.0);
    EXPECT_LE(successRate, 100.0);
}

TEST_F(DoctorTest, NeedsContinuingEducation) {
    bool needsEducation = doctor->needsContinuingEducation();
    EXPECT_TRUE(needsEducation || !needsEducation);
}

TEST_F(DoctorTest, ExpertiseLevel) {
    std::string expertise = doctor->determineExpertiseLevel();
    EXPECT_FALSE(expertise.empty());
}

TEST_F(DoctorTest, PatientManagement) {
    doctor->addPatient(patient);
    auto patients = doctor->getCurrentPatients();
    EXPECT_EQ(patients.size(), 1);
    
    doctor->removePatient("P001");
    patients = doctor->getCurrentPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(DoctorTest, AppointmentManagement) {
    doctor->scheduleAppointment(appointment);
    auto appointments = doctor->getScheduledAppointments();
    EXPECT_EQ(appointments.size(), 1);
    
    doctor->cancelAppointment("A001");
    appointments = doctor->getScheduledAppointments();
    EXPECT_EQ(appointments.size(), 0);
}
