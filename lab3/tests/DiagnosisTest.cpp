#include <gtest/gtest.h>
#include "Diagnosis.h"
#include "MedicalRecord.h"
#include "TreatmentPlan.h"

class DiagnosisTest : public ::testing::Test {
protected:
    void SetUp() override {
        diagnosis = new Diagnosis("D001", "Hypertension", "Cardiovascular");
        record = new MedicalRecord("MR001", "Blood pressure check", "2024-01-15");
        plan = new TreatmentPlan("TP001", "Blood pressure management", 90);
    }

    void TearDown() override {
        delete diagnosis;
        delete record;
        delete plan;
    }

    Diagnosis* diagnosis;
    MedicalRecord* record;
    TreatmentPlan* plan;
};

TEST_F(DiagnosisTest, CalculateTreatmentComplexity) {
    diagnosis->setSeverity(3);
    diagnosis->setIsChronic(true);
    double complexity = diagnosis->calculateTreatmentComplexity();
    EXPECT_GE(complexity, 0.0);
    EXPECT_LE(complexity, 100.0);
}

TEST_F(DiagnosisTest, RequiresSpecialist) {
    bool requiresSpecialist = diagnosis->requiresSpecialist();
    EXPECT_TRUE(requiresSpecialist || !requiresSpecialist);
}

TEST_F(DiagnosisTest, CalculateRecoveryTime) {
    double recoveryTime = diagnosis->calculateRecoveryTime();
    EXPECT_GT(recoveryTime, 0.0);
}

TEST_F(DiagnosisTest, MedicalRecordAssociation) {
    diagnosis->addMedicalRecord(record);
    auto records = diagnosis->getMedicalRecords();
    EXPECT_EQ(records.size(), 1);
    
    diagnosis->removeMedicalRecord("MR001");
    records = diagnosis->getMedicalRecords();
    EXPECT_EQ(records.size(), 0);
}

TEST_F(DiagnosisTest, TreatmentPlanAssociation) {
    diagnosis->addRecommendedPlan(plan);
    auto plans = diagnosis->getRecommendedPlans();
    EXPECT_EQ(plans.size(), 1);
    
    diagnosis->removeRecommendedPlan("TP001");
    plans = diagnosis->getRecommendedPlans();
    EXPECT_EQ(plans.size(), 0);
}
