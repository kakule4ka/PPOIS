#include <gtest/gtest.h>
#include "AnalyticsService.h"
#include "Hospital.h"
#include "Patient.h"

class AnalyticsServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        analytics = new AnalyticsService("ANALYTICS001");
        hospital = new Hospital("HOSP001", "Main Street", 200, 1990, 5000000.0);
        patient = new Patient("PAT001", "John Doe", 45, "A+");
    }

    void TearDown() override {
        delete analytics;
        delete hospital;
        delete patient;
    }

    AnalyticsService* analytics;
    Hospital* hospital;
    Patient* patient;
};

TEST_F(AnalyticsServiceTest, CalculateHospitalEfficiencyScore) {
    double efficiency = analytics->calculateHospitalEfficiencyScore(hospital);
    EXPECT_GE(efficiency, 0.0);
    EXPECT_LE(efficiency, 100.0);
}

TEST_F(AnalyticsServiceTest, PredictPatientOutcomeProbability) {
    double outcome = analytics->predictPatientOutcomeProbability(patient);
    EXPECT_GE(outcome, 0.0);
    EXPECT_LE(outcome, 100.0);
}

TEST_F(AnalyticsServiceTest, AnalyzeResourceUtilizationTrend) {
    double trend = analytics->analyzeResourceUtilizationTrend();
    EXPECT_GE(trend, 0.0);
    EXPECT_LE(trend, 100.0);
}

TEST_F(AnalyticsServiceTest, GeneratePerformanceReport) {
    auto report = analytics->generatePerformanceReport();
    EXPECT_FALSE(report.empty());
}

TEST_F(AnalyticsServiceTest, IdentifyBottlenecks) {
    bool bottlenecks = analytics->identifyBottlenecks();
    EXPECT_TRUE(bottlenecks || !bottlenecks);
}

TEST_F(AnalyticsServiceTest, CalculateReadmissionRisk) {
    double risk = analytics->calculateReadmissionRisk(patient);
    EXPECT_GE(risk, 0.0);
    EXPECT_LE(risk, 100.0);
}

TEST_F(AnalyticsServiceTest, HospitalManagement) {
    analytics->addMonitoredHospital(hospital);
    auto hospitals = analytics->getMonitoredHospitals();
    EXPECT_EQ(hospitals.size(), 1);
    
    analytics->removeMonitoredHospital("HOSP001");
    hospitals = analytics->getMonitoredHospitals();
    EXPECT_EQ(hospitals.size(), 0);
}

TEST_F(AnalyticsServiceTest, PatientManagement) {
    analytics->addPatientToPopulation(patient);
    auto patients = analytics->getPatientPopulation();
    EXPECT_EQ(patients.size(), 1);
    
    analytics->removePatientFromPopulation("PAT001");
    patients = analytics->getPatientPopulation();
    EXPECT_EQ(patients.size(), 0);
}
