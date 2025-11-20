#ifndef RESOURCEALLOCATIONEXCEPTION_H
#define RESOURCEALLOCATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class ResourceAllocationException : public std::runtime_error {
private:
    std::string resourceType;
    
public:
    ResourceAllocationException(const std::string& resource);
    std::string getResourceType() const;
};

#endif
