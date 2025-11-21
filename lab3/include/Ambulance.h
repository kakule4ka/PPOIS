#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <vector>

class Patient;
class EmergencyCase;
class MedicalEquipment;

class Ambulance {
private:
    std::string id;
    std::string type;
    bool availabilityStatus;
    double responseTime;
    int capacity;
    std::vector<Patient*> transportedPatients;
    std::vector<EmergencyCase*> handledEmergencies;
    std::vector<MedicalEquipment*> onboardEquipment;

public:
    Ambulance(const std::string& id, const std::string& type, bool available);
    
    double calculateEmergencyResponseScore() const;
    bool canHandleCriticalTransport() const;
    double calculateEquipmentReadiness() const;
    
    void addTransportedPatient(Patient* patient);
    void removeTransportedPatient(const std::string& patientId);
    std::vector<Patient*> getTransportedPatients() const;
    
    void addHandledEmergency(EmergencyCase* emergency);
    void removeHandledEmergency(const std::string& emergencyId);
    std::vector<EmergencyCase*> getHandledEmergencies() const;
    
    void addOnboardEquipment(MedicalEquipment* equipment);
    void removeOnboardEquipment(const std::string& equipmentId);
    std::vector<MedicalEquipment*> getOnboardEquipment() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    bool isAvailable() const { return availabilityStatus; }
    void setResponseTime(double time) { responseTime = time; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    double getResponseTime() const { return responseTime; }
    int getCapacity() const { return capacity; }
};

#endif
