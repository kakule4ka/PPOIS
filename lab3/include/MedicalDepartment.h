#ifndef MEDICALDEPARTMENT_H
#define MEDICALDEPARTMENT_H

#include <string>
#include <vector>

class Doctor;
class Patient;

class MedicalDepartment {
private:
    std::string id;
    std::string name;
    std::string specialization;
    int capacity;
    int currentPatients;
    double budget;
    bool operationalStatus;
    std::vector<Doctor*> doctors;
    std::vector<Patient*> admittedPatients;

public:
    MedicalDepartment(const std::string& id, const std::string& name, const std::string& specialization);
    
    double calculateUtilizationRate() const;
    bool canHandleEmergency() const;
    double calculateEfficiencyScore() const;
    bool needsAdditionalStaff() const;
    
    void addDoctor(Doctor* doctor);
    void removeDoctor(const std::string& doctorId);
    std::vector<Doctor*> getDoctors() const;
    
    void admitPatient(Patient* patient);
    void dischargePatient(const std::string& patientId);
    std::vector<Patient*> getAdmittedPatients() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    void setCurrentPatients(int patients) { currentPatients = patients; }
    void setBudget(double budget) { this->budget = budget; }
    void setOperationalStatus(bool operational) { operationalStatus = operational; }
    int getCapacity() const { return capacity; }
    int getCurrentPatients() const { return currentPatients; }
    double getBudget() const { return budget; }
    bool isOperational() const { return operationalStatus; }
};

#endif
