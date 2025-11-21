#ifndef ANALYTICSSERVICE_H
#define ANALYTICSSERVICE_H

#include <string>
#include <vector>
#include <map>

class Hospital;
class Patient;

class AnalyticsService {
private:
    std::string serviceId;
    std::vector<Hospital*> monitoredHospitals;
    std::vector<Patient*> patientPopulation;

public:
    AnalyticsService(const std::string& serviceId);
    
    double calculateHospitalEfficiencyScore(const Hospital* hospital) const;
    double predictPatientOutcomeProbability(const Patient* patient) const;
    double analyzeResourceUtilizationTrend() const;
    std::map<std::string, double> generatePerformanceReport() const;
    bool identifyBottlenecks() const;
    double calculateReadmissionRisk(const Patient* patient) const;
    
    void addMonitoredHospital(Hospital* hospital);
    void removeMonitoredHospital(const std::string& hospitalId);
    std::vector<Hospital*> getMonitoredHospitals() const;
    
    void addPatientToPopulation(Patient* patient);
    void removePatientFromPopulation(const std::string& patientId);
    std::vector<Patient*> getPatientPopulation() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
