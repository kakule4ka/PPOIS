#ifndef OPERATINGROOM_H
#define OPERATINGROOM_H

#include <string>
#include <vector>

class Surgery;
class MedicalEquipment;
class Doctor;

class OperatingRoom {
private:
    std::string id;
    std::string type;
    bool availabilityStatus;
    double sterilizationLevel;
    int sizeSqm;
    std::vector<Surgery*> scheduledSurgeries;
    std::vector<MedicalEquipment*> surgicalEquipment;
    std::vector<Doctor*> authorizedSurgeons;

public:
    OperatingRoom(const std::string& id, const std::string& type, bool available);
    
    double calculateReadinessScore() const;
    bool canHandleComplexSurgery() const;
    double calculateEfficiencyRating() const;
    
    void addScheduledSurgery(Surgery* surgery);
    void removeScheduledSurgery(const std::string& surgeryId);
    std::vector<Surgery*> getScheduledSurgeries() const;
    
    void addSurgicalEquipment(MedicalEquipment* equipment);
    void removeSurgicalEquipment(const std::string& equipmentId);
    std::vector<MedicalEquipment*> getSurgicalEquipment() const;
    
    void addAuthorizedSurgeon(Doctor* surgeon);
    void removeAuthorizedSurgeon(const std::string& surgeonId);
    std::vector<Doctor*> getAuthorizedSurgeons() const;
    
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    bool isAvailable() const { return availabilityStatus; }
    void setSterilizationLevel(double level) { sterilizationLevel = level; }
    void setSizeSqm(int size) { sizeSqm = size; }
    double getSterilizationLevel() const { return sterilizationLevel; }
    int getSizeSqm() const { return sizeSqm; }
    bool isFullyEquipped() const { return !surgicalEquipment.empty(); }
};

#endif
