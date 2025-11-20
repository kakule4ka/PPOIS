#include <gtest/gtest.h>
#include "BudgetExceededException.h"
#include "ScheduleConflictException.h"
#include "SafetyViolationException.h"
#include "MaterialShortageException.h"
#include "PermitNotGrantedException.h"
#include "QualityStandardNotMetException.h"
#include "InvalidBlueprintException.h"
#include "EquipmentFailureException.h"
#include "WorkerNotQualifiedException.h"
#include "ClientPaymentDelayedException.h"
#include "WeatherConditionsException.h"
#include "ResourceAllocationException.h"

TEST(ExceptionsTest, BudgetExceededException) {
    BudgetExceededException exception(50000.0);
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getExceededAmount(), 50000.0);
}

TEST(ExceptionsTest, ScheduleConflictException) {
    ScheduleConflictException exception("Critical Path Task");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getConflictingTask(), "Critical Path Task");
}

TEST(ExceptionsTest, SafetyViolationException) {
    SafetyViolationException exception("Fall Protection");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getViolationType(), "Fall Protection");
}

TEST(ExceptionsTest, MaterialShortageException) {
    MaterialShortageException exception("Concrete", 50.5);
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getMaterialName(), "Concrete");
    EXPECT_EQ(exception.getShortageAmount(), 50.5);
}

TEST(ExceptionsTest, PermitNotGrantedException) {
    PermitNotGrantedException exception("Building Permit");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getPermitType(), "Building Permit");
}

TEST(ExceptionsTest, QualityStandardNotMetException) {
    QualityStandardNotMetException exception("Concrete Strength", 25.3);
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getStandardName(), "Concrete Strength");
    EXPECT_EQ(exception.getActualValue(), 25.3);
}

TEST(ExceptionsTest, InvalidBlueprintException) {
    InvalidBlueprintException exception("BP-2024-001");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getBlueprintId(), "BP-2024-001");
}

TEST(ExceptionsTest, EquipmentFailureException) {
    EquipmentFailureException exception("EXC-001");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getEquipmentId(), "EXC-001");
}

TEST(ExceptionsTest, WorkerNotQualifiedException) {
    WorkerNotQualifiedException exception("W-123", "Electrical Work");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getWorkerId(), "W-123");
    EXPECT_EQ(exception.getRequiredSkill(), "Electrical Work");
}

TEST(ExceptionsTest, ClientPaymentDelayedException) {
    ClientPaymentDelayedException exception("CLIENT-001", 15);
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getClientId(), "CLIENT-001");
    EXPECT_EQ(exception.getDelayDays(), 15);
}

TEST(ExceptionsTest, WeatherConditionsException) {
    WeatherConditionsException exception("Heavy Rain");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getWeatherCondition(), "Heavy Rain");
}

TEST(ExceptionsTest, ResourceAllocationException) {
    ResourceAllocationException exception("Crane Operators");
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_EQ(exception.getResourceType(), "Crane Operators");
}
