#ifndef CONSTRUCTIONCOMPANY_H
#define CONSTRUCTIONCOMPANY_H

#include <string>

class ConstructionCompany {
private:
    std::string name;
    std::string license;
    int foundedYear;
    
public:
    ConstructionCompany(const std::string& name, const std::string& license, int year);
    
    double calculateMaxProjectCapacity() const;
    bool verifyLicense() const;
    
    std::string getName() const { return name; }
};

#endif
