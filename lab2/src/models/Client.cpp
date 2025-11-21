#include "models/Client.h"
#include "core/ConstructionProject.h"
#include "models/Contract.h"
#include <algorithm>

Client::Client(const std::string& id, const std::string& name, double budget)
    : id(id), name(name), budget(budget) {}

bool Client::validateProjectBudget(double cost) const {
    return cost <= budget * 0.8;
}

double Client::calculatePaymentPlan(int months) const {
    if (months <= 0) return 0.0;
    return budget / months;
}

double Client::calculateTotalInvestment() const {
    double totalInvestment = 0.0;
    for (const auto& project : projects) {
        totalInvestment += project->calculateMonthlyCost() * project->getDuration();
    }
    return totalInvestment;
}

bool Client::isReliableClient() const {
    double investment = calculateTotalInvestment();
    bool hasContracts = !contracts.empty();
    bool withinBudget = investment <= budget;
    bool hasMultipleProjects = projects.size() >= 1;
    
    return hasContracts && withinBudget && hasMultipleProjects;
}

void Client::addProject(ConstructionProject* project) {
    if (project) {
        projects.push_back(project);
    }
}

void Client::removeProject(const std::string& projectId) {
    projects.erase(
        std::remove_if(projects.begin(), projects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        projects.end()
    );
}

std::vector<ConstructionProject*> Client::getProjects() const {
    return projects;
}

void Client::addContract(Contract* contract) {
    if (contract) {
        contracts.push_back(contract);
    }
}

void Client::removeContract(const std::string& contractId) {
    contracts.erase(
        std::remove_if(contracts.begin(), contracts.end(),
            [&contractId](Contract* contract) {
                return contract->getId() == contractId;
            }),
        contracts.end()
    );
}

std::vector<Contract*> Client::getContracts() const {
    return contracts;
}
