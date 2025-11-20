#include "ScheduleConflictException.h"

ScheduleConflictException::ScheduleConflictException(const std::string& task)
    : std::runtime_error("Schedule conflict with task: " + task),
      conflictingTask(task) {}

std::string ScheduleConflictException::getConflictingTask() const {
    return conflictingTask;
}
