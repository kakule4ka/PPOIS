#include "MedicalRecordAccessException.h"

MedicalRecordAccessException::MedicalRecordAccessException(const std::string& recordId, 
                                                         const std::string& accessReason, 
                                                         const std::string& userId)
    : std::runtime_error("Medical record access denied: Record " + recordId + 
                        " - Reason: " + accessReason + 
                        " - User: " + userId), 
      recordId(recordId), accessReason(accessReason), userId(userId) {}

std::string MedicalRecordAccessException::getRecordId() const {
    return recordId;
}

std::string MedicalRecordAccessException::getAccessReason() const {
    return accessReason;
}

std::string MedicalRecordAccessException::getUserId() const {
    return userId;
}
