#ifndef CONSTRUCTIONPROJECT_H
#define CONSTRUCTIONPROJECT_H

#include <string>

class ConstructionProject {
private:
    std::string id;
    std::string name;
    double budget;
    int duration;
    
public:
    ConstructionProject(const std::string& id, const std::string& name, double budget, int duration);
    
    double calculateMonthlyCost() const;
    bool isOnSchedule(int elapsedMonths, double spent) const;
    
    std::string getId() const { return id; }
};

#endif
