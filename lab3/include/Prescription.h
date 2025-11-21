#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>
#include <vector>

class Patient;
class Doctor;
class Medication;

class Prescription {
private:
    std::string id;
    std::string dateIssued;
    std::string instructions;
    int refillsRemaining;
    bool isActive;
    Patient* patient;
    Doctor* prescribingDoctor;
    std::vector<Medication*> prescribedMedications;

public:
    Prescription(const std::string& id, const std::string& dateIssued, const std::string& instructions);
    
    double calculateAdherenceProbability() const;
    bool requiresRenewal() const;
    double calculateTherapeuticEffectiveness() const;
    bool hasDrugInteractions() const;
    std::string determineComplexityLevel() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void setPrescribingDoctor(Doctor* doctor);
    Doctor* getPrescribingDoctor() const;
    
    void addMedication(Medication* medication);
    void removeMedication(const std::string& medicationId);
    std::vector<Medication*> getPrescribedMedications() const;
    
    std::string getId() const { return id; }
    std::string getDateIssued() const { return dateIssued; }
    std::string getInstructions() const { return instructions; }
    void setRefillsRemaining(int refills) { refillsRemaining = refills; }
    void setIsActive(bool active) { isActive = active; }
    int getRefillsRemaining() const { return refillsRemaining; }
    bool getIsActive() const { return isActive; }
};

#endif
