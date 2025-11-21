#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

class MedicalRecord;
class TreatmentPlan;

class Patient {
private:
    std::string id;
    std::string name;
    int age;
    std::string bloodType;
    bool isAdmitted;
    double weight;
    double height;
    std::vector<MedicalRecord*> medicalHistory;
    TreatmentPlan* currentTreatmentPlan;

public:
    Patient(const std::string& id, const std::string& name, int age, const std::string& bloodType);
    
    double calculateBMI() const;
    bool isEligibleForSurgery() const;
    double calculateHealthRiskScore() const;
    bool needsRegularCheckup() const;
    std::string determinePriorityLevel() const;
    
    void addMedicalRecord(MedicalRecord* record);
    void removeMedicalRecord(const std::string& recordId);
    std::vector<MedicalRecord*> getMedicalHistory() const;
    
    void setTreatmentPlan(TreatmentPlan* plan);
    TreatmentPlan* getTreatmentPlan() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getBloodType() const { return bloodType; }
    bool isCurrentlyAdmitted() const { return isAdmitted; }
    void setAdmitted(bool admitted) { isAdmitted = admitted; }
    void setWeight(double w) { weight = w; }
    void setHeight(double h) { height = h; }
};

#endif
