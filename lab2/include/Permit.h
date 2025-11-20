#ifndef PERMIT_H
#define PERMIT_H

#include <string>

class Permit {
private:
    std::string permitId;
    std::string type;
    std::string issuingAuthority;
    bool isActive;
    
public:
    Permit(const std::string& id, const std::string& type, const std::string& authority);
    
    bool validateExpiryDate() const;
    double calculateProcessingTime() const;
    
    std::string getId() const { return permitId; }
};

#endif
