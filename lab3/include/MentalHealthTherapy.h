#ifndef MENTALHEALTHTHERAPY_H
#define MENTALHEALTHTHERAPY_H

#include <string>
#include <vector>

class Patient;
class TreatmentPlan;

class MentalHealthTherapy {
private:
    std::string id;
    std::string therapyType;
    int sessionDuration;
    double successRate;
    std::vector<Patient*> mentalHealthPatients;
    std::vector<TreatmentPlan*> therapyPlans;

public:
    MentalHealthTherapy(const std::string& id, const std::string& therapyType, int duration);
    
    double calculateTherapeuticOutcome() const;
    bool requiresSpecializedApproach() const;
    double calculatePatientEngagement() const;
    
    void addMentalHealthPatient(Patient* patient);
    void removeMentalHealthPatient(const std::string& patientId);
    std::vector<Patient*> getMentalHealthPatients() const;
    
    void addTherapyPlan(TreatmentPlan* plan);
    void removeTherapyPlan(const std::string& planId);
    std::vector<TreatmentPlan*> getTherapyPlans() const;
    
    std::string getId() const { return id; }
    std::string getTherapyType() const { return therapyType; }
    int getSessionDuration() const { return sessionDuration; }
    void setSuccessRate(double rate) { successRate = rate; }
    double getSuccessRate() const { return successRate; }
};

#endif
