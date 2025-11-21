#ifndef APPOINTMENTSERVICE_H
#define APPOINTMENTSERVICE_H

#include <string>
#include <vector>

class Appointment;
class Doctor;
class Patient;

class AppointmentService {
private:
    std::string serviceId;
    std::vector<Appointment*> managedAppointments;
    std::vector<Doctor*> availableDoctors;
    std::vector<Patient*> registeredPatients;

public:
    AppointmentService(const std::string& serviceId);
    
    bool scheduleAppointment(Appointment* appointment, Doctor* doctor, Patient* patient);
    bool rescheduleAppointment(const std::string& appointmentId, const std::string& newDate, const std::string& newTime);
    bool cancelAppointment(const std::string& appointmentId);
    double calculateScheduleOptimizationScore() const;
    std::vector<Appointment*> findAvailableSlots(const std::string& date, const std::string& specialty) const;
    bool validateAppointmentFeasibility(const Appointment* appointment) const;
    
    void addManagedAppointment(Appointment* appointment);
    void removeManagedAppointment(const std::string& appointmentId);
    std::vector<Appointment*> getManagedAppointments() const;
    
    void addAvailableDoctor(Doctor* doctor);
    void removeAvailableDoctor(const std::string& doctorId);
    std::vector<Doctor*> getAvailableDoctors() const;
    
    void addRegisteredPatient(Patient* patient);
    void removeRegisteredPatient(const std::string& patientId);
    std::vector<Patient*> getRegisteredPatients() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
