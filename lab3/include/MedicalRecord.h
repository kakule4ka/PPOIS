#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <string>
#include <vector>

class Patient;
class Diagnosis;

class MedicalRecord {
private:
    std::string id;
    std::string description;
    std::string date;
    std::string doctorNotes;
    int severityLevel;
    bool isChronic;
    Patient* patient;
    std::vector<Diagnosis*> diagnoses;

public:
    MedicalRecord(const std::string& id, const std::string& description, const std::string& date);
    
    double calculateTreatmentComplexity() const;
    bool indicatesCriticalCondition() const;
    double calculateRecoveryProbability() const;
    bool requiresFollowUp() const;
    std::string determineUrgencyLevel() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void addDiagnosis(Diagnosis* diagnosis);
    void removeDiagnosis(const std::string& diagnosisId);
    std::vector<Diagnosis*> getDiagnoses() const;
    
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getDate() const { return date; }
    void setDoctorNotes(const std::string& notes) { doctorNotes = notes; }
    void setSeverityLevel(int level) { severityLevel = level; }
    void setIsChronic(bool chronic) { isChronic = chronic; }
    bool isChronicCondition() const { return isChronic; }
};

#endif
