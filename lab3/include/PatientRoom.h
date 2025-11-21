#ifndef PATIENTROOM_H
#define PATIENTROOM_H

#include <string>
#include <vector>

class Patient;
class Nurse;
class MedicalEquipment;

class PatientRoom {
private:
    std::string id;
    std::string type;
    int capacity;
    bool hasPrivateBathroom;
    double cleanlinessLevel;
    std::vector<Patient*> assignedPatients;
    std::vector<Nurse*> attendingNurses;
    std::vector<MedicalEquipment*> roomEquipment;

public:
    PatientRoom(const std::string& id, const std::string& type, int capacity, bool privateBath);
    
    double calculateRoomUtilization() const;
    bool isSuitableForIsolation() const;
    double calculatePatientComfortScore() const;
    
    void addPatient(Patient* patient);
    void removePatient(const std::string& patientId);
    std::vector<Patient*> getAssignedPatients() const;
    
    void addNurse(Nurse* nurse);
    void removeNurse(const std::string& nurseId);
    std::vector<Nurse*> getAttendingNurses() const;
    
    void addEquipment(MedicalEquipment* equipment);
    void removeEquipment(const std::string& equipmentId);
    std::vector<MedicalEquipment*> getRoomEquipment() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    int getCapacity() const { return capacity; }
    bool getHasPrivateBathroom() const { return hasPrivateBathroom; }
    void setCleanlinessLevel(double level) { cleanlinessLevel = level; }
    double getCleanlinessLevel() const { return cleanlinessLevel; }
};

#endif
