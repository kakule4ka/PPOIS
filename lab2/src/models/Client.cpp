#include "Client.h"

Client::Client(const std::string& id, const std::string& name, double budget)
    : id(id), name(name), budget(budget) {}

bool Client::validateProjectBudget(double cost) const {
    return cost <= budget * 1.1;
}

double Client::calculatePaymentPlan(int months) const {
    return months > 0 ? budget / months : budget;
}
