#ifndef DOCUMENTMANAGEMENTSERVICE_H
#define DOCUMENTMANAGEMENTSERVICE_H

#include <string>
#include <vector>

class ConstructionProject;
class Blueprint;

class DocumentManagementService {
private:
    std::string serviceId;
    int documentsManaged;
    double retrievalEfficiency;
    std::vector<ConstructionProject*> projectDocuments;
    std::vector<Blueprint*> managedBlueprints;
    
public:
    DocumentManagementService(const std::string& id, int documents, double efficiency);
    
    double calculateDocumentAccuracy() const;
    bool automateDocumentWorkflow() const;
    double calculateServicePerformance() const;
    bool needsSystemUpgrade() const;
    
    void addProjectDocument(ConstructionProject* project);
    void removeProjectDocument(const std::string& projectId);
    std::vector<ConstructionProject*> getProjectDocuments() const;
    
    void addManagedBlueprint(Blueprint* blueprint);
    void removeManagedBlueprint(const std::string& blueprintId);
    std::vector<Blueprint*> getManagedBlueprints() const;
    
    std::string getId() const { return serviceId; }
};

#endif
