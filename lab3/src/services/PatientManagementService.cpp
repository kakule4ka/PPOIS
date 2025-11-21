#include "PatientManagementService.h"
#include "Patient.h"
#include <algorithm>

PatientManagementService::PatientManagementService(const std::string& serviceId)
    : serviceId(serviceId) {}

double PatientManagementService::calculatePatientSatisfaction() const {
    if (managedPatients.empty()) return 0.0;
    
    double totalSatisfaction = 0.0;
    int highRiskPatients = 0;
    
    for (const auto& patient : managedPatients) {
        double healthScore = 100.0 - patient->calculateHealthRiskScore();
        totalSatisfaction += healthScore;
        
        if (patient->calculateHealthRiskScore() > 60.0) {
            highRiskPatients++;
        }
    }
    
    double avgSatisfaction = totalSatisfaction / managedPatients.size();
    double highRiskAdjustment = (static_cast<double>(highRiskPatients) / managedPatients.size()) * 15.0;
    
    return std::min(avgSatisfaction - highRiskAdjustment, 100.0);
}

bool PatientManagementService::validatePatientCareStandards() const {
    if (managedPatients.empty()) return false;
    
    int compliantPatients = 0;
    for (const auto& patient : managedPatients) {
        if (patient->needsRegularCheckup() && patient->getTreatmentPlan() != nullptr) {
            compliantPatients++;
        }
    }
    
    double complianceRate = static_cast<double>(compliantPatients) / managedPatients.size();
    return complianceRate >= 0.75;
}

int PatientManagementService::getActivePatientCount() const {
    return managedPatients.size();
}

void PatientManagementService::addManagedPatient(Patient* patient) {
    if (patient) {
        managedPatients.push_back(patient);
    }
}

void PatientManagementService::removeManagedPatient(const std::string& patientId) {
    managedPatients.erase(
        std::remove_if(managedPatients.begin(), managedPatients.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        managedPatients.end()
    );
}

std::vector<Patient*> PatientManagementService::getManagedPatients() const {
    return managedPatients;
}
