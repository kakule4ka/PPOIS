#ifndef PATIENTNOTFOUNDEXCEPTION_H
#define PATIENTNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

class PatientNotFoundException : public std::runtime_error {
private:
    std::string patientId;
    
public:
    PatientNotFoundException(const std::string& patientId);
    std::string getPatientId() const;
};

#endif
