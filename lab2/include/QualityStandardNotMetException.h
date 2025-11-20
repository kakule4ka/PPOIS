#ifndef QUALITYSTANDARDNOTMETEXCEPTION_H
#define QUALITYSTANDARDNOTMETEXCEPTION_H

#include <stdexcept>
#include <string>

class QualityStandardNotMetException : public std::runtime_error {
private:
    std::string standardName;
    double actualValue;
    
public:
    QualityStandardNotMetException(const std::string& standard, double value);
    std::string getStandardName() const;
    double getActualValue() const;
};

#endif
