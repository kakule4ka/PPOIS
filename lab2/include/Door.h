#ifndef DOOR_H
#define DOOR_H

#include <string>

class Door {
private:
    std::string doorId;
    std::string type;
    std::string material;
    double width;
    
public:
    Door(const std::string& id, const std::string& type, const std::string& material, double width);
    
    double calculateSecurityLevel() const;
    bool validateAccessibility() const;
    
    std::string getId() const { return doorId; }
};

#endif
