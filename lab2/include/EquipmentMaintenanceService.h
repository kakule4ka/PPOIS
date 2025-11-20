#ifndef EQUIPMENTMAINTENANCESERVICE_H
#define EQUIPMENTMAINTENANCESERVICE_H

#include <string>

class EquipmentMaintenanceService {
private:
    std::string serviceId;
    int maintainedEquipment;
    double uptimeRate;
    
public:
    EquipmentMaintenanceService(const std::string& id, int equipment, double uptime);
    
    double calculateMaintenanceCost() const;
    bool predictEquipmentFailure() const;
    
    std::string getId() const { return serviceId; }
};

#endif
