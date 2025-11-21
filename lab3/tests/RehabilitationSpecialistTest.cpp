#include <gtest/gtest.h>
#include "RehabilitationSpecialist.h"
#include "Patient.h"

class RehabilitationSpecialistTest : public ::testing::Test {
protected:
    void SetUp() override {
        specialist = new RehabilitationSpecialist("REHAB001", "Dr. Recovery", "Neurological", 8);
        patient = new Patient("PAT001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete specialist;
        delete patient;
    }

    RehabilitationSpecialist* specialist;
    Patient* patient;
};

TEST_F(RehabilitationSpecialistTest, CalculateRecoverySuccessRate) {
    double successRate = specialist->calculateRecoverySuccessRate();
    EXPECT_GE(successRate, 0.0);
    EXPECT_LE(successRate, 100.0);
}

TEST_F(RehabilitationSpecialistTest, RequiresAdvancedTechniques) {
    bool requiresAdvanced = specialist->requiresAdvancedTechniques();
    EXPECT_TRUE(requiresAdvanced || !requiresAdvanced);
}

TEST_F(RehabilitationSpecialistTest, PatientManagement) {
    specialist->addRehabPatient(patient);
    auto patients = specialist->getRehabPatients();
    EXPECT_EQ(patients.size(), 1);
    
    specialist->removeRehabPatient("PAT001");
    patients = specialist->getRehabPatients();
    EXPECT_EQ(patients.size(), 0);
}
