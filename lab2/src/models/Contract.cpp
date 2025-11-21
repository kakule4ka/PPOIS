#include "Contract.h"
#include <algorithm>
#include "Client.h"
#include <algorithm>
#include "ConstructionCompany.h"
#include <algorithm>
#include "ConstructionProject.h"
#include <algorithm>

Contract::Contract(const std::string& id, const std::string& clientId, double value, int duration)
    : contractId(id), clientId(clientId), contractValue(value), duration(duration),
      client(nullptr), company(nullptr), project(nullptr) {}

double Contract::calculatePenaltyForDelay(int delayDays) const {
    double dailyPenaltyRate = 0.02;
    double basePenalty = contractValue * dailyPenaltyRate * delayDays;
    
    if (delayDays > 30) {
        basePenalty *= 1.5;
    }
    
    if (contractValue > 1000000) {
        basePenalty *= 0.8;
    }
    
    double clientReliabilityFactor = client ? (client->isReliableClient() ? 0.9 : 1.1) : 1.0;
    double projectComplexityFactor = project ? 1.05 : 1.0;
    
    return basePenalty * clientReliabilityFactor * projectComplexityFactor;
}

bool Contract::isRenewable() const {
    return duration >= 24 && contractValue > 50000;
}

double Contract::calculateProfitMargin() const {
    double baseProfit = contractValue * 0.15;
    
    double durationFactor = 1.0;
    if (duration > 36) {
        durationFactor = 0.9;
    } else if (duration < 12) {
        durationFactor = 1.1;
    }
    
    double clientFactor = client ? (client->isReliableClient() ? 1.05 : 0.95) : 1.0;
    double companyFactor = company ? 1.02 : 1.0;
    double projectRiskFactor = project ? 0.98 : 1.0;
    
    return baseProfit * durationFactor * clientFactor * companyFactor * projectRiskFactor;
}

bool Contract::hasBreachOfContract() const {
    if (!project) return false;
    
    double projectDuration = project->getDuration();
    bool isOverdue = projectDuration > duration;
    
    double penaltyThreshold = contractValue * 0.1;
    double calculatedPenalty = calculatePenaltyForDelay(projectDuration - duration);
    bool hasSignificantPenalty = calculatedPenalty > penaltyThreshold;
    
    bool clientIssues = client ? !client->isReliableClient() : false;
    
    return isOverdue && (hasSignificantPenalty || clientIssues);
}

void Contract::setClient(Client* client) {
    this->client = client;
}

Client* Contract::getClient() const {
    return client;
}

void Contract::setCompany(ConstructionCompany* company) {
    this->company = company;
}

ConstructionCompany* Contract::getCompany() const {
    return company;
}

void Contract::setProject(ConstructionProject* project) {
    this->project = project;
}

ConstructionProject* Contract::getProject() const {
    return project;
}
