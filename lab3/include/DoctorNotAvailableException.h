#ifndef DOCTORNOTAVAILABLEEXCEPTION_H
#define DOCTORNOTAVAILABLEEXCEPTION_H

#include <stdexcept>
#include <string>

class DoctorNotAvailableException : public std::runtime_error {
private:
    std::string doctorId;
    std::string reason;
    
public:
    DoctorNotAvailableException(const std::string& doctorId, const std::string& reason);
    std::string getDoctorId() const;
    std::string getReason() const;
};

#endif
