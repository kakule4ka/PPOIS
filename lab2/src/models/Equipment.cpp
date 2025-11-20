#include "Equipment.h"

Equipment::Equipment(const std::string& id, const std::string& type, double maintenanceCost)
    : equipmentId(id), type(type), maintenanceCost(maintenanceCost), hoursUsed(0) {}

double Equipment::calculateDepreciation() const {
    return maintenanceCost * 0.1;
}

bool Equipment::needsMaintenance() const {
    return hoursUsed > 1000;
}

void Equipment::setHoursUsed(int hours) {
    hoursUsed = hours;
}
