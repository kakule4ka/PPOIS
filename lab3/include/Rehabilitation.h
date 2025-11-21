#ifndef REHABILITATION_H
#define REHABILITATION_H

#include <string>
#include <vector>

class Patient;
class PhysicalTherapist;
class TreatmentPlan;

class Rehabilitation {
private:
    std::string id;
    std::string type;
    int durationWeeks;
    double successRate;
    std::vector<Patient*> rehabPatients;
    std::vector<PhysicalTherapist*> assignedTherapists;
    std::vector<TreatmentPlan*> rehabPlans;

public:
    Rehabilitation(const std::string& id, const std::string& type, int duration);
    
    double calculateRecoveryProbability() const;
    bool requiresIntensiveTherapy() const;
    double calculateFunctionalImprovement() const;
    
    void addRehabPatient(Patient* patient);
    void removeRehabPatient(const std::string& patientId);
    std::vector<Patient*> getRehabPatients() const;
    
    void addAssignedTherapist(PhysicalTherapist* therapist);
    void removeAssignedTherapist(const std::string& therapistId);
    std::vector<PhysicalTherapist*> getAssignedTherapists() const;
    
    void addRehabPlan(TreatmentPlan* plan);
    void removeRehabPlan(const std::string& planId);
    std::vector<TreatmentPlan*> getRehabPlans() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    int getDurationWeeks() const { return durationWeeks; }
    void setSuccessRate(double rate) { successRate = rate; }
    double getSuccessRate() const { return successRate; }
};

#endif
