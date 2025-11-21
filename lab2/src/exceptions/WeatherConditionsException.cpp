#include "WeatherConditionsException.h"

WeatherConditionsException::WeatherConditionsException(const std::string& condition)
    : std::runtime_error("Weather conditions exception: " + condition),
      weatherCondition(condition) {}

std::string WeatherConditionsException::getWeatherCondition() const {
    return weatherCondition;
}
