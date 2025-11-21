#include <gtest/gtest.h>
#include "BedNotAvailableException.h"

TEST(BedNotAvailableExceptionTest, ConstructorAndGetters) {
    std::string wardId = "WARD001";
    std::string bedType = "ICU";
    int required = 2;
    BedNotAvailableException exception(wardId, bedType, required);
    
    EXPECT_EQ(exception.getWardId(), wardId);
    EXPECT_EQ(exception.getBedType(), bedType);
    EXPECT_EQ(exception.getRequiredBeds(), required);
    EXPECT_NE(std::string(exception.what()).find(wardId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(bedType), std::string::npos);
}

TEST(BedNotAvailableExceptionTest, ExceptionInheritance) {
    BedNotAvailableException exception("WARD002", "Private", 1);
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, BedNotAvailableException);
}
