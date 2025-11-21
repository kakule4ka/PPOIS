#ifndef INVALIDBLUEPRINTEXCEPTION_H
#define INVALIDBLUEPRINTEXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidBlueprintException : public std::runtime_error {
private:
    std::string blueprintId;
    
public:
    InvalidBlueprintException(const std::string& blueprint);
    std::string getBlueprintId() const;
};

#endif
