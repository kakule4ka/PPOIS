#ifndef PROJECTMANAGEMENTSERVICE_H
#define PROJECTMANAGEMENTSERVICE_H

#include <string>

class ProjectManagementService {
private:
    std::string serviceId;
    int managedProjects;
    double successRate;
    
public:
    ProjectManagementService(const std::string& id, int projects, double rate);
    
    double calculateResourceEfficiency() const;
    bool canTakeNewProject() const;
    
    std::string getId() const { return serviceId; }
};

#endif
