#include "models/Architect.h"
#include "models/Blueprint.h"
#include "core/ConstructionProject.h"
#include "core/QualityStandard.h"
#include <algorithm>

Architect::Architect(const std::string& id, const std::string& name, double salary, int designs, const std::string& specialty)
    : Employee(id, name, "Architect", salary), completedDesigns(designs), specialty(specialty),
      currentProject(nullptr), designStandard(nullptr) {}

double Architect::calculateDesignComplexity() const {
    double baseComplexity = completedDesigns * 0.5;
    double specialtyMultiplier = 1.0;
    
    if (specialty == "High-rise") specialtyMultiplier = 1.8;
    else if (specialty == "Commercial") specialtyMultiplier = 1.5;
    else if (specialty == "Industrial") specialtyMultiplier = 1.6;
    
    double projectComplexity = currentProject ? currentProject->getDuration() * 0.1 : 0.0;
    double standardComplexity = designStandard ? designStandard->getThreshold() * 0.01 : 0.0;
    
    return baseComplexity * specialtyMultiplier + projectComplexity + standardComplexity;
}

bool Architect::validateCodeCompliance(const std::string& code) const {
    bool hasStandard = designStandard != nullptr;
    bool hasExperience = completedDesigns > 5;
    bool codeLengthValid = code.length() >= 5;
    
    return hasStandard && hasExperience && codeLengthValid;
}

double Architect::calculateDesignEfficiency() const {
    double baseEfficiency = 70.0;
    double blueprintEfficiency = createdBlueprints.size() * 2.0;
    double projectEfficiency = currentProject ? 10.0 : 0.0;
    double standardEfficiency = designStandard ? 5.0 : 0.0;
    
    return baseEfficiency + blueprintEfficiency + projectEfficiency + standardEfficiency;
}

bool Architect::canTakeNewProject() const {
    return currentProject == nullptr && createdBlueprints.size() < 10;
}

void Architect::addBlueprint(Blueprint* blueprint) {
    if (blueprint) {
        createdBlueprints.push_back(blueprint);
    }
}

void Architect::removeBlueprint(const std::string& blueprintId) {
    createdBlueprints.erase(
        std::remove_if(createdBlueprints.begin(), createdBlueprints.end(),
            [&blueprintId](Blueprint* blueprint) {
                return blueprint->getId() == blueprintId;
            }),
        createdBlueprints.end()
    );
}

std::vector<Blueprint*> Architect::getCreatedBlueprints() const {
    return createdBlueprints;
}

void Architect::setCurrentProject(ConstructionProject* project) {
    this->currentProject = project;
}

ConstructionProject* Architect::getCurrentProject() const {
    return currentProject;
}

void Architect::setDesignStandard(QualityStandard* standard) {
    this->designStandard = standard;
}

QualityStandard* Architect::getDesignStandard() const {
    return designStandard;
}
