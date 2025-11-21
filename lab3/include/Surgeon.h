#ifndef SURGEON_H
#define SURGEON_H

#include "Doctor.h"
#include <string>
#include <vector>

class Surgery;
class OperatingRoom;

class Surgeon : public Doctor {
private:
    int surgeriesPerformed;
    double complicationRate;
    std::string surgicalSpecialty;
    std::vector<Surgery*> performedSurgeries;
    std::vector<OperatingRoom*> assignedOperatingRooms;

public:
    Surgeon(const std::string& id, const std::string& name, int experience, 
           const std::string& license, int maxPatients, int surgeries, double complicationRate);
    
    double calculateSurgicalRisk(const Surgery* surgery) const;
    bool canHandleComplexSurgery() const;
    double calculateSurgicalOutcomeScore() const;
    
    void addPerformedSurgery(Surgery* surgery);
    void removePerformedSurgery(const std::string& surgeryId);
    std::vector<Surgery*> getPerformedSurgeries() const;
    
    void addAssignedOperatingRoom(OperatingRoom* room);
    void removeAssignedOperatingRoom(const std::string& roomId);
    std::vector<OperatingRoom*> getAssignedOperatingRooms() const;
    
    int getSurgeriesPerformed() const { return surgeriesPerformed; }
    double getComplicationRate() const { return complicationRate; }
    std::string getSurgicalSpecialty() const { return surgicalSpecialty; }
};

#endif
