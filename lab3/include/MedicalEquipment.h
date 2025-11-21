#ifndef MEDICALEQUIPMENT_H
#define MEDICALEQUIPMENT_H

#include <string>
#include <vector>

class MedicalDepartment;
class Patient;

class MedicalEquipment {
private:
    std::string id;
    std::string name;
    std::string type;
    double cost;
    int maintenanceInterval;
    int usageHours;
    bool isOperational;
    std::vector<MedicalDepartment*> departments;
    std::vector<Patient*> treatedPatients;

public:
    MedicalEquipment(const std::string& id, const std::string& name, const std::string& type, double cost);
    
    double calculateMaintenanceCost() const;
    bool needsMaintenance() const;
    double calculateUtilizationEfficiency() const;
    
    void addDepartment(MedicalDepartment* department);
    void removeDepartment(const std::string& departmentId);
    std::vector<MedicalDepartment*> getDepartments() const;
    
    void addTreatedPatient(Patient* patient);
    void removeTreatedPatient(const std::string& patientId);
    std::vector<Patient*> getTreatedPatients() const;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    double getCost() const { return cost; }
    void setMaintenanceInterval(int interval) { maintenanceInterval = interval; }
    void setUsageHours(int hours) { usageHours = hours; }
    void setIsOperational(bool operational) { isOperational = operational; }
    int getMaintenanceInterval() const { return maintenanceInterval; }
    int getUsageHours() const { return usageHours; }
    bool getIsOperational() const { return isOperational; }
};

#endif
