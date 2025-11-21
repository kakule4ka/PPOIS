#include <gtest/gtest.h>
#include "MedicationNotAvailableException.h"

TEST(MedicationNotAvailableExceptionTest, ConstructorAndGetters) {
    std::string medicationName = "Aspirin";
    double required = 100.0;
    double available = 50.0;
    MedicationNotAvailableException exception(medicationName, required, available);
    
    EXPECT_EQ(exception.getMedicationName(), medicationName);
    EXPECT_DOUBLE_EQ(exception.getRequiredQuantity(), required);
    EXPECT_DOUBLE_EQ(exception.getAvailableQuantity(), available);
    EXPECT_NE(std::string(exception.what()).find(medicationName), std::string::npos);
}

TEST(MedicationNotAvailableExceptionTest, ExceptionInheritance) {
    MedicationNotAvailableException exception("Insulin", 10.0, 5.0);
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, MedicationNotAvailableException);
}
