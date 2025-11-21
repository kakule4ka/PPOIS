#ifndef BLOODTEST_H
#define BLOODTEST_H

#include "LaboratoryTest.h"
#include <string>
#include <vector>

class Patient;
class Doctor;

class BloodTest : public LaboratoryTest {
private:
    std::string bloodType;
    double hemoglobinLevel;
    double cholesterolLevel;
    int whiteBloodCellCount;
    std::vector<Patient*> bloodDonors;
    std::vector<Doctor*> requestingPhysicians;

public:
    BloodTest(const std::string& id, const std::string& name, const std::string& bloodType);
    
    double calculateAnemiaRisk() const;
    bool indicatesInfection() const;
    double calculateCardiovascularRisk() const;
    
    void addBloodDonor(Patient* donor);
    void removeBloodDonor(const std::string& donorId);
    std::vector<Patient*> getBloodDonors() const;
    
    void addRequestingPhysician(Doctor* physician);
    void removeRequestingPhysician(const std::string& physicianId);
    std::vector<Doctor*> getRequestingPhysicians() const;
    
    std::string getBloodType() const { return bloodType; }
    void setHemoglobinLevel(double level) { hemoglobinLevel = level; }
    void setCholesterolLevel(double level) { cholesterolLevel = level; }
    void setWhiteBloodCellCount(int count) { whiteBloodCellCount = count; }
    double getHemoglobinLevel() const { return hemoglobinLevel; }
    double getCholesterolLevel() const { return cholesterolLevel; }
    int getWhiteBloodCellCount() const { return whiteBloodCellCount; }
};

#endif
