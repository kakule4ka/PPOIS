#ifndef DOCTORSCHEDULINGSERVICE_H
#define DOCTORSCHEDULINGSERVICE_H

#include <string>
#include <vector>

class Doctor;

class DoctorSchedulingService {
private:
    std::string serviceId;
    std::vector<Doctor*> managedDoctors;

public:
    DoctorSchedulingService(const std::string& serviceId);
    
    double calculateScheduleEfficiency() const;
    bool assignEmergencyCoverage() const;
    bool validateWorkloadDistribution() const;
    
    void addManagedDoctor(Doctor* doctor);
    void removeManagedDoctor(const std::string& doctorId);
    std::vector<Doctor*> getManagedDoctors() const;
    
    std::string getServiceId() const { return serviceId; }
};

#endif
