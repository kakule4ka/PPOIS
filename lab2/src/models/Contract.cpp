#include "Contract.h"

Contract::Contract(const std::string& id, const std::string& clientId, double value, int duration)
    : contractId(id), clientId(clientId), contractValue(value), duration(duration) {}

double Contract::calculatePenaltyForDelay(int delayDays) const {
    double dailyPenaltyRate = 0.02;
    double basePenalty = contractValue * dailyPenaltyRate * delayDays;
    
    if (delayDays > 30) {
        basePenalty *= 1.5;
    }
    
    if (contractValue > 1000000) {
        basePenalty *= 0.8;
    }
    
    return basePenalty;
}

bool Contract::isRenewable() const {
    return duration >= 24 && contractValue > 50000;
}
