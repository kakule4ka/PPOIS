#ifndef EQUIPMENTFAILUREEXCEPTION_H
#define EQUIPMENTFAILUREEXCEPTION_H

#include <stdexcept>
#include <string>

class EquipmentFailureException : public std::runtime_error {
private:
    std::string equipmentId;
    
public:
    EquipmentFailureException(const std::string& equipment);
    std::string getEquipmentId() const;
};

#endif
