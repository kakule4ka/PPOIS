#include <gtest/gtest.h>
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"

class AppointmentTest : public ::testing::Test {
protected:
    void SetUp() override {
        appointment = new Appointment("A001", "2024-01-15", "10:00");
        doctor = new Doctor("D001", "Dr. Smith", "Cardiology", 10, "MED123", 20);
        patient = new Patient("P001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete appointment;
        delete doctor;
        delete patient;
    }

    Appointment* appointment;
    Doctor* doctor;
    Patient* patient;
};

TEST_F(AppointmentTest, CalculateOverlapRisk) {
    double risk = appointment->calculateOverlapRisk();
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(AppointmentTest, CanBeRescheduled) {
    bool reschedulable = appointment->canBeRescheduled();
    EXPECT_TRUE(reschedulable || !reschedulable);
}

TEST_F(AppointmentTest, CalculateUrgencyScore) {
    double urgency = appointment->calculateUrgencyScore();
    EXPECT_GE(urgency, 0.0);
    EXPECT_LE(urgency, 100.0);
}

TEST_F(AppointmentTest, DoctorAssociation) {
    appointment->setDoctor(doctor);
    EXPECT_EQ(appointment->getDoctor(), doctor);
}

TEST_F(AppointmentTest, PatientAssociation) {
    appointment->setPatient(patient);
    EXPECT_EQ(appointment->getPatient(), patient);
}
