#include "LaboratoryTest.h"
#include "Patient.h"
#include "Doctor.h"
#include <algorithm>
#include <cmath>

LaboratoryTest::LaboratoryTest(const std::string& id, const std::string& name, const std::string& type)
    : id(id), name(name), type(type), cost(0.0), processingTime(24), accuracy(95.0) {}

double LaboratoryTest::calculateDiagnosticValue() const {
    double baseValue = accuracy;
    
    double typeMultiplier = 1.0;
    if (type == "Genetic") typeMultiplier = 1.3;
    else if (type == "Blood") typeMultiplier = 1.1;
    else if (type == "Microbiology") typeMultiplier = 1.2;
    
    double costEfficiency = cost > 0 ? (100.0 / cost) * 10.0 : 0.0;
    double speedBonus = processingTime < 12 ? 10.0 : (processingTime < 24 ? 5.0 : 0.0);
    
    double patientComplexity = 0.0;
    for (const auto& patient : patients) {
        patientComplexity += patient->calculateHealthRiskScore() * 0.05;
    }
    
    double doctorExpertise = 0.0;
    for (const auto& doctor : requestingDoctors) {
        doctorExpertise += doctor->getExperienceYears() * 0.1;
    }
    
    double totalValue = (baseValue * typeMultiplier) + costEfficiency + speedBonus + patientComplexity + doctorExpertise;
    return std::min(totalValue, 100.0);
}

bool LaboratoryTest::isHighPriority() const {
    bool rapidProcessing = processingTime <= 6;
    bool highAccuracy = accuracy >= 98.0;
    bool criticalType = type == "Toxicology" || type == "Infectious Disease" || type == "Cancer Marker";
    
    bool hasCriticalPatients = false;
    for (const auto& patient : patients) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            hasCriticalPatients = true;
            break;
        }
    }
    
    bool requestedBySpecialists = false;
    for (const auto& doctor : requestingDoctors) {
        if (doctor->getSpecialization() == "Oncology" || doctor->getSpecialization() == "Infectious Disease") {
            requestedBySpecialists = true;
            break;
        }
    }
    
    return rapidProcessing || highAccuracy || criticalType || hasCriticalPatients || requestedBySpecialists;
}

double LaboratoryTest::calculateResultReliability() const {
    double baseReliability = accuracy;
    
    double processingPenalty = processingTime > 48 ? 10.0 : 0.0;
    double costPenalty = cost < 10.0 ? 5.0 : 0.0;
    
    double patientConsistency = 0.0;
    if (patients.size() >= 5) {
        patientConsistency = 5.0;
    }
    
    double doctorConsistency = 0.0;
    if (requestingDoctors.size() >= 3) {
        doctorConsistency = 3.0;
    }
    
    double typeReliability = 0.0;
    if (type == "Blood Chemistry") typeReliability = 3.0;
    else if (type == "Genetic") typeReliability = -2.0;
    
    double totalReliability = baseReliability - processingPenalty - costPenalty + patientConsistency + doctorConsistency + typeReliability;
    return std::max(0.0, std::min(totalReliability, 100.0));
}

void LaboratoryTest::addPatient(Patient* patient) {
    if (patient) {
        patients.push_back(patient);
    }
}

void LaboratoryTest::removePatient(const std::string& patientId) {
    patients.erase(
        std::remove_if(patients.begin(), patients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        patients.end()
    );
}

std::vector<Patient*> LaboratoryTest::getPatients() const {
    return patients;
}

void LaboratoryTest::addRequestingDoctor(Doctor* doctor) {
    if (doctor) {
        requestingDoctors.push_back(doctor);
    }
}

void LaboratoryTest::removeRequestingDoctor(const std::string& doctorId) {
    requestingDoctors.erase(
        std::remove_if(requestingDoctors.begin(), requestingDoctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        requestingDoctors.end()
    );
}

std::vector<Doctor*> LaboratoryTest::getRequestingDoctors() const {
    return requestingDoctors;
}
