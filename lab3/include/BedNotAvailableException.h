#ifndef BEDNOTAVAILABLEEXCEPTION_H
#define BEDNOTAVAILABLEEXCEPTION_H

#include <stdexcept>
#include <string>

class BedNotAvailableException : public std::runtime_error {
private:
    std::string wardId;
    std::string bedType;
    int requiredBeds;
    
public:
    BedNotAvailableException(const std::string& wardId, const std::string& bedType, int required);
    std::string getWardId() const;
    std::string getBedType() const;
    int getRequiredBeds() const;
};

#endif
