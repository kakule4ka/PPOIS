#ifndef ARCHITECT_H
#define ARCHITECT_H

#include "models/Employee.h"
#include <vector>

class Blueprint;
class ConstructionProject;
class QualityStandard;

class Architect : public Employee {
private:
    int completedDesigns;
    std::string specialty;
    std::vector<Blueprint*> createdBlueprints;
    ConstructionProject* currentProject;
    QualityStandard* designStandard;
    
public:
    Architect(const std::string& id, const std::string& name, double salary, int designs, const std::string& specialty);
    
    double calculateDesignComplexity() const;
    bool validateCodeCompliance(const std::string& code) const;
    double calculateDesignEfficiency() const;
    bool canTakeNewProject() const;
    
    void addBlueprint(Blueprint* blueprint);
    void removeBlueprint(const std::string& blueprintId);
    std::vector<Blueprint*> getCreatedBlueprints() const;
    
    void setCurrentProject(ConstructionProject* project);
    ConstructionProject* getCurrentProject() const;
    
    void setDesignStandard(QualityStandard* standard);
    QualityStandard* getDesignStandard() const;
};

#endif
