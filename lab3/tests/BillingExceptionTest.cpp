#include <gtest/gtest.h>
#include "BillingException.h"

TEST(BillingExceptionTest, ConstructorAndGetters) {
    std::string billingId = "BIL001";
    std::string patientId = "PAT001";
    double amountInDispute = 2500.75;
    std::string disputeReason = "Insurance claim rejected";
    BillingException exception(billingId, patientId, amountInDispute, disputeReason);
    
    EXPECT_EQ(exception.getBillingId(), billingId);
    EXPECT_EQ(exception.getPatientId(), patientId);
    EXPECT_DOUBLE_EQ(exception.getAmountInDispute(), amountInDispute);
    EXPECT_EQ(exception.getDisputeReason(), disputeReason);
    EXPECT_NE(std::string(exception.what()).find(billingId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(patientId), std::string::npos);
}

TEST(BillingExceptionTest, ExceptionInheritance) {
    BillingException exception("BIL002", "PAT002", 1800.50, "Procedure not covered by insurance");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, BillingException);
}
