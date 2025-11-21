#include "AppointmentService.h"
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include <algorithm>
#include <cmath>

AppointmentService::AppointmentService(const std::string& serviceId)
    : serviceId(serviceId) {}

bool AppointmentService::scheduleAppointment(Appointment* appointment, Doctor* doctor, Patient* patient) {
    if (!appointment || !doctor || !patient) return false;
    
    if (!validateAppointmentFeasibility(appointment)) return false;
    
    appointment->setDoctor(doctor);
    appointment->setPatient(patient);
    
    doctor->scheduleAppointment(appointment);
    managedAppointments.push_back(appointment);
    
    return true;
}

bool AppointmentService::rescheduleAppointment(const std::string& appointmentId, const std::string& newDate, const std::string& newTime) {
    auto it = std::find_if(managedAppointments.begin(), managedAppointments.end(),
        [&appointmentId](Appointment* appt) {
            return appt->getId() == appointmentId;
        });
    
    if (it == managedAppointments.end()) return false;
    
    Appointment* appointment = *it;
    
    if (!appointment->canBeRescheduled()) return false;
    
    // In a real system, we would update date and time
    // For now, we'll just simulate the operation
    return true;
}

bool AppointmentService::cancelAppointment(const std::string& appointmentId) {
    auto it = std::find_if(managedAppointments.begin(), managedAppointments.end(),
        [&appointmentId](Appointment* appt) {
            return appt->getId() == appointmentId;
        });
    
    if (it == managedAppointments.end()) return false;
    
    Appointment* appointment = *it;
    Doctor* doctor = appointment->getDoctor();
    
    if (doctor) {
        doctor->cancelAppointment(appointmentId);
    }
    
    managedAppointments.erase(it);
    return true;
}

double AppointmentService::calculateScheduleOptimizationScore() const {
    if (managedAppointments.empty()) return 0.0;
    
    double baseScore = 70.0;
    
    double overlapRiskScore = 0.0;
    double urgencyOptimizationScore = 0.0;
    int optimizedAppointments = 0;
    
    for (const auto& appointment : managedAppointments) {
        double overlapRisk = appointment->calculateOverlapRisk();
        overlapRiskScore += (100.0 - overlapRisk) * 0.1;
        
        double urgencyScore = appointment->calculateUrgencyScore();
        if (urgencyScore > 60.0) {
            urgencyOptimizationScore += 15.0;
        }
        
        if (appointment->canBeRescheduled()) {
            optimizedAppointments++;
        }
    }
    
    double optimizationRate = (static_cast<double>(optimizedAppointments) / managedAppointments.size()) * 20.0;
    double doctorUtilizationScore = availableDoctors.size() > 0 ? 25.0 : 10.0;
    
    double totalScore = baseScore + overlapRiskScore + urgencyOptimizationScore + optimizationRate + doctorUtilizationScore;
    return std::min(totalScore, 100.0);
}

std::vector<Appointment*> AppointmentService::findAvailableSlots(const std::string& date, const std::string& specialty) const {
    std::vector<Appointment*> availableSlots;
    
    // Simulate finding available slots based on specialty
    for (const auto& doctor : availableDoctors) {
        if (doctor->getSpecialization() == specialty || specialty.empty()) {
            // In a real system, we would check doctor's schedule and create available slots
            // For now, we'll return a simulated available appointment
            if (doctor->getScheduledAppointments().size() < doctor->getMaxPatientsPerDay()) {
                // This indicates availability
                availableSlots.push_back(nullptr); // Placeholder for actual slot creation
            }
        }
    }
    
    return availableSlots;
}

bool AppointmentService::validateAppointmentFeasibility(const Appointment* appointment) const {
    if (!appointment) return false;
    
    Doctor* doctor = appointment->getDoctor();
    if (!doctor) return false;
    
    // Check if doctor has capacity
    if (doctor->getScheduledAppointments().size() >= doctor->getMaxPatientsPerDay()) {
        return false;
    }
    
    // Check if appointment time is reasonable (simplified)
    if (appointment->getDurationMinutes() > 180) {
        return false;
    }
    
    // Check for potential overlaps (simplified)
    double overlapRisk = appointment->calculateOverlapRisk();
    if (overlapRisk > 70.0) {
        return false;
    }
    
    return true;
}

void AppointmentService::addManagedAppointment(Appointment* appointment) {
    if (appointment) {
        managedAppointments.push_back(appointment);
    }
}

void AppointmentService::removeManagedAppointment(const std::string& appointmentId) {
    managedAppointments.erase(
        std::remove_if(managedAppointments.begin(), managedAppointments.end(),
            [&appointmentId](Appointment* appointment) {
                return appointment->getId() == appointmentId;
            }),
        managedAppointments.end()
    );
}

std::vector<Appointment*> AppointmentService::getManagedAppointments() const {
    return managedAppointments;
}

void AppointmentService::addAvailableDoctor(Doctor* doctor) {
    if (doctor) {
        availableDoctors.push_back(doctor);
    }
}

void AppointmentService::removeAvailableDoctor(const std::string& doctorId) {
    availableDoctors.erase(
        std::remove_if(availableDoctors.begin(), availableDoctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        availableDoctors.end()
    );
}

std::vector<Doctor*> AppointmentService::getAvailableDoctors() const {
    return availableDoctors;
}

void AppointmentService::addRegisteredPatient(Patient* patient) {
    if (patient) {
        registeredPatients.push_back(patient);
    }
}

void AppointmentService::removeRegisteredPatient(const std::string& patientId) {
    registeredPatients.erase(
        std::remove_if(registeredPatients.begin(), registeredPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        registeredPatients.end()
    );
}

std::vector<Patient*> AppointmentService::getRegisteredPatients() const {
    return registeredPatients;
}
