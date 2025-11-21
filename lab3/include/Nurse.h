#ifndef NURSE_H
#define NURSE_H

#include <string>
#include <vector>

class Patient;
class MedicalDepartment;

class Nurse {
private:
    std::string id;
    std::string name;
    std::string qualification;
    int experienceYears;
    int shiftHours;
    int maxPatients;
    std::vector<Patient*> assignedPatients;
    MedicalDepartment* department;

public:
    Nurse(const std::string& id, const std::string& name, const std::string& qualification, int experience);
    
    double calculateWorkload() const;
    bool canTakeMorePatients() const;
    double calculatePatientCareScore() const;
    
    void addPatient(Patient* patient);
    void removePatient(const std::string& patientId);
    std::vector<Patient*> getAssignedPatients() const;
    
    void setDepartment(MedicalDepartment* department);
    MedicalDepartment* getDepartment() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getQualification() const { return qualification; }
    int getExperienceYears() const { return experienceYears; }
    void setShiftHours(int hours) { shiftHours = hours; }
    void setMaxPatients(int max) { maxPatients = max; }
    int getShiftHours() const { return shiftHours; }
    int getMaxPatients() const { return maxPatients; }
};

#endif
