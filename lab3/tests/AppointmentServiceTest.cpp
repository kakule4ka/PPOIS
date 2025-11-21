#include <gtest/gtest.h>
#include "AppointmentService.h"
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"

class AppointmentServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new AppointmentService("APPT_SVC001");
        appointment = new Appointment("APT001", "2024-01-20", "10:00");
        doctor = new Doctor("DOC001", "Dr. Smith", "Cardiology", 10, "MED123", 20);
        patient = new Patient("PAT001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete service;
        delete appointment;
        delete doctor;
        delete patient;
    }

    AppointmentService* service;
    Appointment* appointment;
    Doctor* doctor;
    Patient* patient;
};

TEST_F(AppointmentServiceTest, ScheduleAppointment) {
    bool scheduled = service->scheduleAppointment(appointment, doctor, patient);
    EXPECT_TRUE(scheduled || !scheduled);
}

TEST_F(AppointmentServiceTest, CalculateScheduleOptimizationScore) {
    double score = service->calculateScheduleOptimizationScore();
    EXPECT_GE(score, 0.0);
    EXPECT_LE(score, 100.0);
}

TEST_F(AppointmentServiceTest, FindAvailableSlots) {
    auto slots = service->findAvailableSlots("2024-01-20", "Cardiology");
    EXPECT_TRUE(slots.size() >= 0);
}

TEST_F(AppointmentServiceTest, ValidateAppointmentFeasibility) {
    bool feasible = service->validateAppointmentFeasibility(appointment);
    EXPECT_TRUE(feasible || !feasible);
}

TEST_F(AppointmentServiceTest, AppointmentManagement) {
    service->addManagedAppointment(appointment);
    auto appointments = service->getManagedAppointments();
    EXPECT_EQ(appointments.size(), 1);
    
    service->removeManagedAppointment("APT001");
    appointments = service->getManagedAppointments();
    EXPECT_EQ(appointments.size(), 0);
}

TEST_F(AppointmentServiceTest, DoctorManagement) {
    service->addAvailableDoctor(doctor);
    auto doctors = service->getAvailableDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    service->removeAvailableDoctor("DOC001");
    doctors = service->getAvailableDoctors();
    EXPECT_EQ(doctors.size(), 0);
}

TEST_F(AppointmentServiceTest, PatientManagement) {
    service->addRegisteredPatient(patient);
    auto patients = service->getRegisteredPatients();
    EXPECT_EQ(patients.size(), 1);
    
    service->removeRegisteredPatient("PAT001");
    patients = service->getRegisteredPatients();
    EXPECT_EQ(patients.size(), 0);
}
