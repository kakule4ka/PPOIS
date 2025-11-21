#ifndef PHARMACY_H
#define PHARMACY_H

#include <string>
#include <vector>

class Medication;
class Patient;
class Doctor;

class Pharmacy {
private:
    std::string id;
    std::string name;
    int inventorySize;
    double prescriptionAccuracy;
    std::vector<Medication*> availableMedications;
    std::vector<Patient*> servedPatients;
    std::vector<Doctor*> collaboratingDoctors;

public:
    Pharmacy(const std::string& id, const std::string& name, int inventorySize);
    
    double calculateInventoryTurnover() const;
    bool canDispenseSpecializedMeds() const;
    double calculateServiceEfficiency() const;
    
    void addMedication(Medication* medication);
    void removeMedication(const std::string& medicationId);
    std::vector<Medication*> getAvailableMedications() const;
    
    void addServedPatient(Patient* patient);
    void removeServedPatient(const std::string& patientId);
    std::vector<Patient*> getServedPatients() const;
    
    void addCollaboratingDoctor(Doctor* doctor);
    void removeCollaboratingDoctor(const std::string& doctorId);
    std::vector<Doctor*> getCollaboratingDoctors() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    int getInventorySize() const { return inventorySize; }
    void setPrescriptionAccuracy(double accuracy) { prescriptionAccuracy = accuracy; }
    double getPrescriptionAccuracy() const { return prescriptionAccuracy; }
};

#endif
