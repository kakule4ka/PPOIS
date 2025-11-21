#include "XRay.h"
#include "Patient.h"
#include "Radiologist.h"
#include <algorithm>
#include <cmath>

XRay::XRay(const std::string& id, const std::string& name, const std::string& bodyPart)
    : MedicalDevice(id, name, "Imaging"), bodyPart(bodyPart), radiationDose(0.1), imageQuality(85) {}

double XRay::calculateRadiationRisk() const {
    double baseRisk = 5.0;
    
    double doseRisk = radiationDose * 50.0;
    
    double bodyPartRisk = 0.0;
    if (bodyPart == "Chest") bodyPartRisk = 10.0;
    else if (bodyPart == "Abdomen") bodyPartRisk = 20.0;
    else if (bodyPart == "Spine") bodyPartRisk = 15.0;
    
    double patientRisk = 0.0;
    for (const auto& patient : scannedPatients) {
        if (patient->getAge() < 18 || patient->getAge() > 65) {
            patientRisk += 2.0;
        }
    }
    
    double frequencyRisk = scannedPatients.size() * 0.1;
    
    double radiologistExpertiseRisk = 0.0;
    for (const auto& radiologist : interpretingRadiologists) {
        radiologistExpertiseRisk -= radiologist->getExperienceYears() * 0.3;
    }
    
    double totalRisk = baseRisk + doseRisk + bodyPartRisk + patientRisk + frequencyRisk + radiologistExpertiseRisk;
    return std::max(0.0, std::min(totalRisk, 100.0));
}

bool XRay::requiresFollowUpScan() const {
    bool poorImageQuality = imageQuality < 70;
    bool highRadiationDose = radiationDose > 0.5;
    bool criticalBodyPart = bodyPart == "Spine" || bodyPart == "Skull";
    
    bool multiplePreviousScans = scannedPatients.size() >= 10;
    bool complexCase = false;
    
    for (const auto& patient : scannedPatients) {
        if (patient->calculateHealthRiskScore() > 60.0) {
            complexCase = true;
            break;
        }
    }
    
    bool specialistInvolved = false;
    for (const auto& radiologist : interpretingRadiologists) {
        if (radiologist->canInterpretComplexCases()) {
            specialistInvolved = true;
            break;
        }
    }
    
    return poorImageQuality || highRadiationDose || criticalBodyPart || 
           (multiplePreviousScans && complexCase && !specialistInvolved);
}

double XRay::calculateDiagnosticAccuracy() const {
    double baseAccuracy = getAccuracy();
    
    double imageQualityAccuracy = imageQuality * 0.3;
    
    double radiologistAccuracy = 0.0;
    for (const auto& radiologist : interpretingRadiologists) {
        radiologistAccuracy += radiologist->calculateDiagnosticAccuracy() * 0.2;
    }
    
    double patientAccuracy = 0.0;
    for (const auto& patient : scannedPatients) {
        if (patient->calculateHealthRiskScore() < 50.0) {
            patientAccuracy += 1.0;
        }
    }
    
    double bodyPartAccuracy = 0.0;
    if (bodyPart == "Chest") bodyPartAccuracy = 8.0;
    else if (bodyPart == "Extremity") bodyPartAccuracy = 10.0;
    else if (bodyPart == "Dental") bodyPartAccuracy = 12.0;
    
    double radiationAccuracy = radiationDose < 0.2 ? 5.0 : 0.0;
    
    double totalAccuracy = baseAccuracy + imageQualityAccuracy + radiologistAccuracy + 
                          patientAccuracy + bodyPartAccuracy + radiationAccuracy;
    return std::min(totalAccuracy, 100.0);
}

void XRay::addScannedPatient(Patient* patient) {
    if (patient) {
        scannedPatients.push_back(patient);
    }
}

void XRay::removeScannedPatient(const std::string& patientId) {
    scannedPatients.erase(
        std::remove_if(scannedPatients.begin(), scannedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        scannedPatients.end()
    );
}

std::vector<Patient*> XRay::getScannedPatients() const {
    return scannedPatients;
}

void XRay::addInterpretingRadiologist(Radiologist* radiologist) {
    if (radiologist) {
        interpretingRadiologists.push_back(radiologist);
    }
}

void XRay::removeInterpretingRadiologist(const std::string& radiologistId) {
    interpretingRadiologists.erase(
        std::remove_if(interpretingRadiologists.begin(), interpretingRadiologists.end(),
            [&radiologistId](Radiologist* radiologist) {
                return radiologist->getId() == radiologistId;
            }),
        interpretingRadiologists.end()
    );
}

std::vector<Radiologist*> XRay::getInterpretingRadiologists() const {
    return interpretingRadiologists;
}
