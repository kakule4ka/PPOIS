#ifndef RADIOLOGIST_H
#define RADIOLOGIST_H

#include "Doctor.h"
#include <string>
#include <vector>

class MedicalDevice;

class Radiologist : public Doctor {
private:
    int scansInterpreted;
    double diagnosticAccuracy;
    std::vector<MedicalDevice*> imagingEquipment;

public:
    Radiologist(const std::string& id, const std::string& name, int experience, 
                const std::string& license, int maxPatients, int scans, double accuracy);
    
    double calculateDiagnosticAccuracy() const;
    bool canInterpretComplexCases() const;
    
    void addImagingEquipment(MedicalDevice* equipment);
    void removeImagingEquipment(const std::string& equipmentId);
    std::vector<MedicalDevice*> getImagingEquipment() const;
    
    int getScansInterpreted() const { return scansInterpreted; }
    double getDiagnosticAccuracy() const { return diagnosticAccuracy; }
};

#endif
