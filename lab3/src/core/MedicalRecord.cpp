#include "MedicalRecord.h"
#include "Patient.h"
#include "Diagnosis.h"
#include <algorithm>
#include <cmath>

MedicalRecord::MedicalRecord(const std::string& id, const std::string& description, const std::string& date)
    : id(id), description(description), date(date), severityLevel(1), isChronic(false), patient(nullptr) {}

double MedicalRecord::calculateTreatmentComplexity() const {
    double baseComplexity = severityLevel * 10.0;
    
    double descriptionComplexity = 0.0;
    if (description.length() > 100) descriptionComplexity = 15.0;
    else if (description.length() > 50) descriptionComplexity = 10.0;
    
    double chronicFactor = isChronic ? 20.0 : 5.0;
    double diagnosisComplexity = diagnoses.size() * 5.0;
    
    double notesComplexity = doctorNotes.empty() ? 0.0 : 5.0;
    
    double totalComplexity = baseComplexity + descriptionComplexity + chronicFactor + diagnosisComplexity + notesComplexity;
    return std::min(totalComplexity, 100.0);
}

bool MedicalRecord::indicatesCriticalCondition() const {
    bool highSeverity = severityLevel >= 4;
    bool hasEmergencyKeywords = description.find("emergency") != std::string::npos ||
                               description.find("critical") != std::string::npos ||
                               description.find("urgent") != std::string::npos;
    
    bool multipleDiagnoses = diagnoses.size() >= 3;
    bool chronicAndSevere = isChronic && severityLevel >= 3;
    
    return highSeverity || hasEmergencyKeywords || multipleDiagnoses || chronicAndSevere;
}

double MedicalRecord::calculateRecoveryProbability() const {
    double baseProbability = 80.0;
    
    double severityPenalty = (5 - severityLevel) * 8.0;
    double chronicPenalty = isChronic ? 25.0 : 0.0;
    double diagnosisPenalty = diagnoses.size() * 3.0;
    
    double notesBonus = doctorNotes.length() > 50 ? 5.0 : 0.0;
    double descriptionClarity = description.length() < 200 ? 3.0 : 0.0;
    
    double totalProbability = baseProbability + severityPenalty - chronicPenalty - diagnosisPenalty + notesBonus + descriptionClarity;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

bool MedicalRecord::requiresFollowUp() const {
    bool isSevereCase = severityLevel >= 3;
    bool hasChronicCondition = isChronic;
    bool hasMultipleDiagnoses = diagnoses.size() > 1;
    bool hasDetailedNotes = doctorNotes.length() > 100;
    bool lowRecoveryProbability = calculateRecoveryProbability() < 60.0;
    
    return isSevereCase || hasChronicCondition || hasMultipleDiagnoses || hasDetailedNotes || lowRecoveryProbability;
}

std::string MedicalRecord::determineUrgencyLevel() const {
    if (severityLevel >= 4 || indicatesCriticalCondition()) return "IMMEDIATE";
    else if (severityLevel >= 3 || isChronic) return "URGENT";
    else if (severityLevel >= 2) return "PRIORITY";
    else return "ROUTINE";
}

void MedicalRecord::setPatient(Patient* patient) {
    this->patient = patient;
}

Patient* MedicalRecord::getPatient() const {
    return patient;
}

void MedicalRecord::addDiagnosis(Diagnosis* diagnosis) {
    if (diagnosis) {
        diagnoses.push_back(diagnosis);
    }
}

void MedicalRecord::removeDiagnosis(const std::string& diagnosisId) {
    diagnoses.erase(
        std::remove_if(diagnoses.begin(), diagnoses.end(),
            [&diagnosisId](Diagnosis* diagnosis) {
                return diagnosis->getId() == diagnosisId;
            }),
        diagnoses.end()
    );
}

std::vector<Diagnosis*> MedicalRecord::getDiagnoses() const {
    return diagnoses;
}
