#ifndef CONSTRUCTIONSITE_H
#define CONSTRUCTIONSITE_H

#include <string>
#include <vector>

class ConstructionProject;
class SafetyProtocol;

class ConstructionSite {
private:
    std::string id;
    std::string location;
    double size;
    int maxWorkers;
    ConstructionProject* project;
    std::vector<SafetyProtocol*> activeSafetyProtocols;
    
public:
    ConstructionSite(const std::string& id, const std::string& location, double size, int maxWorkers);
    
    bool validateWorkerCapacity(int workers) const;
    double calculatePreparationTime() const;
    double calculateSiteSafetyScore() const;
    bool isSiteReady() const;
    
    void setProject(ConstructionProject* project);
    ConstructionProject* getProject() const;
    
    void addSafetyProtocol(SafetyProtocol* protocol);
    void removeSafetyProtocol(const std::string& protocolId);
    std::vector<SafetyProtocol*> getActiveSafetyProtocols() const;
    
    std::string getId() const { return id; }
};

#endif
