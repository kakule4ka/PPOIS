#ifndef PRESCRIPTIONINVALIDEXCEPTION_H
#define PRESCRIPTIONINVALIDEXCEPTION_H

#include <stdexcept>
#include <string>

class PrescriptionInvalidException : public std::runtime_error {
private:
    std::string prescriptionId;
    std::string medicationName;
    std::string validationError;
    
public:
    PrescriptionInvalidException(const std::string& prescriptionId, const std::string& medicationName, const std::string& validationError);
    std::string getPrescriptionId() const;
    std::string getMedicationName() const;
    std::string getValidationError() const;
};

#endif
