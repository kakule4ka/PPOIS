#include <gtest/gtest.h>
#include "Window.h"

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

TEST(WindowTest, CalculateHeatLossTripleGlazed) {
    Window window("WIN003", "TripleGlazed", 1.5, 2.0);
    double heatLoss = window.calculateHeatLoss();
    EXPECT_GT(heatLoss, 0);
}

TEST(WindowTest, MeetsVentilationRequirementsOperable) {
    Window window("WIN004", "DoubleGlazed", 1.0, 1.8);
    bool meets = window.meetsVentilationRequirements();
    EXPECT_TRUE(meets);
}

TEST(WindowTest, MeetsVentilationRequirementsFixed) {
    Window window("WIN005", "Fixed", 1.5, 2.0);
    bool meets = window.meetsVentilationRequirements();
    EXPECT_FALSE(meets);
}

TEST(WindowTest, GetWindowId) {
    Window window("WIN006", "LowE", 1.1, 1.4);
    EXPECT_EQ(window.getId(), "WIN006");
}
