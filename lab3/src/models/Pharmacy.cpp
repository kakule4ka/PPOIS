#include "Pharmacy.h"
#include "Medication.h"
#include "Patient.h"
#include "Doctor.h"
#include <algorithm>
#include <cmath>

Pharmacy::Pharmacy(const std::string& id, const std::string& name, int inventorySize)
    : id(id), name(name), inventorySize(inventorySize), prescriptionAccuracy(95.0) {}

double Pharmacy::calculateInventoryTurnover() const {
    if (inventorySize == 0) return 0.0;
    
    double medicationUsage = 0.0;
    for (const auto& medication : availableMedications) {
        if (medication->calculateDailyCost() > 0) {
            medicationUsage += medication->calculateEffectivenessScore() * 0.01;
        }
    }
    
    double patientDemand = servedPatients.size() * 2.0;
    double doctorPrescriptions = collaboratingDoctors.size() * 3.0;
    
    double baseTurnover = (medicationUsage + patientDemand + doctorPrescriptions) / inventorySize * 100.0;
    
    double accuracyBonus = prescriptionAccuracy * 0.2;
    double inventoryEfficiency = (static_cast<double>(availableMedications.size()) / inventorySize) * 20.0;
    
    double totalTurnover = baseTurnover + accuracyBonus + inventoryEfficiency;
    return std::min(totalTurnover, 100.0);
}

bool Pharmacy::canDispenseSpecializedMeds() const {
    bool hasSpecializedInventory = false;
    for (const auto& medication : availableMedications) {
        if (medication->getType() == "Chemotherapy" || medication->getType() == "Immunosuppressant" ||
            medication->getType() == "Biologic" || medication->getName().find("Special") != std::string::npos) {
            hasSpecializedInventory = true;
            break;
        }
    }
    
    bool highAccuracy = prescriptionAccuracy >= 98.0;
    bool adequateInventory = availableMedications.size() >= inventorySize * 0.7;
    
    bool hasSpecialistDoctors = false;
    for (const auto& doctor : collaboratingDoctors) {
        if (doctor->getSpecialization() == "Oncology" || doctor->getSpecialization() == "Rheumatology" ||
            doctor->getSpecialization() == "Infectious Disease") {
            hasSpecialistDoctors = true;
            break;
        }
    }
    
    bool servesComplexPatients = false;
    for (const auto& patient : servedPatients) {
        if (patient->calculateHealthRiskScore() > 60.0) {
            servesComplexPatients = true;
            break;
        }
    }
    
    return hasSpecializedInventory && highAccuracy && adequateInventory && 
           hasSpecialistDoctors && servesComplexPatients;
}

double Pharmacy::calculateServiceEfficiency() const {
    double baseEfficiency = prescriptionAccuracy;
    
    double inventoryEfficiency = (static_cast<double>(availableMedications.size()) / inventorySize) * 20.0;
    
    double patientServiceEfficiency = 0.0;
    if (!servedPatients.empty()) {
        double avgPatientHealth = 0.0;
        for (const auto& patient : servedPatients) {
            avgPatientHealth += patient->calculateHealthRiskScore();
        }
        avgPatientHealth /= servedPatients.size();
        patientServiceEfficiency = (100.0 - avgPatientHealth) * 0.2;
    }
    
    double doctorCollaborationEfficiency = collaboratingDoctors.size() * 2.0;
    
    double medicationEffectivenessEfficiency = 0.0;
    for (const auto& medication : availableMedications) {
        medicationEffectivenessEfficiency += medication->calculateEffectivenessScore() * 0.05;
    }
    
    double totalEfficiency = baseEfficiency + inventoryEfficiency + patientServiceEfficiency + 
                            doctorCollaborationEfficiency + medicationEffectivenessEfficiency;
    return std::min(totalEfficiency, 100.0);
}

void Pharmacy::addMedication(Medication* medication) {
    if (medication && availableMedications.size() < inventorySize) {
        availableMedications.push_back(medication);
    }
}

void Pharmacy::removeMedication(const std::string& medicationId) {
    availableMedications.erase(
        std::remove_if(availableMedications.begin(), availableMedications.end(),
            [&medicationId](Medication* medication) {
                return medication->getId() == medicationId;
            }),
        availableMedications.end()
    );
}

std::vector<Medication*> Pharmacy::getAvailableMedications() const {
    return availableMedications;
}

void Pharmacy::addServedPatient(Patient* patient) {
    if (patient) {
        servedPatients.push_back(patient);
    }
}

void Pharmacy::removeServedPatient(const std::string& patientId) {
    servedPatients.erase(
        std::remove_if(servedPatients.begin(), servedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        servedPatients.end()
    );
}

std::vector<Patient*> Pharmacy::getServedPatients() const {
    return servedPatients;
}

void Pharmacy::addCollaboratingDoctor(Doctor* doctor) {
    if (doctor) {
        collaboratingDoctors.push_back(doctor);
    }
}

void Pharmacy::removeCollaboratingDoctor(const std::string& doctorId) {
    collaboratingDoctors.erase(
        std::remove_if(collaboratingDoctors.begin(), collaboratingDoctors.end(),
            [&doctorId](Doctor* doctor) {
                return doctor->getId() == doctorId;
            }),
        collaboratingDoctors.end()
    );
}

std::vector<Doctor*> Pharmacy::getCollaboratingDoctors() const {
    return collaboratingDoctors;
}
