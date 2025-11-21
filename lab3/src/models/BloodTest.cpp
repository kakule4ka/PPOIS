#include "BloodTest.h"
#include "Patient.h"
#include "Doctor.h"
#include <algorithm>
#include <cmath>

BloodTest::BloodTest(const std::string& id, const std::string& name, const std::string& bloodType)
    : LaboratoryTest(id, name, "Blood"), bloodType(bloodType), hemoglobinLevel(14.0), 
      cholesterolLevel(180.0), whiteBloodCellCount(7000) {}

double BloodTest::calculateAnemiaRisk() const {
    double baseRisk = 10.0;
    
    double hemoglobinRisk = 0.0;
    if (hemoglobinLevel < 12.0) hemoglobinRisk = 30.0;
    else if (hemoglobinLevel < 13.5) hemoglobinRisk = 15.0;
    
    double bloodTypeRisk = 0.0;
    if (bloodType == "O") bloodTypeRisk = 5.0;
    else if (bloodType == "A") bloodTypeRisk = 3.0;
    
    double donorRisk = bloodDonors.size() * 0.5;
    
    double physicianExperienceRisk = 0.0;
    for (const auto& physician : requestingPhysicians) {
        physicianExperienceRisk -= physician->getExperienceYears() * 0.2;
    }
    
    double totalRisk = baseRisk + hemoglobinRisk + bloodTypeRisk + donorRisk + physicianExperienceRisk;
    return std::max(0.0, std::min(totalRisk, 100.0));
}

bool BloodTest::indicatesInfection() const {
    bool highWhiteBloodCells = whiteBloodCellCount > 11000;
    bool lowHemoglobin = hemoglobinLevel < 11.0;
    bool abnormalCholesterol = cholesterolLevel > 240 || cholesterolLevel < 160;
    
    bool multipleDonors = bloodDonors.size() >= 5;
    bool specialistRequest = false;
    
    for (const auto& physician : requestingPhysicians) {
        if (physician->getSpecialization() == "Infectious Disease" || 
            physician->getSpecialization() == "Hematology") {
            specialistRequest = true;
            break;
        }
    }
    
    return highWhiteBloodCells || (lowHemoglobin && abnormalCholesterol) || 
           (multipleDonors && specialistRequest);
}

double BloodTest::calculateCardiovascularRisk() const {
    double baseRisk = 20.0;
    
    double cholesterolRisk = 0.0;
    if (cholesterolLevel > 240) cholesterolRisk = 35.0;
    else if (cholesterolLevel > 200) cholesterolRisk = 20.0;
    else if (cholesterolLevel < 160) cholesterolRisk = 10.0;
    
    double hemoglobinRisk = hemoglobinLevel > 16.0 ? 15.0 : 0.0;
    
    double bloodTypeRisk = 0.0;
    if (bloodType == "AB") bloodTypeRisk = 8.0;
    else if (bloodType == "B") bloodTypeRisk = 5.0;
    
    double donorHealthRisk = 0.0;
    for (const auto& donor : bloodDonors) {
        donorHealthRisk += donor->calculateHealthRiskScore() * 0.1;
    }
    
    double physicianRiskAssessment = 0.0;
    for (const auto& physician : requestingPhysicians) {
        if (physician->getSpecialization() == "Cardiology") {
            physicianRiskAssessment -= 10.0;
        }
    }
    
    double totalRisk = baseRisk + cholesterolRisk + hemoglobinRisk + bloodTypeRisk + 
                      donorHealthRisk + physicianRiskAssessment;
    return std::max(0.0, std::min(totalRisk, 100.0));
}

void BloodTest::addBloodDonor(Patient* donor) {
    if (donor) {
        bloodDonors.push_back(donor);
    }
}

void BloodTest::removeBloodDonor(const std::string& donorId) {
    bloodDonors.erase(
        std::remove_if(bloodDonors.begin(), bloodDonors.end(),
            [&donorId](Patient* donor) {
                return donor->getId() == donorId;
            }),
        bloodDonors.end()
    );
}

std::vector<Patient*> BloodTest::getBloodDonors() const {
    return bloodDonors;
}

void BloodTest::addRequestingPhysician(Doctor* physician) {
    if (physician) {
        requestingPhysicians.push_back(physician);
    }
}

void BloodTest::removeRequestingPhysician(const std::string& physicianId) {
    requestingPhysicians.erase(
        std::remove_if(requestingPhysicians.begin(), requestingPhysicians.end(),
            [&physicianId](Doctor* physician) {
                return physician->getId() == physicianId;
            }),
        requestingPhysicians.end()
    );
}

std::vector<Doctor*> BloodTest::getRequestingPhysicians() const {
    return requestingPhysicians;
}
