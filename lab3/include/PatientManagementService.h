#ifndef PATIENTMANAGEMENTSERVICE_H
#define PATIENTMANAGEMENTSERVICE_H

#include <string>
#include <vector>

class Patient;

class PatientManagementService {
private:
    std::string serviceId;
    std::vector<Patient*> managedPatients;

public:
    PatientManagementService(const std::string& serviceId);
    
    double calculatePatientSatisfaction() const;
    bool validatePatientCareStandards() const;
    int getActivePatientCount() const;
    
    void addManagedPatient(Patient* patient);
    void removeManagedPatient(const std::string& patientId);
    std::vector<Patient*> getManagedPatients() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
