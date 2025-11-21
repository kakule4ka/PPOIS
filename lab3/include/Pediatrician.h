#ifndef PEDIATRICIAN_H
#define PEDIATRICIAN_H

#include "Doctor.h"
#include <string>
#include <vector>

class Patient;
class Vaccine;

class Pediatrician : public Doctor {
private:
    int pediatricCases;
    double vaccinationRate;
    std::string ageSpecialization;
    std::vector<Patient*> pediatricPatients;
    std::vector<Vaccine*> administeredVaccines;

public:
    Pediatrician(const std::string& id, const std::string& name, int experience, 
                const std::string& license, int maxPatients, int cases, double vaxRate);
    
    double calculateChildDevelopmentScore(const Patient* child) const;
    bool canHandleRarePediatricConditions() const;
    double calculatePreventiveCareEffectiveness() const;
    
    void addPediatricPatient(Patient* patient);
    void removePediatricPatient(const std::string& patientId);
    std::vector<Patient*> getPediatricPatients() const;
    
    void addAdministeredVaccine(Vaccine* vaccine);
    void removeAdministeredVaccine(const std::string& vaccineId);
    std::vector<Vaccine*> getAdministeredVaccines() const;
    
    int getPediatricCases() const { return pediatricCases; }
    double getVaccinationRate() const { return vaccinationRate; }
    std::string getAgeSpecialization() const { return ageSpecialization; }
};

#endif
