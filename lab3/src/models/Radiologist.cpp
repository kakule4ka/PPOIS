#include "Radiologist.h"
#include "MedicalDevice.h"
#include <algorithm>

Radiologist::Radiologist(const std::string& id, const std::string& name, int experience, 
                        const std::string& license, int maxPatients, int scans, double accuracy)
    : Doctor(id, name, "Radiology", experience, license, maxPatients),
      scansInterpreted(scans), diagnosticAccuracy(accuracy) {}

double Radiologist::calculateDiagnosticAccuracy() const {
    double baseAccuracy = diagnosticAccuracy;
    
    double experienceBonus = getExperienceYears() * 0.8;
    double scanVolumeBonus = scansInterpreted * 0.05;
    
    double equipmentBonus = 0.0;
    for (const auto& equipment : imagingEquipment) {
        if (equipment->calculateDiagnosticValue() > 85.0) {
            equipmentBonus += 2.0;
        }
    }
    
    double totalAccuracy = baseAccuracy + experienceBonus + scanVolumeBonus + equipmentBonus;
    return std::min(totalAccuracy, 100.0);
}

bool Radiologist::canInterpretComplexCases() const {
    bool sufficientExperience = getExperienceYears() >= 8;
    bool highAccuracy = calculateDiagnosticAccuracy() >= 90.0;
    bool advancedEquipment = false;
    
    for (const auto& equipment : imagingEquipment) {
        if (equipment->getCategory() == "Advanced Imaging") {
            advancedEquipment = true;
            break;
        }
    }
    
    return sufficientExperience && highAccuracy && advancedEquipment;
}

void Radiologist::addImagingEquipment(MedicalDevice* equipment) {
    if (equipment) {
        imagingEquipment.push_back(equipment);
    }
}

void Radiologist::removeImagingEquipment(const std::string& equipmentId) {
    imagingEquipment.erase(
        std::remove_if(imagingEquipment.begin(), imagingEquipment.end(),
            [&equipmentId](MedicalDevice* equipment) {
                return equipment->getId() == equipmentId;
            }),
        imagingEquipment.end()
    );
}

std::vector<MedicalDevice*> Radiologist::getImagingEquipment() const {
    return imagingEquipment;
}
