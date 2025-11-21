#ifndef SURGERY_H
#define SURGERY_H

#include <string>
#include <vector>

class Patient;
class Doctor;
class OperatingRoom;

class Surgery {
private:
    std::string id;
    std::string type;
    int durationMinutes;
    double successRate;
    std::string status;
    int complexityLevel;
    Patient* patient;
    Doctor* surgeon;
    OperatingRoom* operatingRoom;

public:
    Surgery(const std::string& id, const std::string& type, int duration);
    
    double calculateRiskLevel() const;
    bool requiresSpecialEquipment() const;
    double calculateRecoveryProbability() const;
    
    void setPatient(Patient* patient);
    Patient* getPatient() const;
    
    void setSurgeon(Doctor* surgeon);
    Doctor* getSurgeon() const;
    
    void setOperatingRoom(OperatingRoom* room);
    OperatingRoom* getOperatingRoom() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    int getDurationMinutes() const { return durationMinutes; }
    void setSuccessRate(double rate) { successRate = rate; }
    void setStatus(const std::string& status) { this->status = status; }
    void setComplexityLevel(int level) { complexityLevel = level; }
    double getSuccessRate() const { return successRate; }
    std::string getStatus() const { return status; }
    int getComplexityLevel() const { return complexityLevel; }
};

#endif
