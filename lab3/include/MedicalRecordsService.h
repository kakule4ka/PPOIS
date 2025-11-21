#ifndef MEDICALRECORDSSERVICE_H
#define MEDICALRECORDSSERVICE_H

#include <string>
#include <vector>

class MedicalRecord;

class MedicalRecordsService {
private:
    std::string serviceId;
    std::vector<MedicalRecord*> storedRecords;

public:
    MedicalRecordsService(const std::string& serviceId);
    
    double calculateRecordCompleteness() const;
    bool validateRecordSecurity() const;
    int getTotalRecordCount() const;
    
    void addStoredRecord(MedicalRecord* record);
    void removeStoredRecord(const std::string& recordId);
    std::vector<MedicalRecord*> getStoredRecords() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
