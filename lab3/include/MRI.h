#ifndef MRI_H
#define MRI_H

#include "MedicalDevice.h"
#include <string>
#include <vector>

class Patient;
class Radiologist;

class MRI : public MedicalDevice {
private:
    std::string scanType;
    double magneticStrength;
    int scanDuration;
    std::vector<Patient*> mriPatients;
    std::vector<Radiologist*> mriSpecialists;

public:
    MRI(const std::string& id, const std::string& name, const std::string& scanType);
    
    double calculateScanQuality() const;
    bool requiresContrast() const;
    double calculateDiagnosticPrecision() const;
    
    void addMRIPatient(Patient* patient);
    void removeMRIPatient(const std::string& patientId);
    std::vector<Patient*> getMRIPatients() const;
    
    void addMRISpecialist(Radiologist* specialist);
    void removeMRISpecialist(const std::string& specialistId);
    std::vector<Radiologist*> getMRISpecialists() const;
    
    std::string getScanType() const { return scanType; }
    void setMagneticStrength(double strength) { magneticStrength = strength; }
    void setScanDuration(int duration) { scanDuration = duration; }
    double getMagneticStrength() const { return magneticStrength; }
    int getScanDuration() const { return scanDuration; }
};

#endif
