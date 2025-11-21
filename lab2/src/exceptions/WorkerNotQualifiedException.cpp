#include "exceptions/WorkerNotQualifiedException.h"

WorkerNotQualifiedException::WorkerNotQualifiedException(const std::string& worker, const std::string& skill)
    : std::runtime_error("Worker not qualified: " + worker + " for skill: " + skill),
      workerId(worker), requiredSkill(skill) {}

std::string WorkerNotQualifiedException::getWorkerId() const {
    return workerId;
}

std::string WorkerNotQualifiedException::getRequiredSkill() const {
    return requiredSkill;
}
