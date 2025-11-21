#include <gtest/gtest.h>
#include "MedicalRecordAccessException.h"

TEST(MedicalRecordAccessExceptionTest, ConstructorAndGetters) {
    std::string recordId = "MR001";
    std::string accessReason = "Unauthorized access";
    std::string userId = "USER123";
    MedicalRecordAccessException exception(recordId, accessReason, userId);
    
    EXPECT_EQ(exception.getRecordId(), recordId);
    EXPECT_EQ(exception.getAccessReason(), accessReason);
    EXPECT_EQ(exception.getUserId(), userId);
    EXPECT_NE(std::string(exception.what()).find(recordId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(accessReason), std::string::npos);
}

TEST(MedicalRecordAccessExceptionTest, ExceptionInheritance) {
    MedicalRecordAccessException exception("MR002", "Patient consent required", "DOCTOR001");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, MedicalRecordAccessException);
}
