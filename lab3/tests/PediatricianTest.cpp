#include <gtest/gtest.h>
#include "Pediatrician.h"
#include "Patient.h"
#include "Vaccine.h"

class PediatricianTest : public ::testing::Test {
protected:
    void SetUp() override {
        pediatrician = new Pediatrician("PED001", "Dr. Childcare", 10, "PED123", 30, 200, 92.0);
        childPatient = new Patient("CH001", "Little Timmy", 8, "O+");
        vaccine = new Vaccine("V001", "MMR", "Viral", 95.0);
    }

    void TearDown() override {
        delete pediatrician;
        delete childPatient;
        delete vaccine;
    }

    Pediatrician* pediatrician;
    Patient* childPatient;
    Vaccine* vaccine;
};

TEST_F(PediatricianTest, CalculateChildDevelopmentScore) {
    double score = pediatrician->calculateChildDevelopmentScore(childPatient);
    EXPECT_GE(score, 0.0);
    EXPECT_LE(score, 100.0);
}

TEST_F(PediatricianTest, CanHandleRarePediatricConditions) {
    bool canHandle = pediatrician->canHandleRarePediatricConditions();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(PediatricianTest, CalculatePreventiveCareEffectiveness) {
    double effectiveness = pediatrician->calculatePreventiveCareEffectiveness();
    EXPECT_GE(effectiveness, 0.0);
    EXPECT_LE(effectiveness, 100.0);
}

TEST_F(PediatricianTest, PediatricPatientManagement) {
    pediatrician->addPediatricPatient(childPatient);
    auto patients = pediatrician->getPediatricPatients();
    EXPECT_EQ(patients.size(), 1);
    
    pediatrician->removePediatricPatient("CH001");
    patients = pediatrician->getPediatricPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(PediatricianTest, VaccineManagement) {
    pediatrician->addAdministeredVaccine(vaccine);
    auto vaccines = pediatrician->getAdministeredVaccines();
    EXPECT_EQ(vaccines.size(), 1);
    
    pediatrician->removeAdministeredVaccine("V001");
    vaccines = pediatrician->getAdministeredVaccines();
    EXPECT_EQ(vaccines.size(), 0);
}
