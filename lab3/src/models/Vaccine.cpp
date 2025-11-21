#include "Vaccine.h"
#include "Patient.h"
#include "Pediatrician.h"
#include <algorithm>
#include <cmath>

Vaccine::Vaccine(const std::string& id, const std::string& name, const std::string& type, double effectiveness)
    : id(id), name(name), type(type), effectiveness(effectiveness), recommendedAge(0), boosterInterval(0) {}

double Vaccine::calculateProtectionLevel() const {
    double baseProtection = effectiveness;
    
    double ageAppropriateProtection = 0.0;
    if (recommendedAge > 0) {
        ageAppropriateProtection = 10.0;
    }
    
    double boosterProtection = boosterInterval > 0 ? 8.0 : 5.0;
    
    double doctorExpertiseProtection = 0.0;
    for (const auto& doctor : administeringDoctors) {
        doctorExpertiseProtection += doctor->calculatePreventiveCareEffectiveness() * 0.1;
    }
    
    double patientComplianceProtection = 0.0;
    for (const auto& patient : vaccinatedPatients) {
        if (patient->getAge() >= recommendedAge && patient->getAge() <= recommendedAge + 5) {
            patientComplianceProtection += 2.0;
        }
    }
    
    double vaccineTypeProtection = 0.0;
    if (type == "Live") vaccineTypeProtection = 12.0;
    else if (type == "mRNA") vaccineTypeProtection = 15.0;
    else if (type == "Inactivated") vaccineTypeProtection = 10.0;
    
    double totalProtection = baseProtection + ageAppropriateProtection + boosterProtection + 
                            doctorExpertiseProtection + patientComplianceProtection + vaccineTypeProtection;
    return std::min(totalProtection, 100.0);
}

bool Vaccine::requiresBooster() const {
    bool hasBoosterSchedule = boosterInterval > 0;
    bool waningEffectiveness = effectiveness < 80.0;
    bool highRiskVaccine = type == "Live" || name.find("Flu") != std::string::npos;
    
    bool pediatricFocus = recommendedAge <= 18;
    bool extensiveUsage = vaccinatedPatients.size() >= 100;
    
    bool doctorRecommendation = false;
    for (const auto& doctor : administeringDoctors) {
        if (doctor->getVaccinationRate() > 90.0) {
            doctorRecommendation = true;
            break;
        }
    }
    
    return hasBoosterSchedule || waningEffectiveness || 
           (highRiskVaccine && pediatricFocus && extensiveUsage && doctorRecommendation);
}

double Vaccine::calculateHerdImmunityPotential() const {
    double basePotential = effectiveness * 0.7;
    
    double coveragePotential = (static_cast<double>(vaccinatedPatients.size()) / 1000.0) * 30.0;
    
    double doctorNetworkPotential = administeringDoctors.size() * 2.0;
    
    double ageGroupPotential = 0.0;
    if (recommendedAge <= 12) ageGroupPotential = 15.0;
    else if (recommendedAge <= 18) ageGroupPotential = 12.0;
    else ageGroupPotential = 8.0;
    
    double boosterPotential = boosterInterval > 0 ? 10.0 : 5.0;
    
    double vaccineStabilityPotential = 0.0;
    if (type == "mRNA") vaccineStabilityPotential = 8.0;
    else if (type == "Inactivated") vaccineStabilityPotential = 12.0;
    
    double totalPotential = basePotential + coveragePotential + doctorNetworkPotential + 
                           ageGroupPotential + boosterPotential + vaccineStabilityPotential;
    return std::min(totalPotential, 100.0);
}

void Vaccine::addVaccinatedPatient(Patient* patient) {
    if (patient) {
        vaccinatedPatients.push_back(patient);
    }
}

void Vaccine::removeVaccinatedPatient(const std::string& patientId) {
    vaccinatedPatients.erase(
        std::remove_if(vaccinatedPatients.begin(), vaccinatedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        vaccinatedPatients.end()
    );
}

std::vector<Patient*> Vaccine::getVaccinatedPatients() const {
    return vaccinatedPatients;
}

void Vaccine::addAdministeringDoctor(Pediatrician* doctor) {
    if (doctor) {
        administeringDoctors.push_back(doctor);
    }
}

void Vaccine::removeAdministeringDoctor(const std::string& doctorId) {
    administeringDoctors.erase(
        std::remove_if(administeringDoctors.begin(), administeringDoctors.end(),
            [&doctorId](Pediatrician* doctor) {
                return doctor->getId() == doctorId;
            }),
        administeringDoctors.end()
    );
}

std::vector<Pediatrician*> Vaccine::getAdministeringDoctors() const {
    return administeringDoctors;
}
