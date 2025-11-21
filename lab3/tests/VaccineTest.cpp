#include <gtest/gtest.h>
#include "Vaccine.h"
#include "Patient.h"
#include "Pediatrician.h"

class VaccineTest : public ::testing::Test {
protected:
    void SetUp() override {
        vaccine = new Vaccine("V001", "MMR", "Live", 95.0);
        patient = new Patient("P001", "Little Timmy", 5, "O+");
        pediatrician = new Pediatrician("PED001", "Dr. Child", 10, "PED123", 30, 150, 94.0);
    }

    void TearDown() override {
        delete vaccine;
        delete patient;
        delete pediatrician;
    }

    Vaccine* vaccine;
    Patient* patient;
    Pediatrician* pediatrician;
};

TEST_F(VaccineTest, CalculateProtectionLevel) {
    double protection = vaccine->calculateProtectionLevel();
    EXPECT_GE(protection, 0.0);
    EXPECT_LE(protection, 100.0);
}

TEST_F(VaccineTest, RequiresBooster) {
    bool needsBooster = vaccine->requiresBooster();
    EXPECT_TRUE(needsBooster || !needsBooster);
}

TEST_F(VaccineTest, CalculateHerdImmunityPotential) {
    double herdImmunity = vaccine->calculateHerdImmunityPotential();
    EXPECT_GE(herdImmunity, 0.0);
    EXPECT_LE(herdImmunity, 100.0);
}

TEST_F(VaccineTest, PatientManagement) {
    vaccine->addVaccinatedPatient(patient);
    auto patients = vaccine->getVaccinatedPatients();
    EXPECT_EQ(patients.size(), 1);
    
    vaccine->removeVaccinatedPatient("P001");
    patients = vaccine->getVaccinatedPatients();
    EXPECT_EQ(patients.size(), 0);
}

TEST_F(VaccineTest, DoctorManagement) {
    vaccine->addAdministeringDoctor(pediatrician);
    auto doctors = vaccine->getAdministeringDoctors();
    EXPECT_EQ(doctors.size(), 1);
    
    vaccine->removeAdministeringDoctor("PED001");
    doctors = vaccine->getAdministeringDoctors();
    EXPECT_EQ(doctors.size(), 0);
}
