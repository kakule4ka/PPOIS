#include "Supplier.h"
#include "BuildingMaterial.h"
#include "ConstructionProject.h"
#include <algorithm>

Supplier::Supplier(const std::string& id, const std::string& name, const std::string& material, double reliability)
    : id(id), name(name), material(material), reliability(reliability) {}

double Supplier::calculateDeliveryRisk() const {
    return (1.0 - reliability) * 100.0;
}

bool Supplier::canHandleUrgentOrder() const {
    return reliability > 0.8 && material != "Concrete";
}

double Supplier::calculateSupplierRating() const {
    double baseRating = reliability * 80.0;
    
    double materialBonus = suppliedMaterials.size() * 2.0;
    double projectBonus = servedProjects.size() * 3.0;
    double reliabilityBonus = reliability * 20.0;
    
    double totalRating = baseRating + materialBonus + projectBonus + reliabilityBonus;
    
    double urgencyPenalty = canHandleUrgentOrder() ? 0 : -10.0;
    double riskPenalty = calculateDeliveryRisk() * 0.5;
    
    return totalRating + urgencyPenalty - riskPenalty;
}

bool Supplier::isPreferredSupplier() const {
    double rating = calculateSupplierRating();
    bool hasGoodRating = rating > 85.0;
    bool hasMultipleMaterials = suppliedMaterials.size() >= 2;
    bool hasProjectExperience = servedProjects.size() >= 1;
    bool isReliable = reliability > 0.85;
    
    return hasGoodRating && hasMultipleMaterials && hasProjectExperience && isReliable;
}

void Supplier::addSuppliedMaterial(BuildingMaterial* material) {
    if (material) {
        suppliedMaterials.push_back(material);
    }
}

void Supplier::removeSuppliedMaterial(const std::string& materialId) {
    suppliedMaterials.erase(
        std::remove_if(suppliedMaterials.begin(), suppliedMaterials.end(),
            [&materialId](BuildingMaterial* material) {
                return material->getId() == materialId;
            }),
        suppliedMaterials.end()
    );
}

std::vector<BuildingMaterial*> Supplier::getSuppliedMaterials() const {
    return suppliedMaterials;
}

void Supplier::addServedProject(ConstructionProject* project) {
    if (project) {
        servedProjects.push_back(project);
    }
}

void Supplier::removeServedProject(const std::string& projectId) {
    servedProjects.erase(
        std::remove_if(servedProjects.begin(), servedProjects.end(),
            [&projectId](ConstructionProject* project) {
                return project->getId() == projectId;
            }),
        servedProjects.end()
    );
}

std::vector<ConstructionProject*> Supplier::getServedProjects() const {
    return servedProjects;
}
