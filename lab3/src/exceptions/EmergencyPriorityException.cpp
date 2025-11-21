#include "EmergencyPriorityException.h"

EmergencyPriorityException::EmergencyPriorityException(const std::string& emergencyId, 
                                                     const std::string& priorityLevel, 
                                                     const std::string& conflictReason)
    : std::runtime_error("Emergency priority conflict: Case " + emergencyId + 
                        " - Priority: " + priorityLevel + 
                        " - Conflict: " + conflictReason), 
      emergencyId(emergencyId), priorityLevel(priorityLevel), conflictReason(conflictReason) {}

std::string EmergencyPriorityException::getEmergencyId() const {
    return emergencyId;
}

std::string EmergencyPriorityException::getPriorityLevel() const {
    return priorityLevel;
}

std::string EmergencyPriorityException::getConflictReason() const {
    return conflictReason;
}
