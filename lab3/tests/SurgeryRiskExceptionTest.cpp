#include <gtest/gtest.h>
#include "SurgeryRiskException.h"

TEST(SurgeryRiskExceptionTest, ConstructorAndGetters) {
    std::string surgeryId = "SUR001";
    std::string patientId = "PAT001";
    double riskPercentage = 85.5;
    std::string riskFactors = "Age, comorbidities, anesthesia risk";
    SurgeryRiskException exception(surgeryId, patientId, riskPercentage, riskFactors);
    
    EXPECT_EQ(exception.getSurgeryId(), surgeryId);
    EXPECT_EQ(exception.getPatientId(), patientId);
    EXPECT_DOUBLE_EQ(exception.getRiskPercentage(), riskPercentage);
    EXPECT_EQ(exception.getRiskFactors(), riskFactors);
    EXPECT_NE(std::string(exception.what()).find(surgeryId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(patientId), std::string::npos);
}

TEST(SurgeryRiskExceptionTest, ExceptionInheritance) {
    SurgeryRiskException exception("SUR002", "PAT002", 92.0, "Cardiac condition, low platelet count");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, SurgeryRiskException);
}
