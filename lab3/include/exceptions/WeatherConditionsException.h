#ifndef WEATHERCONDITIONSEXCEPTION_H
#define WEATHERCONDITIONSEXCEPTION_H

#include <stdexcept>
#include <string>

class WeatherConditionsException : public std::runtime_error {
private:
    std::string weatherCondition;
    
public:
    WeatherConditionsException(const std::string& condition);
    std::string getWeatherCondition() const;
};

#endif
