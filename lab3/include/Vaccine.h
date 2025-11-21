#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include <vector>

class Patient;
class Pediatrician;

class Vaccine {
private:
    std::string id;
    std::string name;
    std::string type;
    double effectiveness;
    int recommendedAge;
    int boosterInterval;
    std::vector<Patient*> vaccinatedPatients;
    std::vector<Pediatrician*> administeringDoctors;

public:
    Vaccine(const std::string& id, const std::string& name, const std::string& type, double effectiveness);
    
    double calculateProtectionLevel() const;
    bool requiresBooster() const;
    double calculateHerdImmunityPotential() const;
    
    void addVaccinatedPatient(Patient* patient);
    void removeVaccinatedPatient(const std::string& patientId);
    std::vector<Patient*> getVaccinatedPatients() const;
    
    void addAdministeringDoctor(Pediatrician* doctor);
    void removeAdministeringDoctor(const std::string& doctorId);
    std::vector<Pediatrician*> getAdministeringDoctors() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    double getEffectiveness() const { return effectiveness; }
    void setRecommendedAge(int age) { recommendedAge = age; }
    void setBoosterInterval(int interval) { boosterInterval = interval; }
    int getRecommendedAge() const { return recommendedAge; }
    int getBoosterInterval() const { return boosterInterval; }
};

#endif
