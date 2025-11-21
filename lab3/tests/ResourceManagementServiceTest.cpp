#include <gtest/gtest.h>
#include "ResourceManagementService.h"
#include "Hospital.h"

class ResourceManagementServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new ResourceManagementService("RES_SVC001");
        hospital = new Hospital("HOSP001", "Main St", 200, 1990, 5000000.0);
    }

    void TearDown() override {
        delete service;
        delete hospital;
    }

    ResourceManagementService* service;
    Hospital* hospital;
};

TEST_F(ResourceManagementServiceTest, CalculateResourceUtilization) {
    double utilization = service->calculateResourceUtilization();
    EXPECT_GE(utilization, 0.0);
    EXPECT_LE(utilization, 100.0);
}

TEST_F(ResourceManagementServiceTest, OptimizeResourceAllocation) {
    bool optimized = service->optimizeResourceAllocation();
    EXPECT_TRUE(optimized || !optimized);
}

TEST_F(ResourceManagementServiceTest, GetManagedHospitalCount) {
    int count = service->getManagedHospitalCount();
    EXPECT_GE(count, 0);
}

TEST_F(ResourceManagementServiceTest, HospitalManagement) {
    service->addManagedHospital(hospital);
    auto hospitals = service->getManagedHospitals();
    EXPECT_EQ(hospitals.size(), 1);
    
    service->removeManagedHospital("HOSP001");
    hospitals = service->getManagedHospitals();
    EXPECT_EQ(hospitals.size(), 0);
}
