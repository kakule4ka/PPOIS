#ifndef SCHEDULECONFLICTEXCEPTION_H
#define SCHEDULECONFLICTEXCEPTION_H

#include <stdexcept>
#include <string>

class ScheduleConflictException : public std::runtime_error {
private:
    std::string conflictingTask;
    
public:
    ScheduleConflictException(const std::string& task);
    std::string getConflictingTask() const;
};

#endif
