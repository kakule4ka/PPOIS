#include <gtest/gtest.h>
#include "models/Window.h"
#include "models/Building.h"
#include "core/QualityStandard.h"

TEST(WindowTest, CalculateHeatLossDoubleGlazed) {
    Window window("WIN001", "DoubleGlazed", 1.2, 1.5);
    double heatLoss = window.calculateHeatLoss();
    EXPECT_GT(heatLoss, 0);
}

TEST(WindowTest, CalculateHeatLossSingleGlazed) {
    Window window("WIN002", "SingleGlazed", 0.9, 1.2);
    double heatLoss = window.calculateHeatLoss();
    EXPECT_GT(heatLoss, 0);
}

TEST(WindowTest, MeetsVentilationRequirementsOperable) {
    Window window("WIN004", "DoubleGlazed", 1.0, 1.8);
    bool meets = window.meetsVentilationRequirements();
    EXPECT_TRUE(meets);
}

TEST(WindowTest, CalculateWindowEfficiency) {
    Window window("WIN005", "TripleGlazed", 1.5, 2.0);
    double efficiency = window.calculateWindowEfficiency();
    EXPECT_GT(efficiency, 0.0);
}

TEST(WindowTest, IsEnergyEfficient) {
    Window window("WIN006", "DoubleGlazed", 1.2, 1.5);
    bool efficient = window.isEnergyEfficient();
    EXPECT_FALSE(efficient);
}

TEST(WindowTest, SetAndGetBuilding) {
    Window window("WIN007", "LowE", 1.1, 1.4);
    Building building("B1", "Test Building", 5, 2000);
    
    window.setBuilding(&building);
    EXPECT_EQ(window.getBuilding()->getId(), "B1");
}

TEST(WindowTest, AddAndGetEnergyStandards) {
    Window window("WIN008", "DoubleGlazed", 1.3, 1.6);
    QualityStandard standard1("QS1", "U-Value", "Energy", 2.0);
    QualityStandard standard2("QS2", "Solar Heat Gain", "Energy", 0.5);
    
    window.addEnergyStandard(&standard1);
    window.addEnergyStandard(&standard2);
    
    auto standards = window.getEnergyStandards();
    EXPECT_EQ(standards.size(), 2);
}
