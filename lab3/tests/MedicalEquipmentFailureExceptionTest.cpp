#include <gtest/gtest.h>
#include "MedicalEquipmentFailureException.h"

TEST(MedicalEquipmentFailureExceptionTest, ConstructorAndGetters) {
    std::string equipmentId = "EQ001";
    std::string failureType = "Power Supply";
    MedicalEquipmentFailureException exception(equipmentId, failureType);
    
    EXPECT_EQ(exception.getEquipmentId(), equipmentId);
    EXPECT_EQ(exception.getFailureType(), failureType);
    EXPECT_NE(std::string(exception.what()).find(equipmentId), std::string::npos);
    EXPECT_NE(std::string(exception.what()).find(failureType), std::string::npos);
}

TEST(MedicalEquipmentFailureExceptionTest, ExceptionInheritance) {
    MedicalEquipmentFailureException exception("MRI001", "Cooling System");
    
    EXPECT_THROW(throw exception, std::runtime_error);
    EXPECT_THROW(throw exception, MedicalEquipmentFailureException);
}
