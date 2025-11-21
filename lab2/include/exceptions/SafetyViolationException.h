#ifndef SAFETYVIOLATIONEXCEPTION_H
#define SAFETYVIOLATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class SafetyViolationException : public std::runtime_error {
private:
    std::string violationType;
    
public:
    SafetyViolationException(const std::string& violation);
    std::string getViolationType() const;
};

#endif
