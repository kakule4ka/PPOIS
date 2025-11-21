#ifndef MEDICATIONNOTAVAILABLEEXCEPTION_H
#define MEDICATIONNOTAVAILABLEEXCEPTION_H

#include <stdexcept>
#include <string>

class MedicationNotAvailableException : public std::runtime_error {
private:
    std::string medicationName;
    double requiredQuantity;
    double availableQuantity;
    
public:
    MedicationNotAvailableException(const std::string& medicationName, double required, double available);
    std::string getMedicationName() const;
    double getRequiredQuantity() const;
    double getAvailableQuantity() const;
};

#endif
