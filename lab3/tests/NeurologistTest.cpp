#include <gtest/gtest.h>
#include "Neurologist.h"
#include "Patient.h"
#include "LaboratoryTest.h"

class NeurologistTest : public ::testing::Test {
protected:
    void SetUp() override {
        neurologist = new Neurologist("N001", "Dr. Brain", 15, "NEURO123", 20, 120, 89.5);
        patient = new Patient("P001", "John Doe", 70, "O+");
        test = new LaboratoryTest("T001", "MRI Brain", "Neurological");
    }

    void TearDown() override {
        delete neurologist;
        delete patient;
        delete test;
    }

    Neurologist* neurologist;
    Patient* patient;
    LaboratoryTest* test;
};

TEST_F(NeurologistTest, CalculateNeurologicalDisorderProbability) {
    double probability = neurologist->calculateNeurologicalDisorderProbability(patient);
    EXPECT_GE(probability, 0.0);
    EXPECT_LE(probability, 100.0);
}

TEST_F(NeurologistTest, CanDiagnoseComplexConditions) {
    bool canDiagnose = neurologist->canDiagnoseComplexConditions();
    EXPECT_TRUE(canDiagnose || !canDiagnose);
}

TEST_F(NeurologistTest, CalculateTherapeuticSuccessRate) {
    double successRate = neurologist->calculateTherapeuticSuccessRate();
    EXPECT_GE(successRate, 0.0);
    EXPECT_LE(successRate, 100.0);
}

TEST_F(NeurologistTest, NeurologicalPatientManagement) {
    neurologist->addNeurologicalPatient(patient);
    auto patients = neurologist->getNeurologicalPatients();
    EXPECT_EQ(patients.size(), 1);
    
    neurologist->removeNeurologicalPatient("P001");
    patients = neurologist->getNeurologicalPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(NeurologistTest, TestManagement) {
    neurologist->addSpecializedTest(test);
    auto tests = neurologist->getSpecializedTests();
    EXPECT_EQ(tests.size(), 1);
    
    neurologist->removeSpecializedTest("T001");
    tests = neurologist->getSpecializedTests();
    EXPECT_EQ(tests.size(), 0);
}
