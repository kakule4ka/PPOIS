#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>

class Patient;
class Appointment;

class Doctor {
private:
    std::string id;
    std::string name;
    std::string specialization;
    int experienceYears;
    std::string licenseNumber;
    int maxPatientsPerDay;
    std::vector<Patient*> currentPatients;
    std::vector<Appointment*> scheduledAppointments;

public:
    Doctor(const std::string& id, const std::string& name, const std::string& specialization, 
           int experience, const std::string& license, int maxPatients);
    
    double calculateWorkloadEfficiency() const;
    bool isAvailableForEmergency() const;
    double calculatePatientSuccessRate() const;
    bool needsContinuingEducation() const;
    std::string determineExpertiseLevel() const;
    
    void addPatient(Patient* patient);
    void removePatient(const std::string& patientId);
    std::vector<Patient*> getCurrentPatients() const;
    
    void scheduleAppointment(Appointment* appointment);
    void cancelAppointment(const std::string& appointmentId);
    std::vector<Appointment*> getScheduledAppointments() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    int getExperienceYears() const { return experienceYears; }
    std::string getLicenseNumber() const { return licenseNumber; }
    int getMaxPatientsPerDay() const { return maxPatientsPerDay; }
};

#endif
