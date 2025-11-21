#ifndef PERMITNOTGRANTEDEXCEPTION_H
#define PERMITNOTGRANTEDEXCEPTION_H

#include <stdexcept>
#include <string>

class PermitNotGrantedException : public std::runtime_error {
private:
    std::string permitType;
    
public:
    PermitNotGrantedException(const std::string& permit);
    std::string getPermitType() const;
};

#endif
