#include <gtest/gtest.h>
#include "ConstructionSite.h"
#include "ConstructionProject.h"
#include "SafetyProtocol.h"

TEST(ConstructionSiteTest, ValidateWorkerCapacityOptimal) {
    ConstructionSite site("S001", "Downtown", 5000, 50);
    bool valid = site.validateWorkerCapacity(40);
    EXPECT_TRUE(valid);
}

TEST(ConstructionSiteTest, ExceedWorkerCapacity) {
    ConstructionSite site("S003", "Industrial Zone", 10000, 100);
    bool valid = site.validateWorkerCapacity(120);
    EXPECT_FALSE(valid);
}

TEST(ConstructionSiteTest, CalculatePreparationTimeSmall) {
    ConstructionSite site("S004", "Residential Area", 2000, 20);
    double time = site.calculatePreparationTime();
    EXPECT_NEAR(time, 150.0, 0.01);
}

TEST(ConstructionSiteTest, CalculateSiteSafetyScore) {
    ConstructionSite site("S005", "Commercial District", 15000, 100);
    double score = site.calculateSiteSafetyScore();
    EXPECT_GT(score, 0.0);
}

TEST(ConstructionSiteTest, IsSiteReady) {
    ConstructionSite site("S006", "Waterfront", 8000, 80);
    bool ready = site.isSiteReady();
    EXPECT_FALSE(ready);
}

TEST(ConstructionSiteTest, SetAndGetProject) {
    ConstructionSite site("S007", "Test Location", 5000, 50);
    ConstructionProject project("P1", "Test Project", 1000000, 12);
    
    site.setProject(&project);
    EXPECT_EQ(site.getProject()->getId(), "P1");
}

TEST(ConstructionSiteTest, AddAndGetSafetyProtocols) {
    ConstructionSite site("S008", "Safe Location", 6000, 60);
    SafetyProtocol protocol1("SP1", "Fall Protection", 40, true);
    SafetyProtocol protocol2("SP2", "Fire Safety", 20, true);
    
    site.addSafetyProtocol(&protocol1);
    site.addSafetyProtocol(&protocol2);
    
    auto protocols = site.getActiveSafetyProtocols();
    EXPECT_EQ(protocols.size(), 2);
}
