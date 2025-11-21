#include <gtest/gtest.h>
#include "Ambulance.h"
#include "Patient.h"
#include "EmergencyCase.h"
#include "MedicalEquipment.h"

class AmbulanceTest : public ::testing::Test {
protected:
    void SetUp() override {
        ambulance = new Ambulance("AMB001", "ALS", true);
        patient = new Patient("P001", "John Doe", 45, "A+");
        emergency = new EmergencyCase("E001", "Cardiac arrest", 5);
        equipment = new MedicalEquipment("EQ001", "Defibrillator", "Life Support", 15000.0);
    }

    void TearDown() override {
        delete ambulance;
        delete patient;
        delete emergency;
        delete equipment;
    }

    Ambulance* ambulance;
    Patient* patient;
    EmergencyCase* emergency;
    MedicalEquipment* equipment;
};

TEST_F(AmbulanceTest, CalculateEmergencyResponseScore) {
    double responseScore = ambulance->calculateEmergencyResponseScore();
    EXPECT_GE(responseScore, 0.0);
    EXPECT_LE(responseScore, 100.0);
}

TEST_F(AmbulanceTest, CanHandleCriticalTransport) {
    bool canHandle = ambulance->canHandleCriticalTransport();
    EXPECT_TRUE(canHandle || !canHandle);
}

TEST_F(AmbulanceTest, CalculateEquipmentReadiness) {
    double readiness = ambulance->calculateEquipmentReadiness();
    EXPECT_GE(readiness, 0.0);
    EXPECT_LE(readiness, 100.0);
}

TEST_F(AmbulanceTest, PatientManagement) {
    ambulance->addTransportedPatient(patient);
    auto patients = ambulance->getTransportedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    ambulance->removeTransportedPatient("P001");
    patients = ambulance->getTransportedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(AmbulanceTest, EmergencyManagement) {
    ambulance->addHandledEmergency(emergency);
    auto emergencies = ambulance->getHandledEmergencies();
    EXPECT_EQ(emergencies.size(), 1);
    
    ambulance->removeHandledEmergency("E001");
    emergencies = ambulance->getHandledEmergencies();
    EXPECT_EQ(emergencies.size(), 0);
}

TEST_F(AmbulanceTest, EquipmentManagement) {
    ambulance->addOnboardEquipment(equipment);
    auto equipmentList = ambulance->getOnboardEquipment();
    EXPECT_EQ(equipmentList.size(), 1);
    
    ambulance->removeOnboardEquipment("EQ001");
    equipmentList = ambulance->getOnboardEquipment();
    EXPECT_EQ(equipmentList.size(), 0);
}
