#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Doctor;
class Patient;

class Appointment {
private:
    std::string id;
    std::string date;
    std::string time;
    int durationMinutes;
    std::string status;
    std::string reason;
    Doctor* doctor;
    Patient* patient;

public:
    Appointment(const std::string& id, const std::string& date, const std::string& time);
    
    double calculateOverlapRisk() const;
    bool canBeRescheduled() const;
    double calculateUrgencyScore() const;
    
    void setDoctor(Doctor* doctor);
    Doctor* getDoctor() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    std::string getId() const { return id; }
    std::string getDate() const { return date; }
    std::string getTime() const { return time; }
    void setDurationMinutes(int duration) { durationMinutes = duration; }
    void setStatus(const std::string& status) { this->status = status; }
    void setReason(const std::string& reason) { this->reason = reason; }
    int getDurationMinutes() const { return durationMinutes; }
    std::string getStatus() const { return status; }
};

#endif
