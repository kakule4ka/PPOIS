#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window {
private:
    std::string windowId;
    std::string material;
    double width;
    double height;
    
public:
    Window(const std::string& id, const std::string& material, double width, double height);
    
    double calculateHeatLoss() const;
    bool meetsVentilationRequirements() const;
    
    std::string getId() const { return windowId; }
};

#endif
