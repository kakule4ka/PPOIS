#include "MedicalRecordsService.h"
#include "MedicalRecord.h"
#include <algorithm>

MedicalRecordsService::MedicalRecordsService(const std::string& serviceId)
    : serviceId(serviceId) {}

double MedicalRecordsService::calculateRecordCompleteness() const {
    if (storedRecords.empty()) return 0.0;
    
    double totalCompleteness = 0.0;
    int criticalRecords = 0;
    
    for (const auto& record : storedRecords) {
        double complexity = record->calculateTreatmentComplexity();
        totalCompleteness += complexity;
        
        if (record->indicatesCriticalCondition()) {
            criticalRecords++;
        }
    }
    
    double avgCompleteness = totalCompleteness / storedRecords.size();
    double criticalRecordBonus = (static_cast<double>(criticalRecords) / storedRecords.size()) * 20.0;
    
    return std::min(avgCompleteness + criticalRecordBonus, 100.0);
}

bool MedicalRecordsService::validateRecordSecurity() const {
    if (storedRecords.empty()) return false;
    
    int secureRecords = 0;
    for (const auto& record : storedRecords) {
        if (!record->indicatesCriticalCondition() || record->determineUrgencyLevel() != "IMMEDIATE") {
            secureRecords++;
        }
    }
    
    double securityRate = static_cast<double>(secureRecords) / storedRecords.size();
    return securityRate >= 0.85;
}

int MedicalRecordsService::getTotalRecordCount() const {
    return storedRecords.size();
}

void MedicalRecordsService::addStoredRecord(MedicalRecord* record) {
    if (record) {
        storedRecords.push_back(record);
    }
}

void MedicalRecordsService::removeStoredRecord(const std::string& recordId) {
    storedRecords.erase(
        std::remove_if(storedRecords.begin(), storedRecords.end(),
            [&recordId](MedicalRecord* record) {
                return record->getId() == recordId;
            }),
        storedRecords.end()
    );
}

std::vector<MedicalRecord*> MedicalRecordsService::getStoredRecords() const {
    return storedRecords;
}
