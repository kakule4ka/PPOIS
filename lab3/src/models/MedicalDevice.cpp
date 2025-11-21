#include "MedicalDevice.h"
#include "Patient.h"
#include "Doctor.h"
#include <algorithm>
#include <cmath>

MedicalDevice::MedicalDevice(const std::string& id, const std::string& name, const std::string& category)
    : id(id), name(name), category(category), accuracy(95.0), calibrationInterval(90), usageCount(0) {}

double MedicalDevice::calculateReliabilityScore() const {
    double baseScore = accuracy;
    
    double usageScore = 0.0;
    if (usageCount < 1000) {
        usageScore = 10.0;
    } else if (usageCount < 5000) {
        usageScore = 5.0;
    } else {
        usageScore = 2.0;
    }
    
    double calibrationScore = (180 - calibrationInterval) * 0.2;
    
    double doctorExpertiseScore = 0.0;
    for (const auto& doctor : operatingDoctors) {
        doctorExpertiseScore += doctor->getExperienceYears() * 0.1;
    }
    
    double patientDiversityScore = testedPatients.size() * 0.5;
    
    double categoryBonus = 0.0;
    if (category == "Diagnostic") categoryBonus = 8.0;
    else if (category == "Monitoring") categoryBonus = 6.0;
    else if (category == "Therapeutic") categoryBonus = 5.0;
    
    double totalScore = baseScore + usageScore + calibrationScore + doctorExpertiseScore + 
                       patientDiversityScore + categoryBonus;
    return std::min(totalScore, 100.0);
}

bool MedicalDevice::needsCalibration() const {
    bool highUsage = usageCount >= calibrationInterval;
    bool lowAccuracy = accuracy < 90.0;
    bool complexDevice = category == "Diagnostic" || category == "Surgical";
    
    bool multipleUsers = operatingDoctors.size() >= 3;
    bool diversePatients = testedPatients.size() >= 50;
    
    bool recentCalibration = usageCount < calibrationInterval * 0.5;
    
    return (highUsage && complexDevice) || lowAccuracy || (multipleUsers && diversePatients && !recentCalibration);
}

double MedicalDevice::calculateDiagnosticValue() const {
    double baseValue = accuracy;
    
    double usageValue = std::min(usageCount * 0.01, 15.0);
    
    double doctorValue = 0.0;
    for (const auto& doctor : operatingDoctors) {
        if (doctor->calculatePatientSuccessRate() > 80.0) {
            doctorValue += 2.0;
        }
    }
    
    double patientValue = 0.0;
    for (const auto& patient : testedPatients) {
        if (patient->calculateHealthRiskScore() < 40.0) {
            patientValue += 1.0;
        }
    }
    
    double categoryValue = 0.0;
    if (category == "Imaging") categoryValue = 12.0;
    else if (category == "Laboratory") categoryValue = 10.0;
    else if (category == "Monitoring") categoryValue = 8.0;
    
    double calibrationValue = needsCalibration() ? -10.0 : 5.0;
    
    double totalValue = baseValue + usageValue + doctorValue + patientValue + categoryValue + calibrationValue;
    return std::max(0.0, std::min(totalValue, 100.0));
}

void MedicalDevice::addTestedPatient(Patient* patient) {
    if (patient) {
        testedPatients.push_back(patient);
        usageCount++;
    }
}

void MedicalDevice::removeTestedPatient(const std::string& patientId) {
    testedPatients.erase(
        std::remove_if(testedPatients.begin(), testedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        testedPatients.end()
    );
}

std::vector<Patient*> MedicalDevice::getTestedPatients() const {
    return testedPatients;
}

void MedicalDevice::addOperatingDoctor(Doctor* doctor) {
    if (doctor) {
        operatingDoctors.push_back(doctor);
    }
}

void MedicalDevice::removeOperatingDoctor(const std::string& doctorId) {
    operatingDoctors.erase(
        std::remove_if(operatingDoctors.begin(), operatingDoctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        operatingDoctors.end()
    );
}

std::vector<Doctor*> MedicalDevice::getOperatingDoctors() const {
    return operatingDoctors;
}
