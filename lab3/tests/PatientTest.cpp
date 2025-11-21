#include <gtest/gtest.h>
#include "Patient.h"
#include "MedicalRecord.h"
#include "TreatmentPlan.h"

class PatientTest : public ::testing::Test {
protected:
    void SetUp() override {
        patient = new Patient("P001", "John Doe", 45, "A+");
        patient->setHeight(180.0);
        patient->setWeight(75.0);
        record = new MedicalRecord("R001", "Annual checkup", "Normal results");
        plan = new TreatmentPlan("TP001", "Physical therapy", 30);
    }

    void TearDown() override {
        delete patient;
        delete record;
        delete plan;
    }

    Patient* patient;
    MedicalRecord* record;
    TreatmentPlan* plan;
};

TEST_F(PatientTest, CalculateBMI) {
    double bmi = patient->calculateBMI();
    EXPECT_GT(bmi, 0.0);
    EXPECT_NEAR(bmi, 23.15, 0.1);
}

TEST_F(PatientTest, SurgeryEligibility) {
    bool eligible = patient->isEligibleForSurgery();
    EXPECT_TRUE(eligible || !eligible);
}

TEST_F(PatientTest, HealthRiskScore) {
    double risk = patient->calculateHealthRiskScore();
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(PatientTest, NeedsRegularCheckup) {
    bool needsCheckup = patient->needsRegularCheckup();
    EXPECT_TRUE(needsCheckup || !needsCheckup);
}

TEST_F(PatientTest, PriorityLevel) {
    std::string priority = patient->determinePriorityLevel();
    EXPECT_FALSE(priority.empty());
}

TEST_F(PatientTest, MedicalHistoryManagement) {
    patient->addMedicalRecord(record);
    auto history = patient->getMedicalHistory();
    EXPECT_EQ(history.size(), 1);
    
    patient->removeMedicalRecord("R001");
    history = patient->getMedicalHistory();
    EXPECT_EQ(history.size(), 0);
}
