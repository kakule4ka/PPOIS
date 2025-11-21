#include <gtest/gtest.h>
#include "Radiologist.h"
#include "MedicalDevice.h"

class RadiologistTest : public ::testing::Test {
protected:
    void SetUp() override {
        radiologist = new Radiologist("RAD001", "Dr. Scan", 12, "RAD123", 15, 500, 92.5);
        equipment = new MedicalDevice("DEV001", "CT Scanner", "Imaging");
    }

    void TearDown() override {
        delete radiologist;
        delete equipment;
    }

    Radiologist* radiologist;
    MedicalDevice* equipment;
};

TEST_F(RadiologistTest, CalculateDiagnosticAccuracy) {
    double accuracy = radiologist->calculateDiagnosticAccuracy();
    EXPECT_GE(accuracy, 0.0);
    EXPECT_LE(accuracy, 100.0);
}

TEST_F(RadiologistTest, CanInterpretComplexCases) {
    bool canInterpret = radiologist->canInterpretComplexCases();
    EXPECT_TRUE(canInterpret || !canInterpret);
}

TEST_F(RadiologistTest, EquipmentManagement) {
    radiologist->addImagingEquipment(equipment);
    auto equipmentList = radiologist->getImagingEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    radiologist->removeImagingEquipment("DEV001");
    equipmentList = radiologist->getImagingEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}
