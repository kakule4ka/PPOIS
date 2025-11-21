#ifndef LABORATORYTEST_H
#define LABORATORYTEST_H

#include <string>
#include <vector>

class Patient;
class Doctor;

class LaboratoryTest {
private:
    std::string id;
    std::string name;
    std::string type;
    double cost;
    int processingTime;
    double accuracy;
    std::vector<Patient*> patients;
    std::vector<Doctor*> requestingDoctors;

public:
    LaboratoryTest(const std::string& id, const std::string& name, const std::string& type);
    
    double calculateDiagnosticValue() const;
    bool isHighPriority() const;
    double calculateResultReliability() const;
    
    void addPatient(Patient* patient);
    void removePatient(const std::string& patientId);
    std::vector<Patient*> getPatients() const;
    
    void addRequestingDoctor(Doctor* doctor);
    void removeRequestingDoctor(const std::string& doctorId);
    std::vector<Doctor*> getRequestingDoctors() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    void setCost(double cost) { this->cost = cost; }
    void setProcessingTime(int time) { processingTime = time; }
    void setAccuracy(double accuracy) { this->accuracy = accuracy; }
    double getCost() const { return cost; }
    int getProcessingTime() const { return processingTime; }
    double getAccuracy() const { return accuracy; }
};

#endif
