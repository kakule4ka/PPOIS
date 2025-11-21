#ifndef MEDICALEQUIPMENTFAILUREEXCEPTION_H
#define MEDICALEQUIPMENTFAILUREEXCEPTION_H

#include <stdexcept>
#include <string>

class MedicalEquipmentFailureException : public std::runtime_error {
private:
    std::string equipmentId;
    std::string failureType;
    
public:
    MedicalEquipmentFailureException(const std::string& equipmentId, const std::string& failureType);
    std::string getEquipmentId() const;
    std::string getFailureType() const;
};

#endif
