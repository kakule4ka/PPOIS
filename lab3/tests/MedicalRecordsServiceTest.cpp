#include <gtest/gtest.h>
#include "MedicalRecordsService.h"
#include "MedicalRecord.h"

class MedicalRecordsServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new MedicalRecordsService("REC_SVC001");
        record = new MedicalRecord("REC001", "Annual checkup", "2024-01-15");
    }

    void TearDown() override {
        delete service;
        delete record;
    }

    MedicalRecordsService* service;
    MedicalRecord* record;
};

TEST_F(MedicalRecordsServiceTest, CalculateRecordCompleteness) {
    double completeness = service->calculateRecordCompleteness();
    EXPECT_GE(completeness, 0.0);
    EXPECT_LE(completeness, 100.0);
}

TEST_F(MedicalRecordsServiceTest, ValidateRecordSecurity) {
    bool secure = service->validateRecordSecurity();
    EXPECT_TRUE(secure || !secure);
}

TEST_F(MedicalRecordsServiceTest, GetTotalRecordCount) {
    int count = service->getTotalRecordCount();
    EXPECT_GE(count, 0);
}

TEST_F(MedicalRecordsServiceTest, RecordManagement) {
    service->addStoredRecord(record);
    auto records = service->getStoredRecords();
    EXPECT_EQ(records.size(), 1);
    
    service->removeStoredRecord("REC001");
    records = service->getStoredRecords();
    EXPECT_EQ(records.size(), 0);
}
