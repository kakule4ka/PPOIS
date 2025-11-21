#ifndef MEDICALRECORDACCESSEXCEPTION_H
#define MEDICALRECORDACCESSEXCEPTION_H

#include <stdexcept>
#include <string>

class MedicalRecordAccessException : public std::runtime_error {
private:
    std::string recordId;
    std::string accessReason;
    std::string userId;
    
public:
    MedicalRecordAccessException(const std::string& recordId, const std::string& accessReason, const std::string& userId);
    std::string getRecordId() const;
    std::string getAccessReason() const;
    std::string getUserId() const;
};

#endif
