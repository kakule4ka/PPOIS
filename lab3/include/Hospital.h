#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>

class MedicalDepartment;
class Patient;

class Hospital {
private:
    std::string name;
    std::string address;
    int capacity;
    int establishedYear;
    double budget;
    std::vector<MedicalDepartment*> departments;
    std::vector<Patient*> currentPatients;

public:
    Hospital(const std::string& name, const std::string& address, int capacity, int year, double budget);
    
    double calculateBedOccupancyRate() const;
    bool canHandleEmergency(int emergencySeverity) const;
    double calculateResourceUtilization() const;
    bool needsExpansion() const;
    double calculatePatientSatisfactionScore() const;
    
    void addDepartment(MedicalDepartment* department);
    void removeDepartment(const std::string& departmentId);
    std::vector<MedicalDepartment*> getDepartments() const;
    
    void admitPatient(Patient* patient);
    void dischargePatient(const std::string& patientId);
    std::vector<Patient*> getCurrentPatients() const;
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    int getCapacity() const { return capacity; }
};

#endif
