#include "AnalyticsService.h"
#include "Hospital.h"
#include "Patient.h"
#include "MedicalDepartment.h"
#include "MedicalRecord.h"
#include <algorithm>
#include <cmath>
#include <numeric>

AnalyticsService::AnalyticsService(const std::string& serviceId)
    : serviceId(serviceId) {}

double AnalyticsService::calculateHospitalEfficiencyScore(const Hospital* hospital) const {
    if (!hospital) return 0.0;
    
    double baseScore = 65.0;
    
    double bedUtilizationScore = hospital->calculateBedOccupancyRate() * 0.3;
    double resourceUtilizationScore = hospital->calculateResourceUtilization() * 0.25;
    double patientSatisfactionScore = hospital->calculatePatientSatisfactionScore() * 0.2;
    
    double departmentEfficiency = 0.0;
    auto departments = hospital->getDepartments();
    if (!departments.empty()) {
        double totalEfficiency = 0.0;
        for (const auto& dept : departments) {
            totalEfficiency += dept->calculateEfficiencyScore();
        }
        departmentEfficiency = (totalEfficiency / departments.size()) * 0.25;
    }
    
    double totalScore = baseScore + bedUtilizationScore + resourceUtilizationScore + 
                       patientSatisfactionScore + departmentEfficiency;
    return std::min(totalScore, 100.0);
}

double AnalyticsService::predictPatientOutcomeProbability(const Patient* patient) const {
    if (!patient) return 0.0;
    
    double baseProbability = 70.0;
    
    double healthRiskFactor = (100.0 - patient->calculateHealthRiskScore()) * 0.4;
    double ageFactor = patient->getAge() < 60 ? 15.0 : 8.0;
    double bmiFactor = patient->calculateBMI() > 18.5 && patient->calculateBMI() < 25.0 ? 10.0 : 3.0;
    
    double treatmentPlanFactor = patient->getTreatmentPlan() ? 12.0 : 5.0;
    double medicalHistoryFactor = patient->getMedicalHistory().size() > 5 ? -8.0 : 5.0;
    
    double totalProbability = baseProbability + healthRiskFactor + ageFactor + bmiFactor + 
                             treatmentPlanFactor + medicalHistoryFactor;
    return std::max(0.0, std::min(totalProbability, 100.0));
}

double AnalyticsService::analyzeResourceUtilizationTrend() const {
    if (monitoredHospitals.empty()) return 0.0;
    
    double totalUtilization = 0.0;
    for (const auto& hospital : monitoredHospitals) {
        totalUtilization += hospital->calculateResourceUtilization();
    }
    
    double avgUtilization = totalUtilization / monitoredHospitals.size();
    
    double patientLoadFactor = 0.0;
    for (const auto& patient : patientPopulation) {
        if (patient->calculateHealthRiskScore() > 50.0) {
            patientLoadFactor += 2.0;
        }
    }
    
    double trendScore = avgUtilization * 0.7 + (patientLoadFactor / patientPopulation.size()) * 30.0;
    return std::min(trendScore, 100.0);
}

std::map<std::string, double> AnalyticsService::generatePerformanceReport() const {
    std::map<std::string, double> report;
    
    double totalEfficiency = 0.0;
    for (const auto& hospital : monitoredHospitals) {
        totalEfficiency += calculateHospitalEfficiencyScore(hospital);
    }
    report["Average Hospital Efficiency"] = monitoredHospitals.empty() ? 0.0 : totalEfficiency / monitoredHospitals.size();
    
    double totalPatientOutcomes = 0.0;
    for (const auto& patient : patientPopulation) {
        totalPatientOutcomes += predictPatientOutcomeProbability(patient);
    }
    report["Average Patient Outcome Probability"] = patientPopulation.empty() ? 0.0 : totalPatientOutcomes / patientPopulation.size();
    
    report["Resource Utilization Trend"] = analyzeResourceUtilizationTrend();
    
    double readmissionRisk = 0.0;
    for (const auto& patient : patientPopulation) {
        readmissionRisk += calculateReadmissionRisk(patient);
    }
    report["Average Readmission Risk"] = patientPopulation.empty() ? 0.0 : readmissionRisk / patientPopulation.size();
    
    report["Bottleneck Identification Score"] = identifyBottlenecks() ? 85.0 : 45.0;
    
    return report;
}

bool AnalyticsService::identifyBottlenecks() const {
    if (monitoredHospitals.empty()) return false;
    
    int highUtilizationHospitals = 0;
    for (const auto& hospital : monitoredHospitals) {
        if (hospital->calculateResourceUtilization() > 85.0) {
            highUtilizationHospitals++;
        }
    }
    
    double highUtilizationRatio = static_cast<double>(highUtilizationHospitals) / monitoredHospitals.size();
    
    int highRiskPatients = 0;
    for (const auto& patient : patientPopulation) {
        if (patient->calculateHealthRiskScore() > 70.0) {
            highRiskPatients++;
        }
    }
    
    double highRiskRatio = patientPopulation.empty() ? 0.0 : static_cast<double>(highRiskPatients) / patientPopulation.size();
    
    return highUtilizationRatio > 0.6 || highRiskRatio > 0.4;
}

double AnalyticsService::calculateReadmissionRisk(const Patient* patient) const {
    if (!patient) return 0.0;
    
    double baseRisk = 15.0;
    
    double healthRiskFactor = patient->calculateHealthRiskScore() * 0.5;
    double ageRiskFactor = patient->getAge() > 65 ? 20.0 : 10.0;
    double chronicConditionRisk = patient->needsRegularCheckup() ? 15.0 : 5.0;
    
    double treatmentComplexityRisk = 0.0;
    auto medicalHistory = patient->getMedicalHistory();
    for (const auto& record : medicalHistory) {
        treatmentComplexityRisk += record->calculateTreatmentComplexity() * 0.1;
    }
    
    double totalRisk = baseRisk + healthRiskFactor + ageRiskFactor + chronicConditionRisk + treatmentComplexityRisk;
    return std::min(totalRisk, 100.0);
}

void AnalyticsService::addMonitoredHospital(Hospital* hospital) {
    if (hospital) {
        monitoredHospitals.push_back(hospital);
    }
}

void AnalyticsService::removeMonitoredHospital(const std::string& hospitalId) {
    monitoredHospitals.erase(
        std::remove_if(monitoredHospitals.begin(), monitoredHospitals.end(),
            [&hospitalId](Hospital* hospital) {
                return hospital->getName() == hospitalId;
            }),
        monitoredHospitals.end()
    );
}

std::vector<Hospital*> AnalyticsService::getMonitoredHospitals() const {
    return monitoredHospitals;
}

void AnalyticsService::addPatientToPopulation(Patient* patient) {
    if (patient) {
        patientPopulation.push_back(patient);
    }
}

void AnalyticsService::removePatientFromPopulation(const std::string& patientId) {
    patientPopulation.erase(
        std::remove_if(patientPopulation.begin(), patientPopulation.end(),
            [&patientId](Patient* patient) {
                return patient->getId() == patientId;
            }),
        patientPopulation.end()
    );
}

std::vector<Patient*> AnalyticsService::getPatientPopulation() const {
    return patientPopulation;
}
