#ifndef REHABILITATIONSPECIALIST_H
#define REHABILITATIONSPECIALIST_H

#include <string>
#include <vector>

class Patient;

class RehabilitationSpecialist {
private:
    std::string id;
    std::string name;
    std::string rehabType;
    int experienceYears;
    std::vector<Patient*> rehabPatients;

public:
    RehabilitationSpecialist(const std::string& id, const std::string& name, const std::string& rehabType, int experience);
    
    double calculateRecoverySuccessRate() const;
    bool requiresAdvancedTechniques() const;
    
    void addRehabPatient(Patient* patient);
    void removeRehabPatient(const std::string& patientId);
    std::vector<Patient*> getRehabPatients() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getRehabType() const { return rehabType; }
    int getExperienceYears() const { return experienceYears; }
};

#endif
