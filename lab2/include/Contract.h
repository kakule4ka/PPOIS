#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

class Contract {
private:
    std::string contractId;
    std::string clientId;
    double contractValue;
    int duration;
    
public:
    Contract(const std::string& id, const std::string& clientId, double value, int duration);
    
    double calculatePenaltyForDelay(int delayDays) const;
    bool isRenewable() const;
    
    std::string getId() const { return contractId; }
};

#endif
