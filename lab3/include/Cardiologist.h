#ifndef CARDIOLOGIST_H
#define CARDIOLOGIST_H

#include "Doctor.h"
#include <string>
#include <vector>

class Patient;
class MedicalEquipment;

class Cardiologist : public Doctor {
private:
    int cardiacProceduresPerformed;
    double successRateCardiacSurgery;
    std::string boardCertification;
    std::vector<Patient*> cardiacPatients;
    std::vector<MedicalEquipment*> specializedEquipment;

public:
    Cardiologist(const std::string& id, const std::string& name, int experience, 
                const std::string& license, int maxPatients, int procedures, double successRate);
    
    double calculateCardiacRiskAssessment(const Patient* patient) const;
    bool canPerformComplexProcedure() const;
    double calculateTreatmentEffectiveness() const;
    
    void addCardiacPatient(Patient* patient);
    void removeCardiacPatient(const std::string& patientId);
    std::vector<Patient*> getCardiacPatients() const;
    
    void addSpecializedEquipment(MedicalEquipment* equipment);
    void removeSpecializedEquipment(const std::string& equipmentId);
    std::vector<MedicalEquipment*> getSpecializedEquipment() const;
    
    int getCardiacProceduresPerformed() const { return cardiacProceduresPerformed; }
    double getSuccessRateCardiacSurgery() const { return successRateCardiacSurgery; }
    std::string getBoardCertification() const { return boardCertification; }
};

#endif
