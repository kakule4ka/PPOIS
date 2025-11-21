#include "LaboratoryService.h"
#include "LaboratoryTest.h"
#include <algorithm>

LaboratoryService::LaboratoryService(const std::string& serviceId)
    : serviceId(serviceId) {}

double LaboratoryService::calculateProcessingEfficiency() const {
    if (activeTests.empty()) return 0.0;
    
    double totalEfficiency = 0.0;
    int urgentTests = 0;
    
    for (const auto& test : activeTests) {
        double diagnosticValue = test->calculateDiagnosticValue();
        totalEfficiency += diagnosticValue;
        
        if (test->isHighPriority()) {
            urgentTests++;
        }
    }
    
    double avgEfficiency = totalEfficiency / activeTests.size();
    double urgentTestBonus = (static_cast<double>(urgentTests) / activeTests.size()) * 25.0;
    
    return std::min(avgEfficiency + urgentTestBonus, 100.0);
}

bool LaboratoryService::validateTestAccuracy() const {
    if (activeTests.empty()) return false;
    
    int accurateTests = 0;
    for (const auto& test : activeTests) {
        if (test->calculateResultReliability() >= 90.0) {
            accurateTests++;
        }
    }
    
    double accuracyRate = static_cast<double>(accurateTests) / activeTests.size();
    return accuracyRate >= 0.95;
}

int LaboratoryService::getPendingTestCount() const {
    return activeTests.size();
}

void LaboratoryService::addActiveTest(LaboratoryTest* test) {
    if (test) {
        activeTests.push_back(test);
    }
}

void LaboratoryService::removeActiveTest(const std::string& testId) {
    activeTests.erase(
        std::remove_if(activeTests.begin(), activeTests.end(),
            [&testId](LaboratoryTest* test) {
                return test->getId() == testId;
            }),
        activeTests.end()
    );
}

std::vector<LaboratoryTest*> LaboratoryService::getActiveTests() const {
    return activeTests;
}
