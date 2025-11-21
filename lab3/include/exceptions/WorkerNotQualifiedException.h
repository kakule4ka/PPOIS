#ifndef WORKERNOTQUALIFIEDEXCEPTION_H
#define WORKERNOTQUALIFIEDEXCEPTION_H

#include <stdexcept>
#include <string>

class WorkerNotQualifiedException : public std::runtime_error {
private:
    std::string workerId;
    std::string requiredSkill;
    
public:
    WorkerNotQualifiedException(const std::string& worker, const std::string& skill);
    std::string getWorkerId() const;
    std::string getRequiredSkill() const;
};

#endif
