#include <gtest/gtest.h>
#include "EmergencyPriorityException.h"

TEST(EmergencyPriorityExceptionTest, ConstructorAndGetters) {
    std::string emergencyId = "EMG001";
    std::string priorityLevel = "CRITICAL";
    std::string conflictReason = "Resource allocation conflict";
    EmergencyPriorityException exception(emergencyId, priorityLevel, conflictReason);
    
    EXPECT_EQ(exception.getEmergencyId(), emergencyId);
    EXPECT_EQ(exception.getPriorityLevel(), priorityLevel);
    EXPECT_EQ(exception.getConflictReason(), conflictReason);
    EXPECT_NE(std::string(exception.what()).find(emergencyId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(priorityLevel), std::string::npos);
}

TEST(EmergencyPriorityExceptionTest, ExceptionInheritance) {
    EmergencyPriorityException exception("EMG002", "HIGH", "Staff availability issue");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, EmergencyPriorityException);
}
