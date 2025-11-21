#include <gtest/gtest.h>
#include "LaboratoryTestFailedException.h"

TEST(LaboratoryTestFailedExceptionTest, ConstructorAndGetters) {
    std::string testId = "LAB001";
    std::string testType = "Blood Analysis";
    std::string failureReason = "Sample contamination";
    LaboratoryTestFailedException exception(testId, testType, failureReason);
    
    EXPECT_EQ(exception.getTestId(), testId);
    EXPECT_EQ(exception.getTestType(), testType);
    EXPECT_EQ(exception.getFailureReason(), failureReason);
    EXPECT_NE(std::string(exception.what()).find(testId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(testType), std::string::npos);
}

TEST(LaboratoryTestFailedExceptionTest, ExceptionInheritance) {
    LaboratoryTestFailedException exception("LAB002", "Urine Test", "Equipment malfunction");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, LaboratoryTestFailedException);
}
