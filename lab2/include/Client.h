#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string id;
    std::string name;
    double budget;
    
public:
    Client(const std::string& id, const std::string& name, double budget);
    
    bool validateProjectBudget(double cost) const;
    double calculatePaymentPlan(int months) const;
    
    std::string getId() const { return id; }
};

#endif
