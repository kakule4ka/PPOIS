#include <gtest/gtest.h>
#include "DoctorNotAvailableException.h"

TEST(DoctorNotAvailableExceptionTest, ConstructorAndGetters) {
    std::string doctorId = "D999";
    std::string reason = "On vacation";
    DoctorNotAvailableException exception(doctorId, reason);
    
    EXPECT_EQ(exception.getDoctorId(), doctorId);
    EXPECT_EQ(exception.getReason(), reason);
    EXPECT_NE(std::string(exception.what()).find(doctorId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(reason), std::string::npos);
}

TEST(DoctorNotAvailableExceptionTest, ExceptionInheritance) {
    DoctorNotAvailableException exception("D001", "Emergency");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, DoctorNotAvailableException);
}
