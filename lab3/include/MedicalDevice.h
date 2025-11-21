#ifndef MEDICALDEVICE_H
#define MEDICALDEVICE_H

#include <string>
#include <vector>

class Patient;
class Doctor;

class MedicalDevice {
private:
    std::string id;
    std::string name;
    std::string category;
    double accuracy;
    int calibrationInterval;
    int usageCount;
    std::vector<Patient*> testedPatients;
    std::vector<Doctor*> operatingDoctors;

public:
    MedicalDevice(const std::string& id, const std::string& name, const std::string& category);
    
    double calculateReliabilityScore() const;
    bool needsCalibration() const;
    double calculateDiagnosticValue() const;
    
    void addTestedPatient(Patient* patient);
    void removeTestedPatient(const std::string& patientId);
    std::vector<Patient*> getTestedPatients() const;
    
    void addOperatingDoctor(Doctor* doctor);
    void removeOperatingDoctor(const std::string& doctorId);
    std::vector<Doctor*> getOperatingDoctors() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    void setAccuracy(double accuracy) { this->accuracy = accuracy; }
    void setCalibrationInterval(int interval) { calibrationInterval = interval; }
    void setUsageCount(int count) { usageCount = count; }
    double getAccuracy() const { return accuracy; }
    int getCalibrationInterval() const { return calibrationInterval; }
    int getUsageCount() const { return usageCount; }
};

#endif
