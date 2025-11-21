#include <gtest/gtest.h>
#include "PrescriptionInvalidException.h"

TEST(PrescriptionInvalidExceptionTest, ConstructorAndGetters) {
    std::string prescriptionId = "RX001";
    std::string medicationName = "Morphine";
    std::string validationError = "Dosage exceeds maximum limit";
    PrescriptionInvalidException exception(prescriptionId, medicationName, validationError);
    
    EXPECT_EQ(exception.getPrescriptionId(), prescriptionId);
    EXPECT_EQ(exception.getMedicationName(), medicationName);
    EXPECT_EQ(exception.getValidationError(), validationError);
    EXPECT_NE(std::string(exception.what()).find(prescriptionId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(medicationName), std::string::npos);
}

TEST(PrescriptionInvalidExceptionTest, ExceptionInheritance) {
    PrescriptionInvalidException exception("RX002", "Antibiotic", "Drug interaction detected");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, PrescriptionInvalidException);
}
