#ifndef NEUROLOGIST_H
#define NEUROLOGIST_H

#include "Doctor.h"
#include <string>
#include <vector>

class Patient;
class LaboratoryTest;

class Neurologist : public Doctor {
private:
    int neurologicalAssessments;
    double diagnosticAccuracy;
    std::string subSpecialty;
    std::vector<Patient*> neurologicalPatients;
    std::vector<LaboratoryTest*> specializedTests;

public:
    Neurologist(const std::string& id, const std::string& name, int experience, 
               const std::string& license, int maxPatients, int assessments, double accuracy);
    
    double calculateNeurologicalDisorderProbability(const Patient* patient) const;
    bool canDiagnoseComplexConditions() const;
    double calculateTherapeuticSuccessRate() const;
    
    void addNeurologicalPatient(Patient* patient);
    void removeNeurologicalPatient(const std::string& patientId);
    std::vector<Patient*> getNeurologicalPatients() const;
    
    void addSpecializedTest(LaboratoryTest* test);
    void removeSpecializedTest(const std::string& testId);
    std::vector<LaboratoryTest*> getSpecializedTests() const;
    
    int getNeurologicalAssessments() const { return neurologicalAssessments; }
    double getDiagnosticAccuracy() const { return diagnosticAccuracy; }
    std::string getSubSpecialty() const { return subSpecialty; }
};

#endif
