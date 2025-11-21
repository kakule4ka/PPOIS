#ifndef ICU_H
#define ICU_H

#include <string>
#include <vector>

class Patient;
class Nurse;
class MedicalEquipment;

class ICU {
private:
    std::string id;
    std::string type;
    int bedCount;
    int occupiedBeds;
    double mortalityRate;
    std::vector<Patient*> criticalPatients;
    std::vector<Nurse*> specializedNurses;
    std::vector<MedicalEquipment*> lifeSupportEquipment;

public:
    ICU(const std::string& id, const std::string& type, int bedCount);
    
    double calculateOccupancyRate() const;
    bool canAdmitCriticalPatient() const;
    double calculatePatientSurvivalProbability() const;
    
    void addCriticalPatient(Patient* patient);
    void removeCriticalPatient(const std::string& patientId);
    std::vector<Patient*> getCriticalPatients() const;
    
    void addSpecializedNurse(Nurse* nurse);
    void removeSpecializedNurse(const std::string& nurseId);
    std::vector<Nurse*> getSpecializedNurses() const;
    
    void addLifeSupportEquipment(MedicalEquipment* equipment);
    void removeLifeSupportEquipment(const std::string& equipmentId);
    std::vector<MedicalEquipment*> getLifeSupportEquipment() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    int getBedCount() const { return bedCount; }
    void setOccupiedBeds(int occupied) { occupiedBeds = occupied; }
    void setMortalityRate(double rate) { mortalityRate = rate; }
    int getOccupiedBeds() const { return occupiedBeds; }
    double getMortalityRate() const { return mortalityRate; }
};

#endif
