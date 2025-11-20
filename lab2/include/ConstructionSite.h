#ifndef CONSTRUCTIONSITE_H
#define CONSTRUCTIONSITE_H

#include <string>

class ConstructionSite {
private:
    std::string id;
    std::string location;
    double size;
    int maxWorkers;
    
public:
    ConstructionSite(const std::string& id, const std::string& location, double size, int maxWorkers);
    
    bool validateWorkerCapacity(int workers) const;
    double calculatePreparationTime() const;
    
    std::string getId() const { return id; }
};

#endif
