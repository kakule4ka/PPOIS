#ifndef EMERGENCYPRIORITYEXCEPTION_H
#define EMERGENCYPRIORITYEXCEPTION_H

#include <stdexcept>
#include <string>

class EmergencyPriorityException : public std::runtime_error {
private:
    std::string emergencyId;
    std::string priorityLevel;
    std::string conflictReason;
    
public:
    EmergencyPriorityException(const std::string& emergencyId, const std::string& priorityLevel, const std::string& conflictReason);
    std::string getEmergencyId() const;
    std::string getPriorityLevel() const;
    std::string getConflictReason() const;
};

#endif
