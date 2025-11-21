#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <string>
#include <vector>

class MedicalRecord;
class TreatmentPlan;

class Diagnosis {
private:
    std::string id;
    std::string name;
    std::string category;
    int severity;
    bool isChronic;
    std::string icdCode;
    std::vector<MedicalRecord*> medicalRecords;
    std::vector<TreatmentPlan*> recommendedPlans;

public:
    Diagnosis(const std::string& id, const std::string& name, const std::string& category);
    
    double calculateTreatmentComplexity() const;
    bool requiresSpecialist() const;
    double calculateRecoveryTime() const;
    
    void addMedicalRecord(MedicalRecord* record);
    void removeMedicalRecord(const std::string& recordId);
    std::vector<MedicalRecord*> getMedicalRecords() const;
    
    void addRecommendedPlan(TreatmentPlan* plan);
    void removeRecommendedPlan(const std::string& planId);
    std::vector<TreatmentPlan*> getRecommendedPlans() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    void setSeverity(int severity) { this->severity = severity; }
    void setIsChronic(bool chronic) { isChronic = chronic; }
    void setIcdCode(const std::string& code) { icdCode = code; }
    int getSeverity() const { return severity; }
    bool getIsChronic() const { return isChronic; }
    std::string getIcdCode() const { return icdCode; }
};

#endif
