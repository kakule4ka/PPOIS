#ifndef LABORATORYTESTFAILEDEXCEPTION_H
#define LABORATORYTESTFAILEDEXCEPTION_H

#include <stdexcept>
#include <string>

class LaboratoryTestFailedException : public std::runtime_error {
private:
    std::string testId;
    std::string testType;
    std::string failureReason;
    
public:
    LaboratoryTestFailedException(const std::string& testId, const std::string& testType, const std::string& failureReason);
    std::string getTestId() const;
    std::string getTestType() const;
    std::string getFailureReason() const;
};

#endif
