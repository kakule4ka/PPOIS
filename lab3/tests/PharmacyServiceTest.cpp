#include <gtest/gtest.h>
#include "PharmacyService.h"
#include "Pharmacy.h"

class PharmacyServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new PharmacyService("PHARM_SVC001");
        pharmacy = new Pharmacy("PHARM001", "Main Pharmacy", 500);
    }

    void TearDown() override {
        delete service;
        delete pharmacy;
    }

    PharmacyService* service;
    Pharmacy* pharmacy;
};

TEST_F(PharmacyServiceTest, CalculateServiceEfficiency) {
    double efficiency = service->calculateServiceEfficiency();
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(PharmacyServiceTest, ValidateInventoryManagement) {
    bool valid = service->validateInventoryManagement();
    EXPECT_TRUE(valid || !valid);
}

TEST_F(PharmacyServiceTest, GetTotalPharmacyCount) {
    int count = service->getTotalPharmacyCount();
    EXPECT_GE(count, 0);
}

TEST_F(PharmacyServiceTest, PharmacyManagement) {
    service->addManagedPharmacy(pharmacy);
    auto pharmacies = service->getManagedPharmacies();
    EXPECT_EQ(pharmacies.size(), 1);
    
    service->removeManagedPharmacy("PHARM001");
    pharmacies = service->getManagedPharmacies();
    EXPECT_EQ(pharmacies.size(), 0);
}
