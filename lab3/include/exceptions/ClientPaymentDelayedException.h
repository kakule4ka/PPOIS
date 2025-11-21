#ifndef CLIENTPAYMENTDELAYEDEXCEPTION_H
#define CLIENTPAYMENTDELAYEDEXCEPTION_H

#include <stdexcept>
#include <string>

class ClientPaymentDelayedException : public std::runtime_error {
private:
    std::string clientId;
    int delayDays;
    
public:
    ClientPaymentDelayedException(const std::string& client, int delay);
    std::string getClientId() const;
    int getDelayDays() const;
};

#endif
