#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
#include <vector>

class TreatmentPlan;
class Patient;

class Medication {
private:
    std::string id;
    std::string name;
    std::string type;
    double dosageMg;
    int frequencyPerDay;
    double costPerUnit;
    bool brandStatus;
    std::vector<TreatmentPlan*> treatmentPlans;
    std::vector<Patient*> allergicPatients;

public:
    Medication(const std::string& id, const std::string& name, const std::string& type, double dosage);
    
    double calculateDailyCost() const;
    bool hasSideEffects() const;
    double calculateEffectivenessScore() const;
    bool isSuitableForElderly() const;
    std::string determineAdministrationComplexity() const;
    
    void addTreatmentPlan(TreatmentPlan* plan);
    void removeTreatmentPlan(const std::string& planId);
    std::vector<TreatmentPlan*> getTreatmentPlans() const;
    
    void addAllergicPatient(Patient* patient);
    void removeAllergicPatient(const std::string& patientId);
    std::vector<Patient*> getAllergicPatients() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    double getDosageMg() const { return dosageMg; }
    int getFrequencyPerDay() const { return frequencyPerDay; }
    void setFrequencyPerDay(int freq) { frequencyPerDay = freq; }
    void setCostPerUnit(double cost) { costPerUnit = cost; }
    void setBrandStatus(bool brand) { brandStatus = brand; }
    bool isBrandName() const { return brandStatus; }
};

#endif
