#include "MRI.h"
#include "Patient.h"
#include "Radiologist.h"
#include <algorithm>
#include <cmath>

MRI::MRI(const std::string& id, const std::string& name, const std::string& scanType)
    : MedicalDevice(id, name, "Advanced Imaging"), scanType(scanType), magneticStrength(1.5), scanDuration(30) {}

double MRI::calculateScanQuality() const {
    double baseQuality = getAccuracy();
    
    double strengthQuality = magneticStrength * 10.0;
    
    double durationQuality = 0.0;
    if (scanDuration >= 45) durationQuality = 15.0;
    else if (scanDuration >= 30) durationQuality = 10.0;
    else durationQuality = 5.0;
    
    double specialistQuality = 0.0;
    for (const auto& specialist : mriSpecialists) {
        specialistQuality += specialist->getExperienceYears() * 0.5;
    }
    
    double patientQuality = 0.0;
    for (const auto& patient : mriPatients) {
        if (patient->calculateHealthRiskScore() < 60.0) {
            patientQuality += 1.5;
        }
    }
    
    double scanTypeQuality = 0.0;
    if (scanType == "Functional") scanTypeQuality = 12.0;
    else if (scanType == "Contrast") scanTypeQuality = 10.0;
    else if (scanType == "Standard") scanTypeQuality = 8.0;
    
    double totalQuality = baseQuality + strengthQuality + durationQuality + 
                         specialistQuality + patientQuality + scanTypeQuality;
    return std::min(totalQuality, 100.0);
}

bool MRI::requiresContrast() const {
    bool complexScanType = scanType == "Functional" || scanType == "Angiography";
    bool highMagneticStrength = magneticStrength >= 3.0;
    
    bool diagnosticChallenge = false;
    for (const auto& patient : mriPatients) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            diagnosticChallenge = true;
            break;
        }
    }
    
    bool specialistRecommendation = false;
    for (const auto& specialist : mriSpecialists) {
        if (specialist->canInterpretComplexCases()) {
            specialistRecommendation = true;
            break;
        }
    }
    
    bool previousInconclusive = mriPatients.size() >= 5;
    
    return complexScanType || highMagneticStrength || 
           (diagnosticChallenge && specialistRecommendation && previousInconclusive);
}

double MRI::calculateDiagnosticPrecision() const {
    double basePrecision = getAccuracy();
    
    double magneticPrecision = magneticStrength * 8.0;
    
    double specialistPrecision = 0.0;
    for (const auto& specialist : mriSpecialists) {
        specialistPrecision += specialist->calculateDiagnosticAccuracy() * 0.3;
    }
    
    double patientStabilityPrecision = 0.0;
    for (const auto& patient : mriPatients) {
        if (patient->calculateHealthRiskScore() < 50.0) {
            patientStabilityPrecision += 2.0;
        }
    }
    
    double scanTypePrecision = 0.0;
    if (scanType == "Neurological") scanTypePrecision = 15.0;
    else if (scanType == "Musculoskeletal") scanTypePrecision = 12.0;
    else if (scanType == "Abdominal") scanTypePrecision = 10.0;
    
    double durationPrecision = scanDuration > 20 ? 8.0 : 4.0;
    
    double totalPrecision = basePrecision + magneticPrecision + specialistPrecision + 
                           patientStabilityPrecision + scanTypePrecision + durationPrecision;
    return std::min(totalPrecision, 100.0);
}

void MRI::addMRIPatient(Patient* patient) {
    if (patient) {
        mriPatients.push_back(patient);
    }
}

void MRI::removeMRIPatient(const std::string& patientId) {
    mriPatients.erase(
        std::remove_if(mriPatients.begin(), mriPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        mriPatients.end()
    );
}

std::vector<Patient*> MRI::getMRIPatients() const {
    return mriPatients;
}

void MRI::addMRISpecialist(Radiologist* specialist) {
    if (specialist) {
        mriSpecialists.push_back(specialist);
    }
}

void MRI::removeMRISpecialist(const std::string& specialistId) {
    mriSpecialists.erase(
        std::remove_if(mriSpecialists.begin(), mriSpecialists.end(),
            [&specialistId](Radiologist* specialist) {
                return specialist->getId() == specialistId;
            }),
        mriSpecialists.end()
    );
}

std::vector<Radiologist*> MRI::getMRISpecialists() const {
    return mriSpecialists;
}
