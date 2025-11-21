#include <gtest/gtest.h>
#include "InsuranceNotCoveredException.h"

TEST(InsuranceNotCoveredExceptionTest, ConstructorAndGetters) {
    std::string provider = "HealthPlus";
    std::string treatment = "MRI Scan";
    double cost = 1500.0;
    InsuranceNotCoveredException exception(provider, treatment, cost);
    
    EXPECT_EQ(exception.getInsuranceProvider(), provider);
    EXPECT_EQ(exception.getTreatmentType(), treatment);
    EXPECT_DOUBLE_EQ(exception.getCost(), cost);
    EXPECT_NE(std::string(exception.what()).find(provider), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(treatment), std::string::npos);
}

TEST(InsuranceNotCoveredExceptionTest, ExceptionInheritance) {
    InsuranceNotCoveredException exception("MediCare", "Surgery", 5000.0);
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, InsuranceNotCoveredException);
}
