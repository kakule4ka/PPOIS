#ifndef EMERGENCYCASE_H
#define EMERGENCYCASE_H

#include <string>
#include <vector>

class Patient;
class Doctor;
class MedicalDepartment;

class EmergencyCase {
private:
    std::string id;
    std::string description;
    int severityLevel;
    std::string arrivalTime;
    std::string status;
    int treatmentDuration;
    Patient* patient;
    Doctor* assignedDoctor;
    MedicalDepartment* treatmentDepartment;

public:
    EmergencyCase(const std::string& id, const std::string& description, int severityLevel);
    
    double calculateUrgencyScore() const;
    bool requiresImmediateSurgery() const;
    double calculateResourceAllocationPriority() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void setAssignedDoctor(Doctor* doctor);
    Doctor* getAssignedDoctor() const;
    
    void setTreatmentDepartment(MedicalDepartment* department);
    MedicalDepartment* getTreatmentDepartment() const;
    
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    int getSeverityLevel() const { return severityLevel; }
    void setArrivalTime(const std::string& time) { arrivalTime = time; }
    void setStatus(const std::string& status) { this->status = status; }
    void setTreatmentDuration(int duration) { treatmentDuration = duration; }
    std::string getArrivalTime() const { return arrivalTime; }
    std::string getStatus() const { return status; }
    int getTreatmentDuration() const { return treatmentDuration; }
};

#endif
