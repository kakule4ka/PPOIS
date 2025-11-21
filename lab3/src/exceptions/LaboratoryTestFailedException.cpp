#include "LaboratoryTestFailedException.h"

LaboratoryTestFailedException::LaboratoryTestFailedException(const std::string& testId, 
                                                            const std::string& testType, 
                                                            const std::string& failureReason)
    : std::runtime_error("Laboratory test failed: Test " + testId + 
                        " - Type: " + testType + 
                        " - Reason: " + failureReason), 
      testId(testId), testType(testType), failureReason(failureReason) {}

std::string LaboratoryTestFailedException::getTestId() const {
    return testId;
}

std::string LaboratoryTestFailedException::getTestType() const {
    return testType;
}

std::string LaboratoryTestFailedException::getFailureReason() const {
    return failureReason;
}
