#ifndef WARD_H
#define WARD_H

#include <string>
#include <vector>

class Patient;
class Nurse;
class MedicalDepartment;

class Ward {
private:
    std::string id;
    std::string name;
    std::string type;
    int capacity;
    int currentOccupancy;
    double cleanlinessScore;
    std::vector<Patient*> patients;
    std::vector<Nurse*> assignedNurses;
    MedicalDepartment* department;

public:
    Ward(const std::string& id, const std::string& name, const std::string& type, int capacity);
    
    double calculateOccupancyRate() const;
    bool canAdmitPatient() const;
    double calculateCareQualityScore() const;
    
    void addPatient(Patient* patient);
    void removePatient(const std::string& patientId);
    std::vector<Patient*> getPatients() const;
    
    void addNurse(Nurse* nurse);
    void removeNurse(const std::string& nurseId);
    std::vector<Nurse*> getAssignedNurses() const;
    
    void setDepartment(MedicalDepartment* department);
    MedicalDepartment* getDepartment() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getCapacity() const { return capacity; }
    void setCurrentOccupancy(int occupancy) { currentOccupancy = occupancy; }
    void setCleanlinessScore(double score) { cleanlinessScore = score; }
    int getCurrentOccupancy() const { return currentOccupancy; }
    double getCleanlinessScore() const { return cleanlinessScore; }
};

#endif
