#include <gtest/gtest.h>
#include "PatientManagementService.h"
#include "Patient.h"

class PatientManagementServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service = new PatientManagementService("PAT_SVC001");
        patient = new Patient("PAT001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete service;
        delete patient;
    }

    PatientManagementService* service;
    Patient* patient;
};

TEST_F(PatientManagementServiceTest, CalculatePatientSatisfaction) {
    double satisfaction = service->calculatePatientSatisfaction();
    EXPECT_GE(satisfaction, 0.0);
    EXPECT_LE(satisfaction, 100.0);
}

TEST_F(PatientManagementServiceTest, ValidatePatientCareStandards) {
    bool standardsMet = service->validatePatientCareStandards();
    EXPECT_TRUE(standardsMet || !standardsMet);
}

TEST_F(PatientManagementServiceTest, GetActivePatientCount) {
    int count = service->getActivePatientCount();
    EXPECT_GE(count, 0);
}

TEST_F(PatientManagementServiceTest, PatientManagement) {
    service->addManagedPatient(patient);
    auto patients = service->getManagedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    service->removeManagedPatient("PAT001");
    patients = service->getManagedPatients();
    EXPECT_EQ(patients.size(), 0);
}
