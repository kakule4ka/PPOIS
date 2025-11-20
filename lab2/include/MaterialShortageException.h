#ifndef MATERIALSHORTAGEEXCEPTION_H
#define MATERIALSHORTAGEEXCEPTION_H

#include <stdexcept>
#include <string>

class MaterialShortageException : public std::runtime_error {
private:
    std::string materialName;
    double shortageAmount;
    
public:
    MaterialShortageException(const std::string& material, double shortage);
    std::string getMaterialName() const;
    double getShortageAmount() const;
};

#endif
