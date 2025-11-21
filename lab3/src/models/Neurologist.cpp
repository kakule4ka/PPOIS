#include "Neurologist.h"
#include "Patient.h"
#include "LaboratoryTest.h"
#include <algorithm>
#include <cmath>

Neurologist::Neurologist(const std::string& id, const std::string& name, int experience, 
                        const std::string& license, int maxPatients, int assessments, double accuracy)
    : Doctor(id, name, "Neurology", experience, license, maxPatients),
      neurologicalAssessments(assessments), diagnosticAccuracy(accuracy),
      subSpecialty("General Neurology") {}

double Neurologist::calculateNeurologicalDisorderProbability(const Patient* patient) const {
    if (!patient) return 0.0;
    
    double baseProbability = 15.0;
    
    double ageProbability = patient->getAge() > 60 ? 25.0 : 10.0;
    double geneticProbability = patient->getBloodType() == "O+" ? 8.0 : 3.0;
    
    double lifestyleProbability = patient->calculateBMI() > 28.0 ? 12.0 : 5.0;
    double stressProbability = patient->calculateHealthRiskScore() > 50.0 ? 15.0 : 7.0;
    
    double diagnosticFactor = diagnosticAccuracy * 0.3;
    double experienceFactor = getExperienceYears() * 0.4;
    
    double testAccuracyFactor = 0.0;
    for (const auto& test : specializedTests) {
        if (test->getAccuracy() > 90.0) {
            testAccuracyFactor += 2.0;
        }
    }
    
    double totalProbability = baseProbability + ageProbability + geneticProbability + 
                             lifestyleProbability + stressProbability - diagnosticFactor - 
                             experienceFactor - testAccuracyFactor;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

bool Neurologist::canDiagnoseComplexConditions() const {
    bool extensiveExperience = getExperienceYears() >= 10;
    bool highDiagnosticAccuracy = diagnosticAccuracy >= 88.0;
    bool sufficientAssessments = neurologicalAssessments >= 100;
    bool hasAdvancedTests = false;
    
    for (const auto& test : specializedTests) {
        if (test->getType() == "Neurological" || test->getType() == "Genetic" ||
            test->getName().find("MRI") != std::string::npos ||
            test->getName().find("EEG") != std::string::npos) {
            hasAdvancedTests = true;
            break;
        }
    }
    
    bool specializedTraining = subSpecialty != "General Neurology";
    
    return extensiveExperience && highDiagnosticAccuracy && sufficientAssessments && 
           hasAdvancedTests && specializedTraining;
}

double Neurologist::calculateTherapeuticSuccessRate() const {
    double baseSuccessRate = diagnosticAccuracy;
    
    double experienceSuccess = getExperienceYears() * 1.1;
    double assessmentSuccess = neurologicalAssessments * 0.12;
    
    double patientImprovementSuccess = 0.0;
    for (const auto& patient : neurologicalPatients) {
        if (patient->calculateHealthRiskScore() < 35.0) {
            patientImprovementSuccess += 2.5;
        }
    }
    
    double testContributionSuccess = 0.0;
    for (const auto& test : specializedTests) {
        if (test->calculateDiagnosticValue() > 80.0) {
            testContributionSuccess += 1.8;
        }
    }
    
    double specialtySuccess = subSpecialty == "Epilepsy" || subSpecialty == "Movement Disorders" ? 8.0 : 3.0;
    
    double totalSuccessRate = baseSuccessRate + experienceSuccess + assessmentSuccess + 
                             patientImprovementSuccess + testContributionSuccess + specialtySuccess;
    return std::min(totalSuccessRate, 100.0);
}

void Neurologist::addNeurologicalPatient(Patient* patient) {
    if (patient) {
        neurologicalPatients.push_back(patient);
    }
}

void Neurologist::removeNeurologicalPatient(const std::string& patientId) {
    neurologicalPatients.erase(
        std::remove_if(neurologicalPatients.begin(), neurologicalPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        neurologicalPatients.end()
    );
}

std::vector<Patient*> Neurologist::getNeurologicalPatients() const {
    return neurologicalPatients;
}

void Neurologist::addSpecializedTest(LaboratoryTest* test) {
    if (test) {
        specializedTests.push_back(test);
    }
}

void Neurologist::removeSpecializedTest(const std::string& testId) {
    specializedTests.erase(
        std::remove_if(specializedTests.begin(), specializedTests.end(),
            [&testId](LaboratoryTest* test) {
                return test->getId() == testId;
            }),
        specializedTests.end()
    );
}

std::vector<LaboratoryTest*> Neurologist::getSpecializedTests() const {
    return specializedTests;
}
