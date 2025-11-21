#include "MedicalEquipment.h"
#include "MedicalDepartment.h"
#include "Patient.h"
#include <algorithm>
#include <cmath>

MedicalEquipment::MedicalEquipment(const std::string& id, const std::string& name, const std::string& type, double cost)
    : id(id), name(name), type(type), cost(cost), maintenanceInterval(180), usageHours(0), isOperational(true) {}

double MedicalEquipment::calculateMaintenanceCost() const {
    double baseCost = cost * 0.02;
    
    double usageMultiplier = 1.0 + (usageHours / 1000.0);
    double typeMultiplier = 1.0;
    
    if (type == "Imaging") typeMultiplier = 1.5;
    else if (type == "Surgical") typeMultiplier = 1.8;
    else if (type == "Monitoring") typeMultiplier = 1.2;
    
    double ageFactor = usageHours > 5000 ? 1.3 : 1.0;
    double departmentFactor = 1.0 + (departments.size() * 0.1);
    
    return baseCost * usageMultiplier * typeMultiplier * ageFactor * departmentFactor;
}

bool MedicalEquipment::needsMaintenance() const {
    bool overdueMaintenance = usageHours >= maintenanceInterval;
    bool highUsage = usageHours > 2000;
    bool multipleDepartments = departments.size() >= 3;
    bool criticalEquipment = type == "Surgical" || type == "Life Support";
    bool hasManyPatients = treatedPatients.size() > 50;
    
    return overdueMaintenance || (highUsage && criticalEquipment) || multipleDepartments || hasManyPatients;
}

double MedicalEquipment::calculateUtilizationEfficiency() const {
    if (usageHours == 0) return 0.0;
    
    double baseEfficiency = 75.0;
    
    double usageEfficiency = std::min(usageHours / 10.0, 20.0);
    double departmentEfficiency = departments.size() * 3.0;
    double patientEfficiency = treatedPatients.size() * 1.0;
    
    double maintenancePenalty = needsMaintenance() ? 15.0 : 0.0;
    double operationalPenalty = !isOperational ? 25.0 : 0.0;
    
    double typeBonus = 0.0;
    if (type == "Diagnostic") typeBonus = 5.0;
    else if (type == "Therapeutic") typeBonus = 7.0;
    
    double totalEfficiency = baseEfficiency + usageEfficiency + departmentEfficiency + 
                           patientEfficiency - maintenancePenalty - operationalPenalty + typeBonus;
    return std::max(0.0, std::min(totalEfficiency, 100.0));
}

void MedicalEquipment::addDepartment(MedicalDepartment* department) {
    if (department) {
        departments.push_back(department);
    }
}

void MedicalEquipment::removeDepartment(const std::string& departmentId) {
    departments.erase(
        std::remove_if(departments.begin(), departments.end(),
            [&departmentId](MedicalDepartment* department) {
                return department->getId() == departmentId;
            }),
        departments.end()
    );
}

std::vector<MedicalDepartment*> MedicalEquipment::getDepartments() const {
    return departments;
}

void MedicalEquipment::addTreatedPatient(Patient* patient) {
    if (patient) {
        treatedPatients.push_back(patient);
    }
}

void MedicalEquipment::removeTreatedPatient(const std::string& patientId) {
    treatedPatients.erase(
        std::remove_if(treatedPatients.begin(), treatedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        treatedPatients.end()
    );
}

std::vector<Patient*> MedicalEquipment::getTreatedPatients() const {
    return treatedPatients;
}
