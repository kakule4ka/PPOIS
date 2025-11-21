#include "EmergencyService.h"
#include "EmergencyCase.h"
#include <algorithm>

EmergencyService::EmergencyService(const std::string& serviceId)
    : serviceId(serviceId) {}

double EmergencyService::calculateResponseEffectiveness() const {
    if (activeCases.empty()) return 0.0;
    
    double totalUrgency = 0.0;
    int criticalCases = 0;
    
    for (const auto& emergency : activeCases) {
        double urgency = emergency->calculateUrgencyScore();
        totalUrgency += urgency;
        
        if (urgency > 70.0) {
            criticalCases++;
        }
    }
    
    double avgUrgency = totalUrgency / activeCases.size();
    double criticalCaseRatio = (static_cast<double>(criticalCases) / activeCases.size()) * 30.0;
    
    return std::min(avgUrgency + criticalCaseRatio, 100.0);
}

bool EmergencyService::canHandleMassCasualty() const {
    int availableCapacity = 0;
    
    for (const auto& emergency : activeCases) {
        if (emergency->calculateResourceAllocationPriority() < 50.0) {
            availableCapacity++;
        }
    }
    
    return availableCapacity >= 5;
}

int EmergencyService::getActiveCaseCount() const {
    return activeCases.size();
}

void EmergencyService::addActiveCase(EmergencyCase* emergency) {
    if (emergency) {
        activeCases.push_back(emergency);
    }
}

void EmergencyService::removeActiveCase(const std::string& caseId) {
    activeCases.erase(
        std::remove_if(activeCases.begin(), activeCases.end(),
            [&caseId](EmergencyCase* emergency) {
                return emergency->getId() == caseId;
            }),
        activeCases.end()
    );
}

std::vector<EmergencyCase*> EmergencyService::getActiveCases() const {
    return activeCases;
}
