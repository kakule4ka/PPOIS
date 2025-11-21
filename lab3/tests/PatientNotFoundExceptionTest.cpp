#include <gtest/gtest.h>
#include "PatientNotFoundException.h"

TEST(PatientNotFoundExceptionTest, ConstructorAndGetters) {
    std::string patientId = "P999";
    PatientNotFoundException exception(patientId);
    
    EXPECT_EQ(exception.getPatientId(), patientId);
    EXPECT_NE(std::string(exception.what()).find(patientId), std::string::npos);
}

TEST(PatientNotFoundExceptionTest, ExceptionInheritance) {
    PatientNotFoundException exception("P001");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, PatientNotFoundException);
}
