#ifndef PHYSICALTHERAPIST_H
#define PHYSICALTHERAPIST_H

#include <string>
#include <vector>

class Patient;

class PhysicalTherapist {
private:
    std::string id;
    std::string name;
    std::string specialization;
    int experienceYears;
    std::vector<Patient*> therapyPatients;

public:
    PhysicalTherapist(const std::string& id, const std::string& name, const std::string& specialization, int experience);
    
    double calculateTherapyEffectiveness() const;
    bool canHandleComplexCases() const;
    
    void addTherapyPatient(Patient* patient);
    void removeTherapyPatient(const std::string& patientId);
    std::vector<Patient*> getTherapyPatients() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    int getExperienceYears() const { return experienceYears; }
};

#endif
