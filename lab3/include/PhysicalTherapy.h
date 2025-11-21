#ifndef PHYSICALTHERAPY_H
#define PHYSICALTHERAPY_H

#include <string>
#include <vector>

class Patient;
class Rehabilitation;

class PhysicalTherapy {
private:
    std::string id;
    std::string name;
    std::string specialization;
    int experienceYears;
    int sessionsPerWeek;
    std::vector<Patient*> therapyPatients;
    std::vector<Rehabilitation*> rehabPrograms;

public:
    PhysicalTherapy(const std::string& id, const std::string& name, const std::string& specialization, int experience);
    
    double calculateTherapyEffectiveness() const;
    bool canHandleComplexCases() const;
    double calculatePatientProgressRate() const;
    
    void addTherapyPatient(Patient* patient);
    void removeTherapyPatient(const std::string& patientId);
    std::vector<Patient*> getTherapyPatients() const;
    
    void addRehabProgram(Rehabilitation* rehab);
    void removeRehabProgram(const std::string& rehabId);
    std::vector<Rehabilitation*> getRehabPrograms() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    int getExperienceYears() const { return experienceYears; }
    void setSessionsPerWeek(int sessions) { sessionsPerWeek = sessions; }
    int getSessionsPerWeek() const { return sessionsPerWeek; }
};

#endif
