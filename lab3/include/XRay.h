#ifndef XRAY_H
#define XRAY_H

#include "MedicalDevice.h"
#include <string>
#include <vector>

class Patient;
class Radiologist;

class XRay : public MedicalDevice {
private:
    std::string bodyPart;
    double radiationDose;
    int imageQuality;
    std::vector<Patient*> scannedPatients;
    std::vector<Radiologist*> interpretingRadiologists;

public:
    XRay(const std::string& id, const std::string& name, const std::string& bodyPart);
    
    double calculateRadiationRisk() const;
    bool requiresFollowUpScan() const;
    double calculateDiagnosticAccuracy() const;
    
    void addScannedPatient(Patient* patient);
    void removeScannedPatient(const std::string& patientId);
    std::vector<Patient*> getScannedPatients() const;
    
    void addInterpretingRadiologist(Radiologist* radiologist);
    void removeInterpretingRadiologist(const std::string& radiologistId);
    std::vector<Radiologist*> getInterpretingRadiologists() const;
    
    std::string getBodyPart() const { return bodyPart; }
    void setRadiationDose(double dose) { radiationDose = dose; }
    void setImageQuality(int quality) { imageQuality = quality; }
    double getRadiationDose() const { return radiationDose; }
    int getImageQuality() const { return imageQuality; }
};

#endif
