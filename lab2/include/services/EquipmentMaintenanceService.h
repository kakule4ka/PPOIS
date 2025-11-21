#ifndef EQUIPMENTMAINTENANCESERVICE_H
#define EQUIPMENTMAINTENANCESERVICE_H

#include <string>
#include <vector>

class Equipment;
class ConstructionProject;

class EquipmentMaintenanceService {
private:
    std::string serviceId;
    int maintainedEquipment;
    double uptimeRate;
    std::vector<Equipment*> equipmentList;
    std::vector<ConstructionProject*> supportedProjects;
    
public:
    EquipmentMaintenanceService(const std::string& id, int equipment, double uptime);
    
    double calculateMaintenanceCost() const;
    bool predictEquipmentFailure() const;
    double calculateServiceReliability() const;
    bool requiresPreventiveMaintenance() const;
    
    void addEquipment(Equipment* equipment);
    void removeEquipment(const std::string& equipmentId);
    std::vector<Equipment*> getEquipmentList() const;
    
    void addSupportedProject(ConstructionProject* project);
    void removeSupportedProject(const std::string& projectId);
    std::vector<ConstructionProject*> getSupportedProjects() const;
    
    std::string getId() const { return serviceId; }
};

#endif
