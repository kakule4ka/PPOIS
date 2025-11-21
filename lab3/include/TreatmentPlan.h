#ifndef TREATMENTPLAN_H
#define TREATMENTPLAN_H

#include <string>
#include <vector>

class Patient;
class Medication;

class TreatmentPlan {
private:
    std::string id;
    std::string description;
    int durationDays;
    double successRate;
    bool isActive;
    double cost;
    Patient* patient;
    std::vector<Medication*> prescribedMedications;

public:
    TreatmentPlan(const std::string& id, const std::string& description, int duration);
    
    double calculateTreatmentEffectiveness() const;
    bool isCostEffective() const;
    double calculateAdherenceProbability() const;
    bool needsModification() const;
    std::string determineComplexityLevel() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void addMedication(Medication* medication);
    void removeMedication(const std::string& medicationId);
    std::vector<Medication*> getPrescribedMedications() const;
    
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    int getDurationDays() const { return durationDays; }
    void setSuccessRate(double rate) { successRate = rate; }
    void setIsActive(bool active) { isActive = active; }
    void setCost(double cost) { this->cost = cost; }
    bool getIsActive() const { return isActive; }
    double getCost() const { return cost; }
};

#endif
