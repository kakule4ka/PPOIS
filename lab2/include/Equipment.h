#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment {
private:
    std::string equipmentId;
    std::string type;
    double maintenanceCost;
    int hoursUsed;
    
public:
    Equipment(const std::string& id, const std::string& type, double maintenanceCost);
    
    double calculateDepreciation() const;
    bool needsMaintenance() const;
    void setHoursUsed(int hours);
    
    std::string getId() const { return equipmentId; }
};

#endif
